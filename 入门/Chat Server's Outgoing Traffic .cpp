#include <bits/stdc++.h>
using namespace std;
set<string> chat;
int main()
{
	int sum=0;
	string s;
	while(getline(cin,s)){
		if(s[0]=='+'){
			string t=s.substr(1);
			chat.insert(t);
		}else if(s[0]=='-'){
			string t=s.substr(1);
			chat.erase(t);
		}else{
			int len=s.length();
			for(int i=0;i<len;i++){
				if(s[i]==':'){
					sum+=chat.size()*(len-i-1);
				}
			}
		}
	}
	cout<<sum;
	
	return 0;
}
