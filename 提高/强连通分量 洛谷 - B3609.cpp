#include <bits/stdc++.h>
using namespace std;
const int N=10005;
vector<int> G[N];
int n,m;
int dfn[N],low[N],sccno[N];
int dfs_clock,scc_cnt;
stack<int> st;
vector<int> SCC[N];
bool vis[N];
void tarjan(int u){
	dfn[u]=low[u]=++dfs_clock;
	st.push(u);
	for(auto v:G[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(!sccno[v]){
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
int main()
{
	int u,v;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		G[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	cout<<scc_cnt<<endl;
	for(int i=1;i<=n;i++){
	//	printf("sccno[%d]=%d\n",i,sccno[i]);
		SCC[sccno[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(!vis[sccno[i]]){
			vis[sccno[i]]=1;
			for(auto j:SCC[sccno[i]]){
				cout<<j<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
