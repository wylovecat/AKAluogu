#include <bits/stdc++.h>
using namespace std;
const int N=2005;
struct node{
	int v,w;
};
vector<node> G[N];
int dis[N];
int cnt[N];
bool vis[N];
int n,m;
bool spfa(int st){
	queue<int> q;
	dis[st]=0;
	q.push(st);
	cnt[st]++;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(auto e:G[u]){
			int v=e.v,w=e.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					cnt[v]++;
					vis[v]=1;
					if(cnt[v]>=n) return 1;	
					q.push(v);
				}
			}
		}
	}
	return 0;
}
int main()
{
	int t,u,v,w;
	cin>>t;
	while(t--){
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<N;i++) G[i].clear();
//		cin>>n>>m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
//			cin>>u>>v>>w;
			scanf("%d%d%d",&u,&v,&w);
			G[u].push_back(node{v,w});
			if(w>=0) G[v].push_back(node{u,w});
		}
		if(spfa(1)){
//			cout<<"YES\n";
			printf("YES\n");
		}else{
//			cout<<"NO\n";
			printf("NO\n");
		}
	}
	return 0;
}
