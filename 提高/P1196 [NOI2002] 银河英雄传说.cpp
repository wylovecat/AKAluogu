#include <bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int fa[N*3];
int findRt(int x){
	if(x==fa[x]) return x;
	return fa[x]=findRt(fa[x]);
}
void merge(int x,int y){
	int fx=findRt(x),fy=findRt(y);
	fa[fx]=fy;
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=3*n;i++){
		fa[i]=i;
	}
	int ans=0;
	int op,x,y;
	while(k--){
		cin>>op>>x>>y;
		if(x>n||y>n){
			ans++;
			continue;
		}
		if(op==1){//同类
			//非同类：x吃y || y吃x
			if(findRt(x+n)==findRt(y)||findRt(y+n)==findRt(x)){
				ans++;
			}else{
				merge(x,y);
				merge(x+n,y+n);
				merge(x+2*n,y+2*n);
			}
		}else{//x吃y
			//x,y同类 || y吃x
			if(findRt(x)==findRt(y)||findRt(y+n)==findRt(x)){
				ans++;
			}else{
				//x      x+n x+2*n
				//y+2*n   y  y+n
				merge(y+2*n,x);
				merge(x+n,y);
				merge(y+n,x+2*n);
			}
		}
	}
	cout<<ans;
	return 0;
}
