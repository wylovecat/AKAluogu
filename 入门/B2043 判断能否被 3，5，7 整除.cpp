#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x,f=0;
	cin>>x;
	if(x%3==0){ f=1;cout<<3<<" ";}
	if(x%5==0) {f=1;cout<<5<<" ";}
	if(x%7==0) {f=1;cout<<7<<" ";}
	if(!f) cout<<"n";
	return 0;
}
