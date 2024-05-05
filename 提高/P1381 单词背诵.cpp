#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;
map<string,bool> vis;
int n,m;
string word[N];
int check(int mid){
	map<string,int> cnt;
	int diff=0;
	int ans=m;
	for(int L=1,R=1;R<=m;R++){
		if(vis[word[R]]){
			cnt[word[R]]++;
			if(cnt[word[R]]==1){
				diff++;
			}
		}
		if(diff<mid) continue;
		while(L<=R && diff==mid){
			ans=min(ans,R-L+1);
			if(vis[word[L]]){
				cnt[word[L]]--;
				if(cnt[word[L]]==0){
					diff--;
				}
			}
			L++;
		}
	}
	// cout<<"mid:"<<mid<<" ans:"<<ans<<endl;
	return ans==m?-1:ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		vis[s]=1;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>word[i];
	}
	int L=1,R=n;
	int ans1=0,ans2=0;
	while(L<=R){
		int mid=(L+R)/2;
		int x=check(mid);
		if(x!=-1){
			ans1=mid;
			ans2=x;
			L=mid+1;
		}else{
			R=mid-1;
		}
	}
	cout<<ans1<<"\n"<<ans2<<endl;
	return 0;
}
