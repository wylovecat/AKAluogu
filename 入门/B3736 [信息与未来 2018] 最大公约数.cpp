#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<__gcd(a,__gcd(b,c));
	return 0;
}
