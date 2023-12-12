#include <bits/stdc++.h>
using namespace std;
bool check(int a[]){
	bool vis[10]={0};
	for(int i=1;i<=3;i++){
		while(a[i]){
			vis[a[i]%10]=1;
			a[i]/=10;
		}
	}
	for(int i=1;i<=9;i++){
		if(!vis[i]) return 0;
	}
	return 1;
}
int main()
{
	int a[4]={0};
	for(int i=123;i<=987/3;i++){
		a[1]=i,a[2]=2*i,a[3]=3*i;
		if(check(a)){
			cout<<i<<" "<<2*i<<" "<<3*i<<endl;
		}
	}
	return 0;
}
