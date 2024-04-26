#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
using i64 = long long;
int n,x;
i64 H[N];
bool check(int mid){
	//判断跳跃距离为mid时，能否往返2x次
	int L=1,R=1;
	i64 sum=0;
	for(;R<n;R++){
		sum+=H[R];
		if(R-L+1<mid) continue;
		while(L<=R && R-L+1==mid){
			if(sum<2*x) return 0;
			sum-=H[L];
			L++;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>x;
	for(int i=1;i<n;i++){
		cin>>H[i];
	}
	int L=1,R=n;
	int ans=-1;
	while(L<=R){
		int mid=(L+R)/2;
		if(check(mid)){
			ans=mid;
			R=mid-1;
		}else{
			L=mid+1;
		}
	}
	cout<<ans;
	return 0;
}