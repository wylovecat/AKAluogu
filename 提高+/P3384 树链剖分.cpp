#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;
int n,m,r,p;
vector<int> G[N];
int ori[N];
int dep[N],fa[N],siz[N];
int son[N],top[N],id[N];
int dfs_clock;
int a[N];
i64 w[N<<2],lzy[N<<2];

void maketag(int u,int L,int R,i64 val){
  lzy[u]=(lzy[u]+val)%p;
  w[u]=(w[u]+(R-L+1)*val%p)%p;
}
void pushdown(int u,int L,int R){
  int mid=(L+R)/2;
  maketag(2*u,L,mid,lzy[u]);
  maketag(2*u+1,mid+1,R,lzy[u]);
  lzy[u]=0;
}
void pushup(int u){
  w[u]=(w[2*u]+w[2*u+1])%p;
}
void build(int u,int L,int R){
  if(L==R){
    w[u]=a[L];
    return ;
  }
  int mid=(L+R)/2;
  build(2*u,L,mid);
  build(2*u+1,mid+1,R);
  pushup(u);
}
bool inRange(int L,int R,int l,int r){
  return l<=L && R<=r;
}
bool outofRange(int L,int R,int l,int r){
  return r<L || R<l;
}
i64 query_range(int u,int L,int R,int l,int r){
  if(inRange(L,R,l,r)){
    return w[u]%p;
  }else if(!outofRange(L,R,l,r)){
    pushdown(u,L,R);
    int mid=(L+R)/2;
    return (query_range(2*u,L,mid,l,r)+query_range(2*u+1,mid+1,R,l,r))%p;
  }else{
    return 0;
  }
}
void update_range(int u,int L,int R,int l,int r,i64 val){
  if(inRange(L,R,l,r)){
    maketag(u,L,R,val);
    return ;
  }else if(!outofRange(L,R,l,r)){
    pushdown(u,L,R);
    int mid=(L+R)/2;
    update_range(2*u,L,mid,l,r,val);
    update_range(2*u+1,mid+1,R,l,r,val);
    pushup(u);
  }
}


void dfs1(int u,int f){
  dep[u]=dep[f]+1;
  fa[u]=f;
  siz[u]=1;
  for(auto v:G[u]){
    if(v==f) continue;
    dfs1(v,u);
    siz[u]+=siz[v];
    
    if(!son[u]||siz[ son[u] ]<siz[v]){
      son[u]=v;
    }
  }
}
void dfs2(int u,int topu){
  top[u]=topu;
  id[u]=++dfs_clock;
  a[ id[u] ]=ori[u];
  
  if(!son[u]) return ;
  dfs2(son[u],topu);
  for(auto v:G[u]){
    if(v==fa[u] || v==son[u]) continue;
    dfs2(v,v);
  }
}

i64 query(int x,int y){
  i64 ans=0;
  while(top[x]!=top[y]){
    if(dep[ top[x] ]<dep[ top[y] ]) swap(x,y);
    //x          --->top[x]
    //id[top[x]] --->id[x]
    ans+=query_range(1,1,n,id[top[x]],id[x]);
    ans%=p;
    x=fa[top[x]];
  }
  if(dep[x]>dep[y]) swap(x,y);
  ans+=query_range(1,1,n,id[x],id[y]);
  return ans%p;
}
void update(int x,int y,i64 val){
  while(top[x]!=top[y]){
    if(dep[top[x]]<dep[top[y]]) swap(x,y);
    update_range(1,1,n,id[top[x]],id[x],val);
    x=fa[top[x]];
  }
  if(dep[x]>dep[y]) swap(x,y);
  update_range(1,1,n,id[x],id[y],val);
}
i64 query_tree(int u){
  return query_range(1,1,n,id[u],id[u]+siz[u]-1);
}
void update_tree(int u,i64 val){
  update_range(1,1,n,id[u],id[u]+siz[u]-1,val);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int op,x,y,z;
	cin>>n>>m>>r>>p;
	for(int i=1;i<=n;i++){
	  cin>>ori[i];
	}
	for(int i=1;i<n;i++){
	  cin>>x>>y;
	  G[x].push_back(y);
	  G[y].push_back(x);
	}
	dfs1(r,r);
	dfs2(r,r);
	build(1,1,n);
	
	
	for(int i=1;i<=m;i++){
	  cin>>op;
	  if(op==1){
	    cin>>x>>y>>z;
	    update(x,y,z);
	  }else if(op==2){
	    cin>>x>>y;
	    cout<<query(x,y)<<endl;
	  }else if(op==3){
	    cin>>x>>z;
	    update_tree(x,z);
	  }else{
	    cin>>x;
	    cout<<query_tree(x)<<endl;
	  }
	}
	return 0;
}
