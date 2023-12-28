#include <bits/stdc++.h>
using namespace std;
const int N=250;
int dp[N][N];//dp[i][j] [i,j]合并i~j的最大分数
int n;
int main()
{
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>dp[i][i];
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			for(int k=i;k<j;k++){
				if(dp[i][k]==dp[k+1][j]){//相邻两块相同则能合并
					dp[i][j]=max(dp[i][j],dp[i][k]+1);
					ans=max(ans,dp[i][j]);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
