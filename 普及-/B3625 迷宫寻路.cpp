#include <bits/stdc++.h>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
char a[105][105];
bool vis[105][105];
int n,m;
void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<1||nx>n||ny<1||ny>m) continue;
		if(vis[nx][ny] || a[nx][ny]=='#') continue;
		dfs(nx,ny);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	dfs(1,1);
	if(vis[n][m]) cout<<"Yes";
	else cout<<"No";
	return 0;
}
