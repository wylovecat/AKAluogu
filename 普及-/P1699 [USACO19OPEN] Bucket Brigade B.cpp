#include <bits/stdc++.h>
using namespace std;
char a[15][15];
int ans[15][15];
bool vis[15][15];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
struct node{
	int x,y;
};
void bfs(int sx,int sy){
	queue<node> q;
	vis[sx][sy]=1;
	ans[sx][sy]=0;
	q.push(node{sx,sy});
	while(!q.empty()){
		node cur=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=cur.x+dx[i];
			int ny=cur.y+dy[i];
			if(nx<1||nx>10||ny<1||ny>10){
				continue;
			}
			if(vis[nx][ny] || a[nx][ny]=='R') continue;
			vis[nx][ny]=1;
			ans[nx][ny]=ans[cur.x][cur.y]+1;
			q.push(node{nx,ny});
		}
	}
}
int main()
{
	int sx,sy,ex,ey;
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			cin>>a[i][j];
			if(a[i][j]=='L'){
				sx=i;sy=j;
			}else if(a[i][j]=='B'){
				ex=i;ey=j;
			}
		}
	}
	bfs(sx,sy);
	cout<<ans[ex][ey]-1;
	
	return 0;
}
