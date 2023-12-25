#include <bits/stdc++.h>
using namespace std;
const int N=105;
int dfn[N],low[N],sccno[N];
int dfs_clock,scc_cnt;
int in[N],out[N];
vector<int> G[N];
stack<int> st;
void tarjan(int u){
	low[u]=dfn[u]=++dfs_clock;
	st.push(u);
	for(auto v:G[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[v],low[u]);
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
		}while(x!=u);
	}
}
int main()
{
	int n,v;
	cin>>n;
	for(int i=1;i<=n;i++){
		while(cin>>v&&v){
			G[i].push_back(v);
		}
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1;i<=n;i++){
		for(auto j:G[i]){
			if(sccno[i]!=sccno[j]){
				in[sccno[j]]++;
				out[sccno[i]]++;
			}
		}
	}
	int cnt1=0,cnt2=0;
	for(int i=1;i<=scc_cnt;i++){
		if(!in[i]) cnt1++;
		if(!out[i]) cnt2++;
	}
	if(scc_cnt==1) cout<<1<<"\n"<<0;
	else cout<<cnt1<<"\n"<<max(cnt1,cnt2);
	return 0;
}
