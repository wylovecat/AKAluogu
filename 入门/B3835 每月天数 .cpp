#include <bits/stdc++.h>
using namespace std;
int a,b;
int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	cin>>a>>b;
	if((a%4==0&&a%100!=0) || a%400==0) m[2]++;
	cout<<m[b];
	return 0;
}
