#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;

int n,m,a[N],fa[N],dep[N],siz[N],son[N],top[N],dfn[N],rnk[N];
int h[N*2],nxt[N*2],w[N*2],cur,cnt;
int tag[N*4],xds[N*4],ma[N*4];

void make(int x,int y){
    cur++;
    nxt[cur]=h[x];
    h[x]=cur;
    w[cur]=y;
}

void dfs1(int u){
    siz[u]=1;
    son[u]=-1;
    for(int i=h[u];i;i=nxt[i]){
        if(!dep[w[i]]){
            dep[w[i]]=dep[u]+1;
            fa[w[i]]=u;
            dfs1(w[i]);
            siz[u]+=siz[w[i]];
            if(son[u]==-1||siz[w[i]]>siz[son[u]]) son[u]=w[i];
        }
    }
}

void dfs2(int u,int t){
    top[u]=t;
    dfn[u]=++cnt;
    rnk[cnt]=u;
    if(son[u]==-1) return;
    dfs2(son[u],t);
    for(int i=h[u];i;i=nxt[i]){
        if(w[i]!=son[u]&&w[i]!=fa[u]) dfs2(w[i],w[i]);
    }
}

int in(int l,int r,int L,int R){
    return (L<=l)&&(R>=r);
}

void pushup(int u){
    xds[u]=(xds[u*2]+xds[u*2+1]);
    ma[u] = max(ma[u*2],ma[u*2+1]);
}

void build(int u,int l,int r) {
    if(l==r) {
        ma[u] = xds[u]=a[dfn[l]];
        return;
    }
    int mid=(l+r)>>1;
    build(u*2,l,mid);
    build(u*2+1,mid+1,r);
    pushup(u);
    return;
}

void update(int u,int l,int r,int L,int R,int x){
    if(l==r) {
    	ma[u] = xds[u] = x;
    	return ;
    }
    int mid=(l+r)/2;
    if(L<=mid) update(u*2,l,mid,L,R,x);
    else update(u*2+1,mid+1,r,L,R,x);
    pushup(u);
}

int query(int u,int l,int r,int L,int R){
    if(in(l,r,L,R)){
        return xds[u];
    }
    int mid=(l+r)/2;
  //  pushup(u);
    int ans = 0;
	if(L<=mid) ans = query(u*2,l,mid,L,R);
	if(R>mid) ans += query(u*2+1,mid+1,r,L,R);
	return ans;
}

int qrymax(int u,int l,int r,int L,int R) {
	if(in(l,r,L,R)){
        return ma[u];
    }
    int ans = -1e9 - 7;
    int mid=(l+r)>>1;
 //   pushup(u);
    if(L<=mid) ans = qrymax(u*2,l,mid,L,R);
	if(R>mid) ans = max(ans,qrymax(u*2+1,mid+1,r,L,R));
	return ans;
}

int qryma(int x,int y) {
    int ans = -1e9-7;
	while(top[x]!=top[y]) {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans = max(ans,qrymax(1,1,n,dfn[top[x]],dfn[x]));
        x=fa[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
    return max(ans,qrymax(1,1,n,dfn[y],dfn[x]));
}

int qry(int x,int y){
    int ans = 0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans+=query(1,1,n,dfn[top[x]],dfn[x]);
        x=fa[top[x]];
    }
	if(dep[x]<dep[y]) swap(x,y);
    return ans+query(1,1,n,dfn[y],dfn[x]);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        make(u,v);
        make(v,u);
    }
    for(int i=1;i<=n;i++) cin>>a[i];
	dep[1]=1;
    dfs1(1);
    dfs2(1,1);
    build(1,1,n);
    string op;int t;
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>op;
        if(op=="CHANGE") {
        	cin>>u>>t;
        	update(1,1,n,dfn[u],dfn[u],t);
		} else if(op=="QMAX") {
			cin>>u>>v;
			cout<<qryma(u,v)<<'\n';
		} else {
			cin>>u>>v;
			cout<<qry(u,v)<<'\n';
		}
    }
    return 0;
}