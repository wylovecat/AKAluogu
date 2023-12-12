#include <bits/stdc++.h>
using namespace std;
const double EPS=0.0001;
double a,b,c,d;
double func(double x){
	return a*x*x*x+b*x*x+c*x+d;
}
int main(){
	int cnt=0;
	cin>>a>>b>>c>>d;
	for(int i=-100;i<100;i++){
		double L=i,R=i+1;
		double res1=func(L);
		double res2=func(R);
		if(!res1){
			cnt++;
			printf("%.2lf ",L);
		}else if(res1*res2<0){
			while(R-L>=EPS){
				double mid=(L+R)/2;
				if(func(L)*func(mid)<0){
					R=mid;
				}else{
					L=mid;
				}
			}
			cnt++;
			printf("%.2lf ",R);
		}
		if(cnt==3) break;
	}
	return 0;
}
