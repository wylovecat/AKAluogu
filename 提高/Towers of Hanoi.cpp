#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
const int N = 1e5 + 5;
string s;
i128 m;
i128 toNum(string s){
	i128 num=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		num=num*10+s[i]-'0';
	}
	return num;
}
int cnt[3];
void hanoi(i128 sum,int n,int from,int to,int tmp){
	if(sum==m) return ;
	i128 num=1;
	num=(num<<(n-1))-1;
	if(sum+num>m){
		hanoi(sum,n-1,from,tmp,to);
		return ;
	}
	//n-1个从from 移动到tmp
	cnt[from]-=n-1;
	cnt[tmp]+=n-1;
	
	if(sum+num==m){
		return ;
	}
	//1个 从 from 移动到 to
	cnt[from]--;
	cnt[to]++;
	
	if(sum+num+1==m){
		return ;
	}
	
	hanoi(sum+num+1,n-1,tmp,to,from);
}
int main(){
	int n;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin>>n>>s&&n){
		cnt[0]=n;cnt[1]=cnt[2]=0;
		m=toNum(s);
		hanoi(0,n,0,2,1);
		cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
	}
	return 0;
}
