#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  vector< vector<int> > switches(m);
  vector<int> conditions(m, 0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int switch_count;
    cin >> switch_count;
    switches[i].resize(switch_count);
    for (int j = 0; j < switch_count; j++) {
      cin >> switches[i][j];
      --switches[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> conditions[i];
  }

  vector< vector<int> > patterns(1<<n);
  for (int bit = 0; bit < (1<<n); ++bit) {
    for (int i = 0; i < n; ++i) {
      if (bit & (1<<i)) {
        patterns[bit].push_back(i);
      }
    }
  }

  int cnt = 0;
  for (auto pattern: patterns) {
    bool all_shined = true;
    for (int i = 0; i < m; ++i) {
      int shined_cnt = 0;
      for (auto s: switches[i]) {
        for (auto p: pattern) {
          if (s == p) ++shined_cnt;
        }
      }

      if (shined_cnt % 2 != conditions[i]) all_shined = false;
    }

    if (all_shined) ++cnt;
  }

  cout << cnt << endl;

  return 0;
}
