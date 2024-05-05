#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 5;
int n,q;
int a[N];
int w[N<<2],lenL[N<<2],lenR[N<<2];
/*
w[u] 线段树节点u维护的区间中，最长的连续01序列长度
lenL[u] 线段树节点u维护的区间中，以区间左端点为起点的最长连续01序列长度
lenR[u] 线段树节点u维护的区间中，以区间右端点为终点的最长连续01序列长度
*/
void pushup(int u,int L,int R){
  int mid=(L+R)/2;
  //       u
  //   2*u   2*u+1
  //[L,mid] [mid+1,R]
  lenL[u]=lenL[2*u];
  lenR[u]=lenR[2*u+1];
  w[u]=max(w[2*u],w[2*u+1]);
  if(a[mid]!=a[mid+1]){//两段区间可以拼接到一起
  //                  2*u      2*u+1
  //              [...,mid]+[mid+1,...]
    w[u]=max(w[u],lenR[2*u]+lenL[2*u+1]);
    if(w[2*u]==mid-L+1) lenL[u]=mid-L+1+lenL[2*u+1];
    if(w[2*u+1]==R-mid) lenR[u]=lenR[2*u]+R-mid;
  }
}
void build(int u,int L,int R){
  if(L==R){
    w[u]=lenL[u]=lenR[u]=1;
    return ;
  }
  int mid=(L+R)/2;
  build(2*u,L,mid);
  build(2*u+1,mid+1,R);
  pushup(u,L,R);
}
void update(int u,int L,int R,int x){
  if(L==R && L==x){
    a[L]^=1;
    return ;
  }
  int mid=(L+R)/2;
  if(x<=mid) update(2*u,L,mid,x);
  else update(2*u+1,mid+1,R,x);
  pushup(u,L,R);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x;
	cin>>n>>q;
	build(1,1,n);
	for(int i=1;i<=q;i++){
	  cin>>x;
	  update(1,1,n,x);
	  cout<<w[1]<<endl;
	}
	return 0;
}
