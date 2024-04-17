#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, m;
int a[N], w[N << 2], lzy[N << 2];
void pushup(int u)
{
    w[u] = w[2 * u] + w[2 * u + 1];
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
    lzy[u] ^= val;
    if (val & 1) w[u] = (R - L + 1) - w[u];
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
        int mid = (L + R) / 2;
        pushdown(u, L, R);
        return query(2 * u, L, mid, l, r) + query(2 * u + 1, mid + 1, R, l, r);
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
        int mid = (L + R) / 2;
        pushdown(u, L, R);
        update(2 * u, L, mid, l, r, val);
        update(2 * u + 1, mid + 1, R, l, r, val);
        pushup(u);
    }
}
int main()
{
    int op, s, e;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        cin >> op >> s >> e;
        if (op == 0) {
            update(1, 1, n, s, e, 1);
        }
        else {
            cout << query(1, 1, n, s, e) << endl;
        }
    }

    return 0;
}