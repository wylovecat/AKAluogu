#include <bits/stdc++.h>
using namespace std;
int main()
{
	int ans=1;
	int a,n;
	cin>>a>>n;
	for(int i=1;i<=n;i++){
		ans*=a;
	}
	cout<<ans;
	return 0;
}
