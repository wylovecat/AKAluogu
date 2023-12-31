#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int x;
	string s;
	cin>>x>>s;
	int num=0;
	ll cf=1;
	int len=s.size();
	for(int i=len-1;i>=0;i--){
		if(s[i]>='0'&&s[i]<='9'){
			num=num+(s[i]-'0')*cf;
		}else{
			num=num+(s[i]-'A'+10)*cf;
		}
		cf*=x;
	}
	cout<<num;
	return 0;
}
