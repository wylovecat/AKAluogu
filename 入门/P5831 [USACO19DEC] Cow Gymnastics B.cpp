#include <bits/stdc++.h>
using namespace std;
int rk[25][25];
int main()
{
	int n,k,x,cnt=0;
	cin>>k>>n;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>x;
			rk[i][x]=j;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			bool f=0;
			for(int l=1;l<=k;l++){
				if(rk[l][i]>rk[l][j]){
					f=1;
					break;
				}
			}
			if(!f) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
