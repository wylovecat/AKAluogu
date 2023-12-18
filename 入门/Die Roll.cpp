#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int x=6-max(a,b)+1;
	int g=__gcd(x,6);
	cout<<x/g<<"/"<<6/g;
	return 0;
}
