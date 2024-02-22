#include <bits/stdc++.h>
using namespace std;
int main()
{
	int xa,ya,xb,yb;
	int xc,yc,xd,yd;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;
		if(xa>xb) swap(xa,xb);
		if(yc>yd) swap(yc,yd);
		int x=xc,y=ya;
	//	printf("\n(%d,%d)\n",x,y);
		if(x>=xa&&x<=xb && y>=yc&&y<=yd){//相交
			cout<<0<<endl;
		}else if((y<yc || y>yd)&&(x<xa ||x>xb)){//不相交
			cout<<2<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
}
