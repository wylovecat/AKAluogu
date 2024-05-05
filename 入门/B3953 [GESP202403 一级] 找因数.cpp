#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a;
  cin >> a;
  for (int i = 1; i <= a; i++) {
    if (a % i == 0) {
      cout << i << endl;
    }
  }
  return 0;
}
