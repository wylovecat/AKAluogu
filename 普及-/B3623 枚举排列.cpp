#include <bits/stdc++.h>
using namespace std;
int rk[15];
bool vis[15];
int n,k;
void dfs(int d){
	if(d==k){
		for(int i=1;i<=k;i++){
			printf("%d ",rk[i]);
		}
		printf("\n");
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		rk[d+1]=i;
		dfs(d+1);
		vis[i]=0;
	}
}
int main()
{
	cin>>n>>k;
	dfs(0);
	return 0;
}
