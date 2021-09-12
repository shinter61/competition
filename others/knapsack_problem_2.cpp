/*
*    author:  shinter_pres
*    created: 06.05.2021 12:23:05
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, W;
  cin >> N >> W;
  vector<int> values(N), weights(N);
  rep(i, N) { cin >> values[i] >> weights[i]; }

  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
  rep(i, N) {
    rep(w, W + 1) {
      if (w >= weights[i]) dp[i + 1][w] = max(dp[i + 1][w - weights[i]] + values[i], dp[i][w]);
      else dp[i + 1][w] = dp[i][w];
    }
  }

  cout << dp[N][W] << endl;

  return 0;
}
