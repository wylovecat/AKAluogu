#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,p;
}a[500];
int n,m,k,cnt,ans;
bool cmp(node A,node B){
	return A.p>B.p;
}
int dis(node A,node B){
	return abs(A.x-B.x)+abs(A.y-B.y);
}
void dfs(int d,int ti,int sum){
	if(a[d].x+ti>k) return ;
//	printf("%d %d %d\n",d,ti,sum);
	ans=sum;
	dfs(d+1,ti+dis(a[d+1],a[d])+1,sum+a[d+1].p);
}
int main()
{
	int x;
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>x;
			if(x){
				a[++cnt]=node{i,j,x};
			}
		}
	}
	sort(a+1,a+cnt+1,cmp);
	a[0].x=0;a[0].y=a[1].y;
	dfs(0,0,0);
	cout<<ans;
	
	return 0;
}
