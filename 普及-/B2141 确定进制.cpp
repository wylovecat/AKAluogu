#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tob(ll x,int b){
	ll num=0,cf=1;
	while(x){
		if(x%10>=b) return -1;
		num=num+cf*(x%10);
		x/=10;
		cf*=b;
	}
	return num;
}
int main()
{
	ll p,q,r;
	cin>>p>>q>>r;
	for(int b=2;b<=16;b++){
		ll p1=tob(p,b);
		ll q1=tob(q,b);
		ll r1=tob(r,b);
	//	cout<<b<<": "<<p1<<"*"<<q1<<"="<<r1<<endl;
		if(p1==-1 || q1==-1 || r1==-1) continue;
		
		if(p1*q1==r1){
			cout<<b;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
