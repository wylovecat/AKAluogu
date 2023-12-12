#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll x1,x2,y1,y2;
	cin>>x1>>x2>>y1>>y2;
	if(x1*y2<INT_MIN || x2*y1<INT_MIN || x2*y2>INT_MAX||x1*y1>=INT_MAX){
		cout<<"long long int";
	}else{
		cout<<"int";
	}
	return 0;
}
