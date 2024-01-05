#include <bits/stdc++.h>
using namespace std;
int ans[10005],k=0;
int main()
{
	string s;
	string bin="";
	cin>>s;
	
	int len=s.size();
	for(int i=len-1;i>=0;i--){
		int num=s[i]-'0';
		for(int j=1;j<=3;j++){
			bin+=num%2+'0';
			num/=2;
		}
	}
	len=bin.size();
	for(int i=0;i<len;i+=4){
		int num=0;
		int cf=1;
		for(int j=i;j<=i+3&& j<len;j++){
			num=num+cf*(bin[j]-'0');
			cf=cf*2;
		}
		ans[++k]=num;
	}
	bool f=0;
	for(int i=k;i>=1;i--){
		if(ans[i]!=0 && !f) f=1;
		if(i==1) f=1;
		if(!f) continue;
		if(ans[i]>=10){
			cout<<char(ans[i]-10+'a');
		}else{
			cout<<ans[i];
		}
	}
	return 0;
}
