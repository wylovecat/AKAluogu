#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
//边差分
const int N = 2e5 + 5;
int n;
ll c[N][2];
ll cnt[N];
int fa[N][20];
int dep[N];
int b[N];
int idx[N];//idx[i] i->fa[i][0] 的边的编号
struct node {
    int v, id;
};
vector<node> G[N];
int lowbit(int x)
{
    return x & -x;
}
void dfs(int u, int f)
{
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (auto e : G[u]) {
        int v = e.v, id = e.id;
        if (v == f) {
            continue;
        }
        //u--->v 
        idx[v] = id;
        dfs(v, u);
    }
}
int LCA(int x, int y)
{
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = dep[x] - dep[y];i;i -= lowbit(i)) {
        int low = log2(lowbit(i));
        x = fa[x][low];
    }
    if (x == y) return x;
    for (int i = log2(n);i >= 0;i--) {
        if (fa[x][i] == fa[y][i]) continue;
        x = fa[x][i];
        y = fa[y][i];
    }
    return fa[x][0];
}
void dfs2(int u, int f)
{
    //cnt[idx[u]]=cnt[idx[f]]+b[idx[u]];
    cnt[idx[u]] = b[idx[u]];
    for (auto e : G[u]) {
        int v = e.v;
        if (v == f) continue;
        dfs2(v, u);
        cnt[idx[u]] += cnt[idx[v]];
    }
}
int main()
{
    int u, v;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> c[i][0] >> c[i][1];
        G[u].push_back(node{ v,i });
        G[v].push_back(node{ u,i });
    }
    dfs(1, 0);
    for (int j = 1;j <= log2(n);j++) {
        for (int i = 1;i <= n;i++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }
    int L = 1, R = 1;
    for (int i = 1;i <= n;i++) {
        L = R;R = i;
        int lca = LCA(L, R);
        b[idx[L]]++;b[idx[lca]]--;
        b[idx[R]]++;b[idx[lca]]--;
    }
    dfs2(1, 0);
    ll ans = 0;
    for (int i = 1;i < n;i++) {
        ans += min(cnt[i] * c[i][0], c[i][1]);
    }
    cout << ans;
    return 0;
}