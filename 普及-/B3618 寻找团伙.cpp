#include <bits/stdc++.h>
using namespace std;
const int N=25;
typedef long long ll;
ll sc[N][65];
int main()
{
	int n,k,m,x;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>m;
		for(int j=1;j<=m;j++){
			cin>>x;
			sc[i][x]=(1LL<<(k-x));
		}
	}
	int all=(1<<n)-1;
	ll ans=0;
	for(int i=1;i<=all;i++){
		ll vis[65]={0};
		for(int j=n-1;j>=0;j--){
			if((i>>j)&1){
				for(int l=1;l<=k;l++){
					vis[l]^=sc[j][l];
				}
			}
		}
		ll sum=0;
		for(int j=1;j<=k;j++){
			sum+=vis[j];
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
