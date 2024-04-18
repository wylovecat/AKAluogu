#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll a[N], b[N],w[N << 2], lzy[N << 2];
int n, m;
void pushup(int u)
{
    w[u] = w[2 * u] + w[2 * u + 1];
}
void build(int u, int L, int R)
{
    if (L == R) {
        w[u] = b[L];
        return;
    }
    int mid = (L + R) / 2;
    build(2 * u, L, mid);
    build(2 * u + 1, mid + 1, R);
    pushup(u);
}
void maketag(int u, int L, int R, ll val)
{
    lzy[u] += val;
    w[u] += (R - L + 1) * val;
}
void pushdown(int u, int L, int R)
{
    int mid = (L + R) / 2;
    maketag(2 * u, L, mid, lzy[u]);
    maketag(2 * u + 1, mid + 1, R, lzy[u]);
    lzy[u] = 0;
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
        pushdown(u, L, R);
        int mid = (L + R) / 2;
        return query(2 * u, L, mid, l, r) + query(2 * u + 1, mid + 1, R, l, r);
    }
    else {
        return 0;
    }
}
void update(int u, int L, int R, int l, int r, ll val)
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
    int op, l, r, k, d, p;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i]=a[i]-a[i-1];
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        cin>>op;
        if(op==1){
            cin>>l>>r>>k>>d;
            update(1,1,n,l,l,k);
            update(1,1,n,l+1,r,d);
            update(1,1,n,r+1,r+1,-(k+d*(r-l)));
        }else{
            cin>>p;
            cout<<query(1,1,n,1,p)<<endl;
        }
    }

    return 0;
}