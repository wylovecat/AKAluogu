#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,x;
	string s="";
	cin>>n>>x;
	while(n){
		int u=n%x;
		n/=x;
		if(u>=0&&u<=9) s=char(u+'0')+s;
		else s=char(u-10+'A')+s;
	}
	cout<<s;
	
	return 0;
}
