#include <bits/stdc++.h>
using namespace std;
const double eps=1e-6;
int n;
double a[15];
double f(double x){
	double ans=0;
	for(int i=n;i>=0;i--){
		ans=ans*x+a[i];
	}
	return ans;
}
int main()
{
	double l,r;
	cin>>n>>l>>r;
	for(int i=n;i>=0;i--) cin>>a[i];
	while(r-l>eps){
		double mid=(l+r)/2;
		if(f(mid-eps)>f(mid)) r=mid;
		else l=mid;
	}
	printf("%.5f",l);
	return 0;
}
