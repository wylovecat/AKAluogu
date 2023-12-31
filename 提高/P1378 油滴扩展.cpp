#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
	double r;
}dot[10];
const double PI=3.1415926535;
int xa,ya,xb,yb;
double maxs=0;
int n;
int a[10];
bool vis[10];
double dis[10][10];
double dist(int xa,int ya,int xb,int yb){
	return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}
double findR(int id,int k){
	double lenx=min(abs(dot[id].x-xa),abs(dot[id].x-xb));
	double leny=min(abs(dot[id].y-ya),abs(dot[id].y-yb));
	double r=min(lenx,leny);//计算到边界的情况
	for(int i=0;i<k;i++){//计算接触到其他油滴的情况
		int x=a[i];
		double d=dis[id][x]-dot[x].r;
		r=min(max(0.0,d),r);//注意包含的情况
	}
	return r;
}
void dfs(int d,double sum){//d-已经放完的数量 sum-当前的总面积
	if(d==n){
		maxs=max(maxs,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		a[d]=i;
		dot[i].r=findR(i,d);
		dfs(d+1,sum+dot[i].r*dot[i].r*PI);
		vis[i]=0;
	}
}
int main()
{
	cin>>n;
	cin>>xa>>ya>>xb>>yb;
	for(int i=1;i<=n;i++){
		cin>>dot[i].x>>dot[i].y;
	}
	//打表两点之间的距离
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=dist(dot[i].x,dot[i].y,dot[j].x,dot[j].y);
		}
	}
	dfs(0,0);
	printf("%.0lf",abs(xa-xb)*abs(ya-yb)-maxs);
	return 0;
}
