#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
const int N = 1e5 + 5;
int main(){
  int n;
  string x;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>x;
    int len = x.length();
    int last = x[len-1]-'0';
    if(last%2==0){
      cout<<"even\n";
    }else{
      cout<<"odd\n";
    }
  }
  return 0;
}