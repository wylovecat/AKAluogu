#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5;
typedef long long ll;
struct node{
	int v;
	ll w;
	friend bool operator <(const node &A,const node &B){
		return A.w>B.w;
	}
};
int n,m;
vector<node> G[N];
ll dis[N];
bool vis[N];
void dijkstra(int st){
	priority_queue<node> q;
	memset(dis,0x3f,sizeof(dis));
	dis[st]=0;
	q.push(node{st,dis[st]});
	while(!q.empty()){
		node cur=q.top();
		q.pop();
		int u=cur.v;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto e:G[u]){
			int v=e.v;
			ll w=e.w;
			if(!vis[v] && dis[v]>dis[u]+w){
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
		G[u].push_back(node{v,w});
	}
	dijkstra(1);
	for(int i=1;i<=n;i++){
		printf("%lld ",(dis[i]==dis[0]?-1:dis[i]));
	}
	return 0;
}
