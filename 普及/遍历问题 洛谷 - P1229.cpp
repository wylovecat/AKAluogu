#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int l1=s1.size(),l2=s2.size();
	int cnt=0;
	for(int i=0;i<l1-1;i++){
		for(int j=1;j<l2;j++){
			if(s1[i]==s2[j] && s1[i+1]==s2[j-1]){
				cnt++;
			}
		}
	}
	cout<<(1<<cnt);
	return 0;
}
