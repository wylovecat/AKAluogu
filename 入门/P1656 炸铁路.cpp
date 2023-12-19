#include <bits/stdc++.h>
using namespace std;
const int N=155;
int dfn[N],low[N],sccno[N];
int dfs_clock,scc_cnt,anscnt;
vector<int> G[N];
stack<int> st;
struct node{
	int u,v;
}edge[N*N];
void dfs(int u,int f){
	low[u]=dfn[u]=++dfs_clock;
	st.push(u);
	for(auto v:G[u]){
		if(v==f) continue;
		if(!dfn[v]){
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				edge[anscnt++]=node{min(u,v),max(u,v)};
			}
		}else{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		int x;
		++scc_cnt;
		do{
			x=st.top();st.pop();
			sccno[x]=scc_cnt;
		}while(x!=u);
	}
}
bool cmp(node A,node B){
	if(A.u!=B.u) return A.u<B.u;
	return A.v<B.v;
}
int main()
{
	int n,m;
	int u,v;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) dfs(i,i);
	}
	sort(edge,edge+anscnt,cmp);
	for(int i=0;i<anscnt;i++){
		printf("%d %d\n",edge[i].u,edge[i].v);
	}
	return 0;
}
