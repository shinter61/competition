/*
*    author:  shinter_pres
*    created: 17.07.2021 22:23:21
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  for (int bit = 0; bit < (1<<N); bit++) {
    string ans = "";
    bool correct = true;
    int right = 0, left = 0;
    for (int i = N-1; i >= 0; i--) {
      if (bit & (1<<i)) {
        ans += ")";
        left++;
      } else {
        ans += "(";
        right++;
      }

      if (left > right) { correct = false; }
    }

    if (right != left) { correct = false; }

    if (!correct) { continue; }

    cout << ans << endl;
  }

  return 0;
}
