#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x){
	if(x<2) return 0;
	if(x%2==0) return 0;
	for(int i=3;i<=x/i;i+=2){
		if(x%i==0) return 0;
	}
	return 1;
}
int reverse(int x){
	int num=0;
	while(x){
		num=num*10+x%10;
		x/=10;
	}
	return num;
}
int main()
{
	int m,n;
	bool f=0;
	cin>>m>>n;
	for(int i=m;i<=n;i++){
		if(isPrime(i)&&isPrime(reverse(i))){
			if(f) cout<<",";
			cout<<i;
			f=1;
		}
	}
	if(!f) cout<<"No";
	return 0;
}
