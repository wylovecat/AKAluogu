#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n;
int a[N],b[N],c[N];
double F(double x){
	double ans=2e9;
	for(int i=1;i<=n;i++){
		ans=min(ans,a[i]*x*x+b[i]*x+c[i]);
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		
	}
	return 0;
}
