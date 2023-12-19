#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
struct node{
	int v;
	ll w;
	friend bool operator <(const node &A,const node &B){
		return A.w>B.w;
	}
};
vector<node> G[2][N];
ll dis[N];
bool vis[N];
int n,m;
void dijkstra(int st,int f){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=0;
	priority_queue<node> q;
	q.push(node{st,0});
	while(!q.empty()){
		node cur=q.top();
		int u=cur.v;
		q.pop();
		if(vis[u]) continue;
		
		vis[u]=1;
		for(auto e:G[f][u]){
			int v=e.v;
			ll w=e.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push(node{v,dis[v]});
			}
		}
	}
}
int main()
{
	int u,v,w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		G[0][u].push_back(node{v,w});
		G[1][v].push_back(node{u,w});
	}
	ll ans=0;
	dijkstra(1,0);
	for(int i=1;i<=n;i++){
		ans+=dis[i];
	}
	dijkstra(1,1);
	for(int i=1;i<=n;i++){
		ans+=dis[i];
	}
	printf("%lld",ans);
	return 0;
}
