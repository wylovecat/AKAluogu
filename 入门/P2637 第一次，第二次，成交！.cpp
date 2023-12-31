#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int p[N];
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	sort(p+1,p+m+1);
	int maxs=0,idx;
	for(int i=1;i<=m;i++){
		int num=min(n,m-i+1);
		if(p[i]*num>maxs){
			maxs=p[i]*num;
			idx=i;
		}
	}
	cout<<p[idx]<<" "<<maxs;
	return 0;
}
