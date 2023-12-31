#include <bits/stdc++.h>
using namespace std;
const int N=2e4+5;
bool vis[N];
vector<int> v[N];
int x[N],d[N];
int main()
{
	int n;
	cin>>n;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>d[i];
		if(x[i]+d[i]>=-10000&&x[i]+d[i]<=10000 && vis[x[i]+d[i]+10000]){
			for(auto j:v[x[i]+d[i]+10000]){
				if(j==-d[i]){
					f=1;
					break;
				}
			}
		}
		if(f) continue;
		vis[x[i]+10000]=1;
		v[x[i]+10000].push_back(d[i]);
	}
	if(f) cout<<"YES";
	else cout<<"NO";
	return 0;
}
