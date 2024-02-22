#include <bits/stdc++.h>
using namespace std;
const int N=55;
int du[N];
int G[N][N];
void dfs(int u){
	for(int v=1;v<=50;v++){
		if(!G[u][v]) continue;
		G[u][v]--;
		G[v][u]--;
		dfs(v);
		cout<<v<<" "<<u<<endl;
	}
}
int main()
{
	int t,cnt=0;
	int n,u,v;
	cin>>t;
	while(t--){
		cnt++;
		if(cnt!=1) cout<<endl;
		cout<<"Case #"<<cnt<<endl;
		memset(du,0,sizeof(du));
		memset(G,0,sizeof(G));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
			du[u]++;
			du[v]++;
			G[u][v]++;
			G[v][u]++;
		}
		bool f=0;
		for(int i=1;i<=50;i++){
			if(du[i]&1){
				f=1;
				cout<<"some beads may be lost\n";
				break;
			}
		}
		if(!f){
			dfs(u);
		}
	}
	
	return 0;
}
