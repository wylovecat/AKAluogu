#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int dfn[N],low[N],sccno[N],cnt[N];
int dfs_clock,scc_cnt;
vector<int> G[N];
stack<int> st;
int n,m;
int out[N];
void tarjan(int u){
	low[u]=dfn[u]=++dfs_clock;
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
			cnt[scc_cnt]++;
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
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(auto j:G[i]){
			if(sccno[i]!=sccno[j]){
				out[sccno[i]]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=scc_cnt;i++){
		if(out[i]==0){
			if(ans){
				ans=0;
				break;
				break;
			}
			ans=cnt[i];
		}
	}
	cout<<ans;
	return 0;
}
