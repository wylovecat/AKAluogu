#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e5+5;
int dfn[N],low[N],cnt[N],sccno[N];
int a[N],b[N];
int dfs_clock,scc_cnt;
vector<int> G[N],G2[N];
stack<int> st;
int u[M],v[M],in[N];
int n,m;
queue<int> q;
int dp[N];
void bfs(){
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:G2[u]){
			in[v]--;
			dp[v]=max(dp[v],dp[u]+b[v]);
			if(!in[v]){
				q.push(v);
			}
		}
	}
}

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
	if(dfn[u]==low[u]){
		int x;
		++scc_cnt;
		do{
			x=st.top();st.pop();
			sccno[x]=scc_cnt;
			cnt[scc_cnt]++;
			b[scc_cnt]+=a[x];
		}while(x!=u);
	}
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i];
		G[u[i]].push_back(v[i]);
	}
	//缩点
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	//缩点后重建图
	for(int i=1;i<=m;i++){
		if(sccno[u[i]]==sccno[v[i]]) continue;
		G2[sccno[u[i]]].push_back(sccno[v[i]]);
		in[sccno[v[i]]]++;
	}
	//拓扑序DP
	for(int i=1;i<=scc_cnt;i++){
		if(!in[i]){
			dp[i]=b[i];
			q.push(i);
		}
	}
	bfs();
	int ans=0;
	for(int i=1;i<=scc_cnt;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
