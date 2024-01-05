#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int w_min[N<<4],w_max[N<<4];
int n,k;
void maketag_add(int u,int h){
	w_min[u]=max(w_min[u],h);
	w_max[u]=max(w_max[u],w_min[u]);
}
void maketag_rm(int u,int h){
	w_max[u]=min(w_max[u],h);
	w_min[u]=min(w_min[u],w_max[u]);
}
void pushdown(int u,int L,int R){
	maketag_add(2*u,w_min[u]);
	maketag_add(2*u+1,w_min[u]);
	maketag_rm(2*u,w_max[u]);
	maketag_rm(2*u+1,w_max[u]);
	w_min[u]=0;w_max[u]=1e9;
}
void build(int u,int L,int R){
	if(L==R){
		w_min[u]=0;
		w_max[u]=1e9;
		return ;
	}
	int mid=(L+R)/2;
	build(2*u,L,mid);
	build(2*u+1,mid+1,R);
}
bool inRange(int L,int R,int l,int r){
	return l<=L&&R<=r;
}
bool outofRange(int L,int R,int l,int r){
	return r<L || R<l;
}
void update_add(int u,int L,int R,int l,int r,int h){
	if(inRange(L,R,l,r)){
		maketag_add(u,h);
	}else if(!outofRange(L,R,l,r)){
		int mid=(L+R)/2;
		pushdown(u,L,R);
		update_add(2*u,L,mid,l,r,h);
		update_add(2*u+1,mid+1,R,l,r,h);
	}
}
void update_rm(int u,int L,int R,int l,int r,int h){
	if(inRange(L,R,l,r)){
		maketag_rm(u,h);
	}else if(!outofRange(L,R,l,r)){
		int mid=(L+R)/2;
		pushdown(u,L,R);
		update_rm(2*u,L,mid,l,r,h);
		update_rm(2*u+1,mid+1,R,l,r,h);
	}
}
void query(int u,int L,int R){
	if(L==R){
		printf("%d\n",w_min[u]);
		return ;
	}
	int mid=(L+R)/2;
	pushdown(u,L,R);
	query(2*u,L,mid);
	query(2*u+1,mid+1,R);
}
int main()
{
	int op,L,R,h;
	scanf("%d%d",&n,&k);
	build(1,1,n);
	while(k--){
		scanf("%d%d%d%d",&op,&L,&R,&h);
		L++;R++;
		if(op==1){
			update_add(1,1,n,L,R,h);
		}else if(op==2){
			update_rm(1,1,n,L,R,h);
		}
	}
	query(1,1,n);
	return 0;
}
