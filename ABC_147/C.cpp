#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector< vector<int> > comments(0);
  for (int i = 1; i <= n; ++i) {
    int com_cnt =0;
    cin >> com_cnt;
    for (int j = 0; j < com_cnt; ++j) {
      vector<int> comment(3);
      cin >> comment[0] >> comment[1];
      comment[2] = i;
      comments.push_back(comment);
    }
  }

  vector < vector<int> > patterns(1<<n);
  for (int bit = 0; bit < (1<<n); ++bit) {
    for (int i = 0; i < n; ++i) {
      if (bit & (1<<i)) patterns[bit].push_back(i + 1);
    }
  }

  int cnt_max = 0;
  for (vector<int> pattern: patterns) {
    bool mujun = false;

    for (int i = 0; i < comments.size(); ++i) {
      vector<int> comment = comments[i];
      bool target_shojiki = false;
      bool origin_shojiki = false;
      for (int j = 0; j < pattern.size(); j++) {
        // 発言の対象が正直者かどうか
        if (comment[0] == pattern[j]) target_shojiki = true;
        // 発言者が正直者かどうか
        if (comment[2] == pattern[j]) origin_shojiki = true;
      }
      if (origin_shojiki && comment[1] == 1 && !target_shojiki) mujun = true;
      if (origin_shojiki && comment[1] == 0 && target_shojiki) mujun = true;
    }

    if (!mujun && pattern.size() > cnt_max)  cnt_max = pattern.size();
  }

  cout << cnt_max << endl;

  return 0;
}
