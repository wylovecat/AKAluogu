#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10005;
int n;
struct node {
    int y, L, R;
}wood[N];
bool cmp(node A, node B)
{
    return A.y < B.y;
}
int a[N], w[N << 2], lzy[N << 2];
void pushup(int u)
{
    w[u] = max(w[2 * u], w[2 * u + 1]);
}
void build(int u, int L, int R)
{
    if (L == R) {
        w[u] = a[L];
        return;
    }
    int mid = (L + R) / 2;
    build(2 * u, L, mid);
    build(2 * u + 1, mid + 1, R);
    pushup(u);
}
bool inRange(int L, int R, int l, int r)
{
    return l <= L && R <= r;
}
bool outofRange(int L, int R, int l, int r)
{
    return r < L || R < l;
}
void maketag(int u, int L, int R, int val)
{
    lzy[u] = max(lzy[u], val);
    w[u] = max(w[u], val);
}
void pushdown(int u, int L, int R)
{
    int mid = (L + R) / 2;
    maketag(2 * u, L, mid, lzy[u]);
    maketag(2 * u + 1, mid + 1, R, lzy[u]);
    lzy[u] = 0;
}
int query(int u, int L, int R, int l, int r)
{
    if (inRange(L, R, l, r)) {
        return w[u];
    }
    else if (!outofRange(L, R, l, r)) {
        pushdown(u, L, R);
        int mid = (L + R) / 2;
        return max(query(2 * u, L, mid, l, r), query(2 * u + 1, mid + 1, R, l, r));
    }
    else {
        return 0;
    }
}
void update(int u, int L, int R, int l, int r, int val)
{
    if (inRange(L, R, l, r)) {
        maketag(u, L, R, val);
    }
    else if (!outofRange(L, R, l, r)) {
        pushdown(u, L, R);
        int mid = (L + R) / 2;
        update(2 * u, L, mid, l, r, val);
        update(2 * u + 1, mid + 1, R, l, r, val);
        pushup(u);
    }
}
void show()
{
    for (int i = 1;i <= n;i++) {
        cout << query(1, 1, n, i, i) << " ";
    }
    cout << endl;
}
int main()
{
    int sum = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> wood[i].y >> wood[i].L >> wood[i].R;
    }
    sort(wood + 1, wood + n + 1, cmp);
    for (int i = 1;i <= n;i++) {
        int L = wood[i].L, R = wood[i].R;
        int H = wood[i].y;
        int LH = H - query(1, 1, N-5, L, L);
        int RH = H - query(1, 1, N-5, R - 1, R - 1);
        sum += LH;
        sum += RH;
     //   printf("%d : %d %d\n", i, LH, RH);
        update(1, 1, N-5, L, R - 1, H);
    }
    cout << sum;
    return 0;
}