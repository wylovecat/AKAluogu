#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	bool f=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='0') f=1;
		if(f) cout<<s[i];
	}
	return 0;
}
