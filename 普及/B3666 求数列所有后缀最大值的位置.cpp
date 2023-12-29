#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef unsigned long long ull;
ull a[N];
stack<int> s;
int main()
{
	int ans=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%llu",&a[i]);
		while(!s.empty() && a[s.top()]<=a[i]){
			ans^=s.top();
			s.pop();
		}
		ans^=i;
		s.push(i);
		printf("%d\n",ans);
	}
	
	return 0;
}
