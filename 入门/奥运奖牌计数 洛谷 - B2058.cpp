#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,s1=0,s2=0,s3=0;
	int x,y,z;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>z;
		s1+=x;
		s2+=y;
		s3+=z;
	}
	cout<<s1<<" "<<s2<<" "<<s3<<" "<<s1+s2+s3;
	
	return 0;
}
