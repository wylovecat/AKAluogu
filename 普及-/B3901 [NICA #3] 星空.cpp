#include <bits/stdc++.h>
using namespace std;
const int N=65;
typedef long long ll;
const int M=1e9+7;
ll a[N];
ll jc[N];
int n;
ll x;
int main()
{
	cin>>n>>x;
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%M;
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int m=0;
	for(int i=1;i<n;i++){
		if(a[i]+a[n]<=x){
			m++;
		}
	}
	ll ans=0;
	if(m>=1) ans=jc[n-2]*m*2%M;
	if(m>=2) ans=(ans+jc[n-3]*m*(m-1)*(n-2))%M;
	cout<<ans;
	return 0;
}
