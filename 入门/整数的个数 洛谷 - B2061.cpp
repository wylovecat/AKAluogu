#include <bits/stdc++.h>
using namespace std;
int cnt[15];
int main()
{
	int k,x;
	cin>>k;
	while(k--){
		cin>>x;
		cnt[x]++;
	} 
	cout<<cnt[1]<<endl<<cnt[5]<<endl<<cnt[10];
	return 0;
}
