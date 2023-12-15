#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int cnt,root;
struct node{
	int lc,rc;
	int val,pri;
	int siz;
}t[N];

//新增节点
int newNode(int x){
	t[++cnt].val=x;
	t[cnt].pri=rand();
	t[cnt].lc=t[cnt].rc=0;
	t[cnt].siz=1;
	return cnt;
}
void update(int u){
	t[u].siz=t[ t[u].lc ].siz+t[ t[u].rc ].siz+1;
}
void split(int u,int x,int &L,int &R){
	if(u==0){
		L=R=0;
		return ;
	}
	if(t[u].val<=x){
		L=u;
		split(t[u].rc,x,t[u].rc,R);
	}else{
		R=u;
		split(t[u].lc,x,L,t[u].lc);
	}
	update(u);
}
int Merge(int L,int R){
	if(L==0||R==0) return L+R;
	if(t[L].pri>t[R].pri){
		t[L].rc=Merge(t[L].rc,R);
		update(L);
		return L;
	}else{
		t[R].lc=Merge(L,t[R].lc);
		update(R);
		return R;
	}
}
void insert(int x){
	int L,R;
	split(root,x,L,R);
	int rx=Merge(L,newNode(x));
	root=Merge(rx,R);
}
void Del(int x){
	int L,R,p;
	split(root,x,L,R);
	split(L,x-1,L,p);
	p=Merge(t[p].lc,t[p].rc);
	root=Merge(Merge(L,p),R);
}
int Rank(int x){
	int L,R;
	split(root,x-1,L,R);
	int ans=t[L].siz+1;
	root=Merge(L,R);
	return ans;
}
int Kth(int u,int k){
	if(k==t[t[u].lc].siz+1) return u;
	else if(k<=t[t[u].lc].siz) return Kth(t[u].lc,k);
	else return Kth(t[u].rc,k-t[ t[u].lc ].siz-1);
}

int pre(int x){
	int L,R;
	split(root,x-1,L,R);
	int ans=t[Kth(L,t[L].siz)].val;
	root=Merge(L,R);
	return ans;
}
int aft(int x){
	int L,R;
	split(root,x,L,R);
	int ans=t[Kth(R,1)].val;
	root=Merge(L,R);
	return ans;
}

int main()
{
	srand(time(0));
	int n;
	cin>>n;
	int op,x;
	while(n--){
		cin>>op>>x;
		if(op==1) insert(x);
		else if(op==2) Del(x);
		else if(op==3) cout<<Rank(x)<<endl;
		else if(op==4) cout<<t[Kth(root,x)].val<<endl;
		else if(op==5) cout<<pre(x)<<endl;
		else if(op==6) cout<<aft(x)<<endl;
	}
	return 0;
}
