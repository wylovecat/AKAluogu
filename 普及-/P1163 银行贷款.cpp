#include <bits/stdc++.h>
using namespace std;
const double eps=0.0001;
int w0,w,m;
bool check(double mid){
	double sum=0,v=1;
	for(int i=1;i<=m;i++){
		v*=(1+mid);
		sum+=(w/v);
	}
//	printf("mid:%lf sum:%lf\n",mid,sum);
	return sum>=w0;
}
int main()
{
	
	cin>>w0>>w>>m;
	double L=0,R=300;
	double ans=0;
	while(R-L>=eps){
		double mid=(L+R)/2;
		if(check(mid)){
			ans=mid;
			L=mid;
		}else{
			R=mid;
		}
	}
	printf("%.1lf",ans*100);
	return 0;
}



