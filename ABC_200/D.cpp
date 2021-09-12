/*
*    author:  shinter_pres
*    created: 08.05.2021 21:14:45
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void rec(vector<vector<int>> &dp, vector<long long> &a, int i, int j, deque<long long> &keiro, vector<deque<long long>> &ans) {
  if (i == 0) {
    if (j == 0) {
        ans.push_back(keiro);
    }
    return;
  }

  // 上へ遡る (dp[i-1][j] == 0) だったら無視)
  if (dp[i-1][j] > 0) {
      rec(dp, a, i-1, j, keiro, ans);
  }
  // 左上へ遡る (dp[i-1][j-a[i-1]] == 0 だったら無視)
  if (j >= a[i - 1]) {
    if (dp[i-1][j-a[i-1]] > 0) {
        keiro.push_front(a[i-1]);
        rec(dp, a, i-1, j-a[i-1], keiro, ans);
        keiro.pop_front();
    }
  } else {
    if (dp[i-1][200-abs(j-a[i-1])] > 0) {
        keiro.push_front(a[i-1]);
        rec(dp, a, i-1, j-a[i-1], keiro, ans);
        keiro.pop_front();
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<long long> a(n);
  rep(i, n) {
    long long ai;
    cin >> ai;
    a[i] = ai % 200; 
  }

  vector<vector<int>> dp(210, vector<int>(210, 0));
  dp[0][0] = 1;
  rep(i, n) {
    rep(j, 200) {
      if (j >= a[i]) {
        dp[i+1][j] = dp[i][j - a[i]] + dp[i][j];
      } else {
        dp[i+1][j] = dp[i][200 - abs(j - a[i])] + dp[i][j];
      }
    }
  }

  int amari = -1;
  rep(i, 200) {
    if (dp[n][i] >= 2) {
      amari = i;
      break;
    }
  }

  if (amari < 0) {
    cout << "no" << endl;
    return 0;
  }

  // 復元
  deque<long long> keiro;
  vector<deque<long long>> ans;
  rec(dp, a, n, amari, keiro, ans);

  cout << "yes" << endl;
  cout << "the num of combinations is: " << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
      cout << i+1 << " case:";
      for (auto el : ans[i]) cout << " " << el;
      cout << endl;
  }


  return 0;
}
