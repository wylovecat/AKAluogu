#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int findc(ll len,ll n){
	if(len==s.size()){
		return n-1;
	}
	ll mid=len/2;
	if(n<=mid){
		return findc(mid,n);
	}else{
		if(n==mid+1){
			return findc(mid,n-1);
		}else{//原串 ->  原串(原串后移1)
			return findc(mid,n-mid-1);
		}
	}
}
int main()
{
	ll n;
	cin>>s>>n;
	ll len=s.size();
	while(len<n) len*=2;
	int idx=findc(len,n);
	cout<<s[idx];
	return 0;
}
