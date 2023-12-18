#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int v,w;
};
vector<node> G[N];
int n,m,q;
int dis[N];
bool vis[N];
void bfs(int st){
	queue<int> q;
	q.push(st);
	vis[st]=1;
	dis[st]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto e:G[u]){
			int v=e.v,w=e.w;
			if(vis[v]) continue;
			dis[v]=dis[u]^w;
			vis[v]=1;
			q.push(v);
		}
	}
}
int main()
{
	int u,v,w;
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		G[u].push_back(node{v,w});
		G[v].push_back(node{u,w});
	}
	bfs(1);
	while(q--){
		cin>>u>>v;
		cout<<(dis[u]^dis[v])<<endl;
	}
	
	return 0;
}
