/*
*    author:  shinter_pres
*    created: 06.05.2021 11:36:12
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> dp(n + 10);
  rep(i, n + 1) {
    if (i == 0) {
      dp[i] = 1;
      continue;
    }
    if (i == 1) {
      dp[i] = 1;
      continue;
    }

    dp[i] = dp[i - 1] + dp[i - 2];
  }

  cout << dp[n] << endl;

  return 0;
}
