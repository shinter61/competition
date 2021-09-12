/*
*    author:  shinter_pres
*    created: 20.04.2021 21:33:30
*/

#include <bits/stdc++.h>

using namespace std;

int r, c;
vector< vector<int> > senbeis(0);

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> r >> c;
  senbeis.resize(r);
  for (int i = 0; i < r; i++) {
    senbeis[i].resize(c);
    for (int j = 0; j < c; j++) {
      cin >> senbeis[i][j];
    }
  }

  vector< vector<bool> > r_patterns(1<<r, vector<bool>(r, false));
  for (int bit = 0; bit < (1<<r); bit++) {
    for (int i = 0; i < r; i++) {
      if (bit & (1<<i)) {
        r_patterns[bit][i] = true;
      }
    }
  }

  int max = 0;
  for (auto pattern: r_patterns) {
    vector< vector<int> > senbeis_copy = senbeis;

    for (int i = 0; i < senbeis_copy.size(); i++) {
      if (pattern[i]) {
        for (int j = 0; j < senbeis_copy[i].size(); j++) {
          senbeis_copy[i][j] = senbeis_copy[i][j] == 1 ? 0 : 1;
        }
      } else {
        continue;
      }
    }

    int border = r % 2 == 0 ? (r / 2) : (r / 2 + 1);
    vector<int> tates(c);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (senbeis_copy[i][j] == 1) tates[j]++;
      }
    }

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (tates[j] >= border) senbeis_copy[i][j] = senbeis_copy[i][j] == 1 ? 0 : 1;
      }
    }

    int zantei_cnt = 0;
    for (int i = 0; i < senbeis_copy.size(); i++) {
      for (int j = 0; j < senbeis_copy[i].size(); j++) {
        if (senbeis_copy[i][j] == 0) zantei_cnt++;
      }
    }
    if (zantei_cnt > max) max = zantei_cnt;
  }

  cout << max << endl;

  return 0;
}
