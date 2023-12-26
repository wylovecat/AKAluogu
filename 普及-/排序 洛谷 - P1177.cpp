#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],n;
void qSort(int L,int R){
	if(L>=R) return ;
	int key=a[(L+R)/2];
	int l=L,r=R;
	while(l<=r){
		//寻找左侧大于key的元素
		while(a[l]<key) l++;
		//寻找右侧小于key的元素
		while(a[r]>key) r--;
		if(l<=r){
			swap(a[l],a[r]);
			l++;
			r--;
		}
	}
	qSort(L,r);
	qSort(l,R);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	qSort(1,n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
