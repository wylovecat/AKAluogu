#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int a[N], w[N << 2], lzy[N << 2];
int n, m;
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
    if (val & 1)
        w[u] = (R - L + 1) - w[u];
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
        pushdown(u, L, R);
        int mid = (L + R) / 2;
        update(2 * u, L, mid, l, r, val);
        update(2 * u + 1, mid + 1, R, l, r, val);
        pushup(u);
    }
}
int main()
{
    int a, b, c;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        cin >> c >> a >> b;
        if (c==1) {
            cout << query(1, 1, n, a, b) << endl;
        }
        else {
            update(1, 1, n, a, b, 1);
        }
    }
    return 0;
}