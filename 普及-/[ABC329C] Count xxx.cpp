#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
using i64 = long long;
int n;
char c[N];
int maxL[30];//maxL[i]:字母(i+'a')对应的最长连号长度
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  int len = 0;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    if (c[i] == c[i - 1]) {//当前元素与前一个元素相同
      len++;//连号长度增加
    } else {
      len = 1;//不同时，开始新的连号
    }
    //更新当前元素对应的最长连号长度
    maxL[c[i]-'a'] = max(maxL[c[i]-'a'], len);
  }
  //本质不同的串就是最长连号的长度
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    ans += maxL[i];//累加所有元素的最长连号长度
  }
  cout << ans;
  return 0;
}
