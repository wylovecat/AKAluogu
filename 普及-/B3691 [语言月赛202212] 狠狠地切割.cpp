#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
using i64 = long long;
int n,m;
int a[N],b[N];
bool vis[int(5e6+5)];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
		vis[b[i]]=1;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[a[i]]){
			a[i]=0;
		}
	}
	int L=1,R=n;
	while(L<=R && !a[L]) L++;
	while(L<=R && !a[R]) R--;
	for(int i=L;i<=R;i++){
		if(!a[i] && a[i-1]) cnt++;
	}
	cout<<cnt+1;
	return 0;
}
