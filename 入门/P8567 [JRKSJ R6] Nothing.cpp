#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll L,R;
	int t;
	cin>>t;
	while(t--){
		cin>>L>>R;
		ll len=(R-L+1);
		if(L&1){
			if(len&1){
				cout<<len/2+1<<endl;
			}else{
				cout<<len/2<<endl;
			}
		}else{
			if(len&1){
				cout<<(len-1)/2<<endl;
			}else{
				cout<<len/2<<endl;
			}
		}
	}
	return 0;
}
