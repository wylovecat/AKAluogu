#include <bits/stdc++.h>
using namespace std;
int main()
{
	double x,y;
	cin>>x;
	if(x>=0&&x<5) y=-x+2.5;
	else if(x<10) y=2-1.5*(x-3)*(x-3);
	else y=x/2.0-1.5;
	printf("%.3lf",y);
	return 0;
}
