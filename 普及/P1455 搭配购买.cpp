#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int fa[N];
int cnt;
int w[N],v[N],a[N],b[N],idx[N];
int dp[N];
int findRt(int x){
	if(x==fa[x]) return x;
	return fa[x]=findRt(fa[x]);
}
void merge(int x,int y){
	int fx=findRt(x),fy=findRt(y);
	if(fx!=fy) fa[fx]=fy;
}
int main()
{
	int n,m,c;
	int x,y;
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		merge(x,y);
	}
	for(int i=1;i<=n;i++){
		if(findRt(i)==i){
			idx[fa[i]]=++cnt;	
		}
	}
	for(int i=1;i<=n;i++){
		v[idx[fa[i]]]+=a[i];
		w[idx[fa[i]]]+=b[i];
	}
	for(int i=1;i<=cnt;i++){
		for(int j=c;j>=v[i];j--){
			dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
		}
	}
	cout<<dp[c];
	return 0;
}
