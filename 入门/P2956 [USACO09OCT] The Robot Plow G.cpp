#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
const int N = 250;
int b[N][N],a[N][N];
int n,m,k;
int main(){
  cin>>n>>m>>k;
  for(int i=1;i<=k;i++){
    int xa,ya,xb,yb;
    //提供坐标系中左下角、右上角的位置
    cin>>xa>>ya>>xb>>yb;
    b[xa][ya]++;
    b[xb+1][ya]--;
    b[xa][yb+1]--;
    b[xb+1][yb+1]++;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+b[i][j];
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j]!=0){
        ans++;
      }
    }
  }
  cout<<ans<<"\n";
  return 0;
}