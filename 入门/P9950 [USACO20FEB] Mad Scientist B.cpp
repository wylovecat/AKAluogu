#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char a[N], c;
int b[N], dp[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  int cnt = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c;
    if (c != a[i]) {
      b[i] = 1;
      if (!b[i - 1]) cnt++;
    }
  }
  cout << cnt;
  return 0;
}