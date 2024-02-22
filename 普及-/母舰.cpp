#include <iostream>
#include <algorithm>
using namespace std;

const int N=1e5+5;

int def[N];	//防御 
int atk[N];	//攻击 

int main(){
	int m,n;
	cin>>m>>n;
	//m个防御
	for(int i=1;i<=m;i++)	cin>>def[i];
	//n个攻击 
	for(int i=1;i<=n;i++)	cin>>atk[i];
	//升序排序 
	sort(def+1,def+m+1); 
	sort(atk+1,atk+n+1);
	
	//遍历攻击数组 
	int j=1;
	for(int i=1;i<=n;i++){
		if(atk[i]>def[j]){	//能够打破 
			atk[i]=0;	//攻击使用过，清空
			j++;
			//当防御到m+1
			if(j==m+1){
				break;
			} 
		}
	} 
	long long ans=0;
	if(j==m+1){	//防御都破坏了 计算伤害 
		for(int i=1;i<=n;i++){
			ans+=atk[i];
		}
	} 
	cout<<ans;
	return 0;
}
