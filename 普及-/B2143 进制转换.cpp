#include <bits/stdc++.h>
using namespace std;
int xToM(int x,int m,char s[],int cnt){
	if(x==0) return cnt;
	
	if(x%m<10) s[cnt]=x%m+'0';
	else s[cnt]=x%m-10+'A';
	return xToM(x/m,m,s,cnt+1);
}


int main(){
	char s[35]={0};
	int x,m;
	cin>>x>>m;
	int len=xToM(x,m,s,0);
	for(int i=len-1;i>=0;i--){
		cout<<s[i];
	}
	return 0;
}
