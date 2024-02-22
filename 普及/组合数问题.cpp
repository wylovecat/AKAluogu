#include <bits/stdc++.h>
using namespace std;
const int N=5e6+5;
const int M=998244353;
typedef long long ll;
ll jc[N];
ll fastpow(ll x,int n){
	ll ans=1;
	while(n){
		if(n&1) ans=ans*x%M;
		x=x*x%M;
		n>>=1;
	}
	return ans;
}
ll C(int n,int m){
	return jc[n]*fastpow(jc[m]*jc[n-m]%M,M-2)%M;
}
int main()
{
	int t,n,m;
	jc[0]=1;
	int ans=0;
	cin>>t>>n;
	for(int i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%M;
	}
	while(t--){
		scanf("%d%d",&n,&m);
		ans^=C(n,m);
	}
	cout<<ans;
	return 0;
}
