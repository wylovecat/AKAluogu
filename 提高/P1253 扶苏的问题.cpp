#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6 + 5;
const i64 INF = 1e18;

int n,q;
int a[N];
i64 w[N<<2],lzy_add[N<<2],lzy_re[N<<2];
void pushup(int u){
	w[u]=max(w[2*u],w[2*u+1]);
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
	return l<=L&&R<=r;
}
bool outofRange(int L,int R,int l,int r){
	return r<L || R<l;
}
void maketag_re(int u,int L,int R,i64 val){
	lzy_re[u]=val;
	lzy_add[u]=0;
	w[u]=val;
}
void maketag_add(int u,int L,int R,i64 val){
	if(lzy_re[u]!=INF){
		lzy_re[u]+=val;
		lzy_add[u]=0;
		w[u]=lzy_re[u];
	}else{
		lzy_add[u]+=val;
		w[u]+=val;	
	}
}
void pushdown(int u,int L,int R){
	int mid=(L+R)/2;
	if(lzy_re[u]!=INF){
		maketag_re(2*u,L,mid,lzy_re[u]);
		maketag_re(2*u+1,mid+1,R,lzy_re[u]);
		lzy_re[u]=INF;
		lzy_add[u]=0;
	}else{
		maketag_add(2*u,L,mid,lzy_add[u]);
		maketag_add(2*u+1,mid+1,R,lzy_add[u]);
		lzy_add[u]=0;
	}
}
void update_re(int u,int L,int R,int l,int r,i64 val){
	if(inRange(L,R,l,r)){
		maketag_re(u,L,R,val);
	}else if(!outofRange(L,R,l,r)){
		int mid=(L+R)/2;
		pushdown(u,L,R);
		update_re(2*u,L,mid,l,r,val);
		update_re(2*u+1,mid+1,R,l,r,val);
		pushup(u);
	}
}
void update_add(int u,int L,int R,int l,int r,i64 val){
	if(inRange(L,R,l,r)){
		maketag_add(u,L,R,val);
	}else if(!outofRange(L,R,l,r)){
		int mid=(L+R)/2;
		pushdown(u,L,R);
		update_add(2*u,L,mid,l,r,val);
		update_add(2*u+1,mid+1,R,l,r,val);
		pushup(u);
	}
}
i64 query(int u,int L,int R,int l,int r){
	if(inRange(L,R,l,r)){
		return w[u];
	}else if(!outofRange(L,R,l,r)){
		pushdown(u,L,R);
		int mid=(L+R)/2;
		return max(query(2*u,L,mid,l,r),query(2*u+1,mid+1,R,l,r));
	}else{
		return -INF;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int op,l,r,x;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=4*n;i++){//需要初始化
		lzy_re[i]=INF;
	}
	build(1,1,n);
	for(int i=1;i<=q;i++){
		cin>>op>>l>>r;
		if(op==1){
			cin>>x;
			update_re(1,1,n,l,r,x);
		}else if(op==2){
			cin>>x;
			update_add(1,1,n,l,r,x);
		}else{
			cout<<query(1,1,n,l,r)<<endl;
		}
	}
	return 0;
}
