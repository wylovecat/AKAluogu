#include <bits/stdc++.h>
using namespace std;
const int N=3005;
int h[N][N];
bool vis[N][N];
int ans[N][N];
int n,m,k;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
bool hei[9000005];
vector<int> dot[2];
struct node{
	int x,y;
}yj[9000005];
void bfs(int sx,int sy){
	queue<node> q;
	memset(ans,0x3f,sizeof(ans));
	memset(vis,0,sizeof(vis));
	q.push(node{sx,sy});
	ans[sx][sy]=0;
	vis[sx][sy]=1;
	while(!q.empty()){
		node cur=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=cur.x+dx[i];
			int ny=cur.y+dy[i];
			if(nx<1||nx>n||ny<1||ny>m) continue;
			if(vis[nx][ny] || !h[nx][ny]) continue;
			vis[nx][ny]=1;
			ans[nx][ny]=ans[cur.x][cur.y]+1;
			q.push(node{nx,ny});
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&h[i][j]);
		}
	}
	for(int i=1;i<=k;i++){
		scanf("%d%d",&yj[i].x,&yj[i].y);
	}
	bfs(1,1);
	int ans1=1e9,ans2=1e9;
	for(int i=1;i<=k;i++){
		if(ans[yj[i].x][yj[i].y]<ans1){
			ans1=ans[yj[i].x][yj[i].y];	
		}
	}
	for(int i=1;i<=k;i++){
		if(ans[yj[i].x][yj[i].y]==ans1){
			hei[h[yj[i].x][yj[i].y]]=1;	
			dot[0].push_back(i);
		}
	}
	
	bfs(n,m);
	for(int i=1;i<=k;i++){
		if(ans[yj[i].x][yj[i].y]<ans2){
			ans2=ans[yj[i].x][yj[i].y];	
		}
	}
	for(int i=1;i<=k;i++){
		if(ans[yj[i].x][yj[i].y]==ans2){
			dot[1].push_back(i);
		}
	}
	int t=ans[1][1];
	for(int i=0;i<dot[0].size();i++){
		for(int j=0;j<dot[1].size();j++){
			int n1=dot[0][i],n2=dot[1][j];
			if(h[yj[n1].x][yj[n1].y]==h[yj[n2].x][yj[n2].y]){
				t=min(t,ans1+ans2+1);
			}else{
				t=min(t,ans1+ans2+2);
			}
		}
	}
	if(t==0x3f3f3f3f) cout<<-1;
	else cout<<t;
	return 0;
}
