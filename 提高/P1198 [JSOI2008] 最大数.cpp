#include <iostream>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
ll a[N], w[N << 2];
int m, d;
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
ll query(int u, int L, int R, int l, int r)
{
    if (inRange(L, R, l, r)) {
        return w[u];
    }
    else if (!outofRange(L, R, l, r)) {
        int mid = (L + R) / 2;
        return max(query(2 * u, L, mid, l, r), query(2 * u + 1, mid + 1, R, l, r));
    }
    else {
        return 0;
    }
}
void update(int u, int L, int R, int x, ll y)
{
    if (L > R) return;
    int mid = (L + R) / 2;
    if (L == R) {
        w[u] += y;
        return;
    }
    if (x <= mid)
        update(2 * u, L, mid, x, y);
    else
        update(2 * u + 1, mid + 1, R, x, y);
    pushup(u);
}
int main()
{
    int n = 0;
    ll t = 0;
    int x;
    char c;
    build(1, 1, N - 5);
    cin >> m >> d;
    for (int i = 1;i <= m;i++) {
        cin >> c >> x;
        if (c == 'Q') {
            t = query(1, 1, N - 5, n - x + 1, n);
            cout << t << endl;
        }
        else {
            update(1, 1, N - 5, n + 1, ((x + t) % d + d) % d);
            n++;
        }
    }
    return 0;
}