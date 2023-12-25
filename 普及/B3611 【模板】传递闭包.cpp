#include <bits/stdc++.h>
using namespace std;
int f[105][105];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>f[i][j];
		}
	}
//	for(int i=1;i<=n;i++) f[i][i]=1;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=f[i][j]||(f[i][k]&&f[k][j]);
			}
		}		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<f[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
