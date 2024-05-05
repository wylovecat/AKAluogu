#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 M = 1e10;
int p;
i64 num[55]={1};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>p;
	for(int i=1;i<=p;i++){
	  int jw=0;
	  for(int j=0;j<50;j++){
	    num[j]=jw+num[j]*2;
	    jw=num[j]/M;
	    num[j]%=M;
	  }
	}
	num[0]-=1;
	printf("%d\n",(int)ceil(log10(2)*p));
	for(int i=49;i>=0;i--){
	  printf("%010lld",num[i]);
	  if(i%5==0) printf("\n");
	}
	return 0;
}
