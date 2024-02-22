#include <bits/stdc++.h>
using namespace std;
int L[105],R[105];
int main()
{
	int sum=0;
	int n,p1,p2,p3,t1,t2;
	cin>>n>>p1>>p2>>p3>>t1>>t2;
	for(int i=1;i<=n;i++){
		cin>>L[i]>>R[i];
		sum+=p1*(R[i]-L[i]);
		if(i<=1) continue;
		int fab=L[i]-R[i-1];
		if(fab>=t1+t2){
			sum+=t1*p1+t2*p2+(fab-t1-t2)*p3;
		}else if(fab>t1){
			sum+=t1*p1+(fab-t1)*p2;
		}else{
			sum+=fab*p1;
		}
	}
	cout<<sum;
	return 0;
}
