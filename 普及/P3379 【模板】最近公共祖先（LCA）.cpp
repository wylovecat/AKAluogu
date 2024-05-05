#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 5e5 + 5;
int n,m,s;
vector<int> G[N];
int siz[N],dep[N],fa[N],son[N];
int top[N],id[N];
void dfs1(int u,int f){
  dep[u]=dep[f]+1;
  fa[u]=f;
  siz[u]=1;
  for(auto v:G[u]){
    if(v==f) continue;
    dfs1(v,u);
    siz[u]+=siz[v];
    
    if(!son[u]||siz[son[u]]<siz[v]){
      son[u]=v;
    }
  }
}
void dfs2(int u,int topu){
  top[u]=topu;
  if(!son[u]) return ;
  dfs2(son[u],topu);
  for(auto v:G[u]){
    if(v==fa[u] || v==son[u]) continue;
    dfs2(v,v);
  }
}
int LCA(int x,int y){
  while(top[x]!=top[y]){
    if(dep[ top[x] ]<dep[ top[y] ]) swap(x,y);
    x=fa[ top[x] ];
  }
  return dep[x]<dep[y]?x:y;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x,y;
	cin>>n>>m>>s;
	for(int i=1;i<n;i++){
	  cin>>x>>y;
	  G[x].push_back(y);
	  G[y].push_back(x);
	}
	dfs1(s,s);
	dfs2(s,s);
	for(int i=1;i<=m;i++){
	  cin>>x>>y;
	  cout<<LCA(x,y)<<endl;
	}
	return 0;
}
