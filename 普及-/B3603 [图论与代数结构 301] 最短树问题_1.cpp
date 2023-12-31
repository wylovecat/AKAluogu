#include <bits/stdc++.h>
using namespace std;
const int N=2005;
typedef long long ll;
struct node{
	int u,v,w;
}E[3005];
int fa[N];
int n,m;
int findRt(int x){
	if(x==fa[x]) return x;
	return fa[x]=findRt(fa[x]);
}
bool cmp(node A,node B){
	return A.w<B.w;
}
int kruskal(){
	ll sum=0;
	for(int i=1;i<=m;i++){
		int u=E[i].u,v=E[i].v,w=E[i].w;
		int fx=findRt(u),fy=findRt(v);
		if(fx==fy) continue;
		fa[fx]=fy;
		sum+=w;
	}
	return sum;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>E[i].u>>E[i].v>>E[i].w;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(E+1,E+m+1,cmp);
	cout<<kruskal();
	return 0;
}
