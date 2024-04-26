#include <iostream>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll c[N];
int n,w,a,b;

int lowbit(int x)
{
    return x&-x;
}
ll getSum(int x)
{
    ll sum=0;
    for(int i=x;i;i-=lowbit(i))
    {
        sum+=c[i];
    }
    return sum;
}
void update(int x,ll y)
{
    for(int i=x;i<=n;i+=lowbit(i))
    {
        c[i]+=y;
    }
}
int main()
{
    int L,R;
    char op;
    cin>>n>>w;
    for(int i=1;i<=w;i++){
        cin>>op>>L>>R;
        if(op=='x'){
            update(L,R);
        }
        else{
            cout<<getSum(R)-getSum(L-1)<<endl;
        }
    }
    return 0;
}