#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,s=0,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		s+=x;
	}
	printf("%d %.5f",s,s*1.0/n);
	
	return 0;
}
