#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	cin>>x;
	double t1=x/1.2;
	double t2=x/3.0+50;
	if(t1<t2){
		cout<<"Walk";
	}else if(t1>t2){
		cout<<"Bike";
	}else{
		cout<<"All";
	}
	return 0;
}
