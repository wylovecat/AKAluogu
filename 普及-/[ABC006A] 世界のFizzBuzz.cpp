#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	bool f=0;
	cin>>n;
	if(n%3==0) f=1;
	while(n){
		if(n%10==3) f=1;
		n/=10;
	}
	if(f) cout<<"YES";
	else cout<<"NO";
	return 0;
}
