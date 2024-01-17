#include <bits/stdc++.h>
using namespace std;
bool isprime(int x){
	if(x<2) return 0;
	for(int i=2;i<=x/i;i++){
		if(x%i==0) return 0;
	}
	return 1;
}
bool hw(int x){
	int _x=0,t=x;
	while(t){
		_x=_x*10+t%10;
		t/=10;
	}
	return x==_x;
}
int main()
{
	int n,cnt=0;
	cin>>n;
	for(int i=11;i<=n;i++){
		if(hw(i)&&isprime(i)){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
