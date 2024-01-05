#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll a[N],w[N<<2],lzy_add[N<<2],lzy_mul[N<<2];
int n,m,p;
void maketag_add(int u,int L,int R,ll val){
	lzy_add[u]=(lzy_add[u]+val)%p;
	w[u]=(w[u]+(R-L+1)*val)%p;
}
void maketag_mul(int u,int L,int R,ll val){
	lzy_mul[u]=(lzy_mul[u]*val)%p;
	w[u]=(w[u]*val)%p;
	lzy_add[u]=(lzy_add[u]*val)%p;
}
void pushdown(int u,int L,int R){
	int mid=(L+R)/2;
	maketag_mul(2*u,L,mid,lzy_mul[u]);
	maketag_mul(2*u+1,mid+1,R,lzy_mul[u]);
	maketag_add(2*u,L,mid,lzy_add[u]);
	maketag_add(2*u+1,mid+1,R,lzy_add[u]);
	lzy_add[u]=0;
	lzy_mul[u]=1;
}
void pushup(int u){
	w[u]=(w[2*u]+w[2*u+1])%p;
}
void build(int u,int L,int R){
	
	if(L==R){
		w[u]=a[L]%p;
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
ll query(int u,int L,int R,int l,int r){
	if(inRange(L,R,l,r)){
		return w[u]%p;
	}else if(!outofRange(L,R,l,r)){
		int mid=(L+R)/2;
		pushdown(u,L,R);
		return (query(2*u,L,mid,l,r)%p+query(2*u+1,mid+1,R,l,r)%p)%p;
	}else{
		return 0;
	}
}
void update_add(int u,int L,int R,int l,int r,ll val){
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
void update_mul(int u,int L,int R,int l,int r,ll val){
	if(inRange(L,R,l,r)){
		maketag_mul(u,L,R,val);
	}else if(!outofRange(L,R,l,r)){
		int mid=(L+R)/2;
		pushdown(u,L,R);
		update_mul(2*u,L,mid,l,r,val);
		update_mul(2*u+1,mid+1,R,l,r,val);
		pushup(u);
	}
}
int main()
{
	int op,L,R,val;
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]%=p;
	}
	build(1,1,n);
	for(int i=1;i<(N<<2);i++) lzy_mul[i]=1;
	cin>>m;
	while(m--){
		cin>>op>>L>>R;
		if(op==1){
			cin>>val;
			update_mul(1,1,n,L,R,val);
		}else if(op==2){
			cin>>val;
			update_add(1,1,n,L,R,val);
		}else if(op==3){
			cout<<query(1,1,n,L,R)<<endl;
		}
	}
	
	return 0;
}
