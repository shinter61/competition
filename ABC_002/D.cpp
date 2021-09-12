/*
*    author:  shinter_pres
*    created: 20.04.2021 19:26:15
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector< vector<bool> > kankei(12, vector<bool>(12, false));

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    kankei[x][y] = true;
    kankei[y][x] = true;
  }

  vector< vector<int> > patterns(1<<n);
  for (int bit = 0; bit < (1<<n); bit++) {
    vector<int> s;
    for (int i = 0; i < n; i++) {
      if (bit & (1<<i)) {
        s.push_back(i);
      }
    }
    patterns.push_back(s);
  }

  int max_cnt = 1;
  for (auto pattern: patterns) {
    if (pattern.size() == 0) continue;
    bool ok = true;
    for (auto giin_i: pattern) {
      for (auto giin_j: pattern) {
        if (giin_i == giin_j) continue;
        if (kankei[giin_i][giin_j] && kankei[giin_j][giin_i]) continue;
        ok = false;
      }
    }

    int pattern_size = pattern.size();
    if (ok) max_cnt = max(max_cnt, pattern_size);
  }

  cout << max_cnt << endl;

  return 0;
}
