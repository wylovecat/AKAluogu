#include <cstdio>
using namespace std;
const int N=1e5+5;
int l,n,k;
int a[N];
bool check(int mid){
	int sum=0;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]>mid){
			sum+=(a[i]-a[i-1]-1)/mid;
		}
	}
	return sum<=k;
}
int read(){
	char c=getchar();
	int num=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0' && c<='9'){num=num*10+c-'0';c=getchar();}
	return num;
}
void write(int x){
	int ans[35]={0},top=0;
	while(x){
		ans[++top]=x%10;
		x/=10;
	}
	do{
		putchar(ans[top--]+'0');
	}while(top);
}
int main()
{
	l=read();n=read();k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	int L=1,R=l;
	int ans=0;
	while(L<=R){
		int mid=(L+R)/2;
		if(check(mid)){
			ans=mid;
			R=mid-1;
		}else{
			L=mid+1;
		}
	}
	write(ans);
	return 0;
}
