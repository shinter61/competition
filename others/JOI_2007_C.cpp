/*
*    author:  shinter_pres
*    created: 20.04.2021 04:10:43
*/

#include <bits/stdc++.h>

using namespace std;

bool is_in_area(int x) {
  return x <= 5000 && x >= 0;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector< vector<int> > pillers(n, vector<int>(2));
  vector< vector<bool> > coordinates(5001, vector<bool>(5001));
  for (int i = 0; i < n; i++) {
    cin >> pillers[i][0] >> pillers[i][1];
    coordinates[pillers[i][0]][pillers[i][1]] = true;
  }

  int max_s = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;

      int diff_x = abs(pillers[i][0] - pillers[j][0]);
      int diff_y = abs(pillers[i][1] - pillers[j][1]);
      vector<int> s(2), t(2);
      s[0] = pillers[i][0] + diff_y;
      s[1] = pillers[i][1] + diff_x;
      t[0] = pillers[j][0] + diff_y;
      t[1] = pillers[j][1] + diff_x;
      if (is_in_area(s[0]) && is_in_area(s[1]) && is_in_area(t[0]) && is_in_area(t[1])) {
        if (coordinates[s[0]][s[1]] && coordinates[t[0]][t[1]]) {
          int zantei_s = pow(pillers[i][0] - pillers[j][0], 2) + pow(pillers[i][1] - pillers[j][1], 2);
          if (zantei_s > max_s) max_s = zantei_s;
        }
      }

      s[0] = pillers[i][0] - diff_y;
      s[1] = pillers[i][1] - diff_x;
      t[0] = pillers[j][0] - diff_y;
      t[1] = pillers[j][1] - diff_x;
      if (is_in_area(s[0]) && is_in_area(s[1]) && is_in_area(t[0]) && is_in_area(t[1])) {
        if (coordinates[s[0]][s[1]] && coordinates[t[0]][t[1]]) {
          int zantei_s = pow(pillers[i][0] - pillers[j][0], 2) + pow(pillers[i][1] - pillers[j][1], 2);
          if (zantei_s > max_s) max_s = zantei_s;
        }
      }
    }
  }

  cout << max_s << endl;

  return 0;
}
