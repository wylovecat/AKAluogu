#include <bits/stdc++.h>
using namespace std;
int dp[35][35];//dp[轮次][人]
//dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1]
int main()
{
	int n,m;
	cin>>n>>m;
	dp[0][0]=1;
	for(int i=1;i<=m;i++){
		for(int j=0;j<n;j++){
			dp[i][j]=dp[i-1][(j-1+n)%n]+dp[i-1][(j+1)%n];
		}
	}
	cout<<dp[m][0];
	return 0;
}
