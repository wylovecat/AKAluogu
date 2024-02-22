#include <bits/stdc++.h>
using namespace std;
stack<string> st;
int main()
{
	string s;
	while(cin>>s){
		st.push(s);
	}
	while(st.size()){
		s=st.top();
		st.pop();
		int len=s.size();
		if(s[0]>='0' && s[0]<='9'){
			for(int i=len-1;i>=0;i--){
				cout<<s[i];
			}
		}else{
			for(int i=0;i<len;i++){
				if(s[i]>='a' && s[i]<='z') cout<<char(s[i]-32);
				else cout<<char(s[i]+32);
			}
		}
		cout<<" ";
	}
	
	return 0;
}
