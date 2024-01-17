#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
int n,x,y,p,q,k;
ll a[N],z[N],ans[N];
int main()
{
	cin>>n>>x>>y>>p;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		z[i]=a[i];
	}
	for(int i=1;i<=p;i++){
		for(int j=1;j<=n;j++){
			a[j]=(a[j]*x+y)%p;
			ans[i]+=(a[j]==z[j]);
		}
	}
	ans[0]=ans[p];
	
	cin>>q;
	while(q--){
		cin>>k;
		cout<<ans[k%p]<<endl;
	}
	return 0;
}
