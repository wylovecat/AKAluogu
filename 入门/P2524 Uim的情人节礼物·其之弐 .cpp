#include <bits/stdc++.h>
using namespace std;
string a,b;

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		b.push_back(i+'0');
	}
	cin>>a;
	int cnt=0;
	while(a!=b){
		cnt++;
		next_permutation(b.begin(),b.end());
	}
	cout<<cnt+1;
	return 0;
}
