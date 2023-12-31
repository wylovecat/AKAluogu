#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N],n,m;
int main()
{
	int x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	while(m--){
		scanf("%d",&x);
		printf("%d\n",a[x]);
	}
	
	return 0;
}
