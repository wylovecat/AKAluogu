#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int main()
{
	int t,n,a;
	cin>>t;
	while(t--){
		cin>>n;
		bool f=0;
		for(int i=1;i<=n;i++){
			cin>>a;
			bool vis=0;
			for(int j=2;j<=i+1&&!vis;j++){
				if(a%j!=0){//可以删除
					vis=1;
				}
			}
			if(!vis) f=1;//a无法删除 
		}
		if(f==1){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
		}
	}
	return 0;
}
