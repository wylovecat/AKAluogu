#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z,cnt=0;
	cin>>x>>y>>z;
	if(x<60) cnt++;
	if(y<60) cnt++;
	if(z<60) cnt++;
	cout<<(cnt==1?1:0);
	return 0;
}
