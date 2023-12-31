#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b;
	cin>>a>>b;
	cout<<__gcd(a,b)<<" "<<a/__gcd(a,b)*b;
	return 0;
}
