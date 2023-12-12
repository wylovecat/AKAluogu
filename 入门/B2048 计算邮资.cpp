#include <bits/stdc++.h>
using namespace std;
int main()
{
	char op;
	int x,s=0;
	cin>>x>>op;
	if(x<=1000){
		s=8;
	}else{
		s=8+ceil((x-1000.0)/500.0)*4;
	}
	if(op=='y') s+=5;
	cout<<s;
	return 0;
}
