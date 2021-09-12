#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  int min = a < b ? a : b;
  int seq = 0;
  int ans;
  for (int i = min; i >= 1; i--) {
    if (a % i == 0 && b % i == 0) seq++;

    if (seq == k) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
