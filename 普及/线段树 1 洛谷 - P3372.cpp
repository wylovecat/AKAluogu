#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
ll a[N],w[N<<2],lzy[N<<2];
int n,m;
void pushup(int u){
	w[u]=w[2*u]+w[2*u+1];
}
void build(int u,int L,int R){
	if(L==R){
		w[u]=a[L];
		return ;
	}
	int mid=(L+R)>>1;
	build(2*u,L,mid);
	build(2*u+1,mid+1,R);
	pushup(u);
}

bool inRange(int L,int R,int l,int r){
	return l<=L&&R<=r;
}
bool outofRange(int L,int R,int l,int r){
	return R<l||r<L;
}

void maketag(int u,int L,int R,ll val){
	lzy[u]+=val;
	w[u]+=(R-L+1)*val;
}
void pushdown(int u,int L,int R){
	int mid=(L+R)/2;
	maketag(2*u,L,mid,lzy[u]);
	maketag(2*u+1,mid+1,R,lzy[u]);
	lzy[u]=0;
}

ll query(int u,int L,int R,int l,int r){
	if(inRange(L,R,l,r)){
		return w[u];
	}else if(!outofRange(L,R,l,r)){
		int mid=(L+R)/2;
		pushdown(u,L,R);
		return query(2*u,L,mid,l,r)+query(2*u+1,mid+1,R,l,r);
	}else{
		return 0;
	}
}

void update(int u,int L,int R,int l,int r,ll x){
	if(inRange(L,R,l,r)){
		maketag(u,L,R,x);
		return ;
	}else if(!outofRange(L,R,l,r)){
		int mid=(L+R)/2;
		pushdown(u,L,R);
		update(2*u,L,mid,l,r,x);
		update(2*u+1,mid+1,R,l,r,x);
		pushup(u);
	}
}

int main()
{
	int op,x,y,k;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	build(1,1,n);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			scanf("%d",&k);
			update(1,1,n,x,y,k);
		}else if(op==2){
			printf("%lld\n",query(1,1,n,x,y));
		}
	}
	return 0;
}
