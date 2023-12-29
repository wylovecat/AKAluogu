#include <bits/stdc++.h>
using namespace std;
const int N=45;
typedef long long ll;
ll sum;
int w[N],n,l,r;
int rnk[N];
void dfs(int d,int total,ll s){
	if(s>r) return;
	if(d==total){
		if(s>=l&&s<=r) sum++;
		return ;
	}
	for(int i=rnk[d]+1;i<=n;i++){
		rnk[d+1]=i;
		dfs(d+1,total,s+w[i]);
	}
}
int main()
{
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		dfs(0,i,0);
	}
	cout<<sum;
	return 0;
}
