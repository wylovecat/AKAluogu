#include <bits/stdc++.h>
using namespace std;
int rk[10];
int n,k;
void dfs(int d){
	if(d==n){
		for(int i=1;i<=n;i++){
			printf("%d ",rk[i]);
		}
		printf("\n");
		return ;
	}
	for(int i=1;i<=k;i++){
		rk[d+1]=i;
		dfs(d+1);
	}
}
int main()
{
	cin>>n>>k;
	dfs(0);
	return 0;
}
