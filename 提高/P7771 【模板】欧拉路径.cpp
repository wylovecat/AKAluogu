#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> G[N];
int vis[N];
int n,m;
int du[N];
int st=-1,ed=-1,cnt=0;
stack<int> s;
void dfs(int u){
	for(int i=vis[u];i<G[u].size();i=vis[u]){
		vis[u]++;
		dfs(G[u][i]);
	}
	s.push(u);
}
int main()
{
	int u,v;
	
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		du[u]++;
		du[v]--;
		G[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		sort(G[i].begin(),G[i].end());
//		printf("du[%d]=%d \n",i,du[i]);
		if(du[i]==1){
			st=i;
		}else if(du[i]==-1){
			ed=i;
		}else if(du[i]==0){
			cnt++;
		}
	}
	if(cnt==n) st=1;//存在欧拉回路
	if(cnt==n||(cnt==n-2&&st!=-1&&ed!=-1)){
		dfs(st);
		while(s.size()){
			cout<<s.top()<<" ";
			s.pop();
		}
	}else{
		cout<<"No";
	}
	
	return 0;
}
