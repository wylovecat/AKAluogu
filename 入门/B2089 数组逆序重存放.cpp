#include <bits/stdc++.h>
using namespace std;
void out(int n){
	if(n==0) return ;
	int x;
	cin>>x;
	out(n-1);
	cout<<x<<" ";
}
int main()
{
	int n;
	cin>>n;
	out(n);
	return 0;
}
