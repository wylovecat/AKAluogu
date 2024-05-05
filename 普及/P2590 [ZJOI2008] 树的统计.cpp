#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 3e4 + 5;
const int INF=-0x3f3f3f3f;
int ori[N];
int n,q;
vector<int> G[N];
int dep[N],fa[N],siz[N],son[N];
int top[N],id[N],a[N],dfs_clock;

int w1[N<<2],w2[N<<2],lzy[N<<2];//总和、最值

void maketag(int u,int L,int R,int val){
  lzy[u]=val;
  w1[u]=(R-L+1)*val;
  w2[u]=val;
}
void pushdown(int u,int L,int R){
  int mid=(L+R)/2;
  if(lzy[u]==INF) return ;
  maketag(2*u,L,mid,lzy[u]);
  maketag(2*u+1,mid+1,R,lzy[u]);
  lzy[u]=INF;
}
void pushup(int u){
  w1[u]=w1[2*u]+w1[2*u+1];
  w2[u]=max(w2[2*u],w2[2*u+1]);
}
void build(int u,int L,int R){
  if(L==R){
    w1[u]=a[L];
    w2[u]=a[L];
    return ;
  }
  int mid=(L+R)/2;
  build(2*u,L,mid);
  build(2*u+1,mid+1,R);
  pushup(u);
}
bool inRange(int L,int R,int l,int r){
  return l<=L&&R<=r;
}
bool outofRange(int L,int R,int l,int r){
  return r<L||R<l;
}
void update(int u,int L,int R,int l,int r,int val){
  if(inRange(L,R,l,r)){
    maketag(u,L,R,val);
  }else if(!outofRange(L,R,l,r)){
    pushdown(u,L,R);
    int mid=(L+R)/2;
    update(2*u,L,mid,l,r,val);
    update(2*u+1,mid+1,R,l,r,val);
    pushup(u);
  }
}
int query_Sum(int u,int L,int R,int l,int r){
  if(inRange(L,R,l,r)){
    return w1[u];
  }else if(!outofRange(L,R,l,r)){
    pushdown(u,L,R);
    int mid=(L+R)/2;
    return query_Sum(2*u,L,mid,l,r)+query_Sum(2*u+1,mid+1,R,l,r);
  }else{
    return 0;
  }
}
int query_Max(int u,int L,int R,int l,int r){
  if(inRange(L,R,l,r)){
    return w2[u];
  }else if(!outofRange(L,R,l,r)){
    pushdown(u,L,R);
    int mid=(L+R)/2;
    return max(query_Max(2*u,L,mid,l,r),query_Max(2*u+1,mid+1,R,l,r));
  }else{
    return INF;
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
  a[id[u]]=ori[u];
  if(!son[u]) return ;
  dfs2(son[u],topu);
  for(auto v:G[u]){
    if(v==fa[u] || v==son[u]) continue;
    dfs2(v,v);
  }
}

void update_Range(int x,int y,int val){
  while(top[x]!=top[y]){
    if(dep[ top[x] ]<dep[ top[y] ]) swap(x,y);
    update(1,1,n,id[ top[x] ],id[x],val);
    x=fa[ top[x] ];
  }
  if(dep[x]<dep[y]) swap(x,y);
  update(1,1,n,id[y],id[x],val);
}
int query_PathMax(int x,int y){
  int ans=INF;
  while(top[x]!=top[y]){
    if(dep[ top[x] ]<dep[ top[y] ]) swap(x,y);
    ans=max(ans,query_Max(1,1,n,id[top[x]],id[x]));
    x=fa[ top[x] ];
  }
  if(dep[x]<dep[y]) swap(x,y);
  return max(ans,query_Max(1,1,n,id[y],id[x]));
}
int query_PathSum(int x,int y){
 // cout<<"["<<x<<","<<y<<"]=";
  int ans=0;
  while(top[x]!=top[y]){
    if(dep[ top[x] ]<dep[ top[y]]) swap(x,y);
   // cout<<"("<<id[top[x]]<<","<<id[x]<<")+";
    ans+=query_Sum(1,1,n,id[top[x]],id[x]);
    x=fa[ top[x] ];
  }
  if(dep[x]<dep[y]) swap(x,y);
 // cout<<"("<<id[y]<<","<<id[x]<<")\n";
  return ans+query_Sum(1,1,n,id[y],id[x]);
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int u,v;
	string op;
	cin>>n;
	for(int i=1;i<n;i++){
	  cin>>u>>v;
	  G[u].push_back(v);
	  G[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
	  cin>>ori[i];
	}
	dfs1(1,1);
	dfs2(1,1);
	
	for(int i=1;i<=4*n;i++){
	  lzy[i]=INF;
	}
	build(1,1,n);
	cin>>q;
	for(int i=1;i<=q;i++){
	  cin>>op>>u>>v;
	  if(op=="CHANGE"){
	    update_Range(u,u,v);
	  }else if(op=="QMAX"){
	    cout<<query_PathMax(u,v)<<endl;
	  }else if(op=="QSUM"){
	    cout<<query_PathSum(u,v)<<endl;
	  }
	}
	return 0;
}
