#include <bits/stdc++.h>
using namespace std;
bool chk1(int a,int b,int c){
	return (a+b>c)&&(a+c>b)&&(b+c>a);
}
bool chk2(int a,int b,int c){
	return (a+b>=c)&&(a+c>=b)&&(b+c>=a);
}
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(chk1(a,b,c)||chk1(a,b,d)||chk1(b,c,d)||chk1(a,c,d)){
		cout<<"TRIANGLE";
	}else if(chk2(a,b,c)||chk2(a,b,d)||chk2(b,c,d)||chk2(a,c,d)){
		cout<<"SEGMENT";
	}else{
		cout<<"IMPOSSIBLE";
	}
	return 0;
}
