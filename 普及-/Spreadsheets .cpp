#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//出进制转换
void fun1(int x){
	//R128C494
	//十进制转26进制
//	cout<<"fun1 "<<x<<endl;
	string s="";
	while(x){
		int u=x%26;
		if(u==0){
			u=26;
			x=(x/26)-1;
		}else{
			x/=26;
		}
		
		s=char(u+'A'-1)+s;
	}
	cout<<s;
//	cout<<"---fun1---\n";
}
void fun2(string s){
	int len=s.length();
	ll num=0;
	ll k=1;
	for(int i=len-1;i>=0;i--){
		num=num+(s[i]-'A'+1)*k;
		k*=26;
	}
	cout<<num;
}
int main()
{
	string s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		int len=s.length();
		bool f=0;
		for(int j=0;j<len;j++){
			if(s[j]=='C'){
				f=1;break;
			}
		}
		if(s[0]=='R'&&s[1]>='0'&&s[1]<='9'&&f&&len>=4){//易错点：可能出现RAC22这样的形态 R8
			int row=0,col=0;
			bool flag=0;
			for(int i=1;i<len;i++){
				if(s[i]=='C'&&s[i+1]>='0'&&s[i+1]<='9'){
					flag=1;
					continue;
				}
				if(!flag)
					row=row*10+s[i]-'0';
				else 
					col=col*10+s[i]-'0';
			}
			fun1(col);
			cout<<row<<endl;
		}else{
			string col="";
			int row=0;
			for(int i=0;i<len;i++){
				if(s[i]>='0'&&s[i]<='9'){
					row=row*10+s[i]-'0';
				}else{
					col+=s[i];
				}
			}
			cout<<"R"<<row<<"C";fun2(col);
			cout<<endl;
		}

	}
	
	return 0;
}
