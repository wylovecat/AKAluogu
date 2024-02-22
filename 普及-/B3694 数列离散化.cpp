#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		int m=unique(b+1,b+n+1)-b-1;
		for(int i=1;i<=n;i++){
			printf("%d ",int(lower_bound(b+1,b+m+1,a[i])-b));
		}
		printf("\n");
	}
	return 0;
}
