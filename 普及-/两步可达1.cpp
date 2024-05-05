#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 505;
bool f[N][N];
int n,m;
bool vis[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int u,v,t;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		vis[u][v]=1;
	}
	//预处理
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=f[i][j]||(vis[i][k]&&vis[k][j]);
			}
		}
	}
	cin>>t;
	while(t--){
		cin>>u>>v;
		if(f[u][v]){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	return 0;
}
