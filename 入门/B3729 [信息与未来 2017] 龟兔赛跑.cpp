#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,t;
	cin>>x>>y>>t;
	//x*T==y*(T-t);
	//x*T==y*T-y*t
	//(y-x)T=y*t
	//T=y*t/(y-x)
	int a=y*t,b=y-x;
//	cout<<floor(1.0*x*a/b);
	cout<<x*a/b;	
	return 0;
}
