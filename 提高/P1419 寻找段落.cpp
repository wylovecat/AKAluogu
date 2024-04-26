#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;
const double eps=1e-5;
double a[N<<1];
double sum[N<<1];
int n,s,t;
bool check(double mid){
	deque<int> q;
	for(int i=1;i<=n+t-s;i++){//注意结束位置 最后一段会存在 L最多到 n-s+1处
		sum[i]=sum[i-1]+(a[i]-mid);
	}
  for(int i=s;i<=n+t-s;i++)//注意结束位置
  {  
 			while(!q.empty()&&i-q.front()>t-s)  
        q.pop_front(); 

      while(!q.empty()&&sum[q.back()]<sum[i])
      	q.pop_back();
      q.push_back(i); 
      if(i<t) continue;
      int R=q.front(),L=i-t+1;
      if(sum[R]-sum[L-1]>=0) return 1; 
  }  
  return 0;  
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	cin>>s>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	double ans=0;
	double L=-sum[n],R=sum[n];
	while(R-L>eps){
		double mid=(L+R)/2;
		if(check(mid)){
			ans=mid;
			L=mid+eps;
		}else{
			R=mid-eps;
		}
	}
	cout<<fixed<<setprecision(3)<<ans;
	return 0;
}
