/*
*    author:  shinter_pres
*    created: 05.05.2021 07:00:27
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int w, h;
  cin >> w >> h;
  vector<vector<int>> fields(h, vector<int>(w));
  rep(i, h) {
    rep(j, w) {
      cin >> fields[i][j];
    }
  }

  return 0;
}
