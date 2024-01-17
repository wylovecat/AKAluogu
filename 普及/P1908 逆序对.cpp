#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int a[N],b[N];
ll sum;
void merge(int l1,int r1,int l2,int r2){
	int i=l1,j=l2,k=l1;
	while(i<=r1 && j<=r2){
		if(a[i]>a[j]){
			sum+=(r1-i+1);//a[i] ~ a[r1] 都与 a[j]形成逆序对
			b[k++]=a[j++];
		}else{
			b[k++]=a[i++];
		}
	}
	while(i<=r1) b[k++]=a[i++];
	while(j<=r2) b[k++]=a[j++];
	for(int i=l1;i<=r2;i++){
		a[i]=b[i];
	}
}
void mergeSort(int l,int r){
	if(l>=r) return ;
	int mid=(l+r)/2;
	//[l,mid] [mid+1,r]
	//先使得左半部分有序、右半部分有序
	mergeSort(l,mid);
	mergeSort(mid+1,r);
	//合并两个有序的数列
	merge(l,mid,mid+1,r);
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	mergeSort(1,n);
	cout<<sum;
	return 0;
}
