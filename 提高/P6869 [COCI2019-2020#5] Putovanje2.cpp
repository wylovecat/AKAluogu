#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
//边差分
const int N = 2e5 + 5;
struct node {
    int v;
    ll c1, c2;
};
vector<node> G[N];
vector<pair<int, int>> Q[N];
int n;
ll c[N][2];
ll b[N], cnt[N];
int rt[N];
int ans[N];
bool vis[N];
int findRt(int x)
{
    if (x == rt[x]) return x;
    return rt[x] = findRt(rt[x]);
}
void tarjan(int u)
{
    vis[u] = 1;
    for (auto e : G[u]) {
        int v = e.v;
        ll c0 = e.c1, c1 = e.c2;
        if (!vis[v]) {
            c[v][0] = c0;
            c[v][1] = c1;
            tarjan(v);
            rt[v] = u;
        }
    }
    for (auto e : Q[u]) {
        int v = e.first, id = e.second;
        if (vis[v]) {
            ans[id] = findRt(v);
        }
    }
}
void dfs(int u, int f)
{
    cnt[u] = b[u];
    for (auto e : G[u]) {
        int v = e.v;
        if (v == f) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
}
int main()
{
    int u, v;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> c[i][0] >> c[i][1];
        G[u].push_back(node{ v,c[i][0],c[i][1] });
        G[v].push_back(node{ u,c[i][0],c[i][1] });
    }
    int L = 1, R = 1;
    for (int i = 1;i <= n;i++) {
        L = R;R = i;
        Q[L].push_back({ R,i });
        Q[R].push_back({ L,i });
    }
    for (int i = 1;i <= n;i++) {
        rt[i] = i;
    }
    tarjan(1);
    R = 1;
    for (int i = 1;i <= n;i++) {
        L = R;R = i;
        int lca = ans[i];
        b[L]++;b[lca]--;
        b[R]++;b[lca]--;
    }
    dfs(1, 1);
    ll sum = 0;
    for (int i = 2;i <= n;i++) {
        sum += min(cnt[i] * c[i][0], c[i][1]);
    }
    cout << sum;
    return 0;
}