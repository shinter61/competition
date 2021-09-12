/*
*    author:  shinter_pres
*    created: 21.04.2021 08:28:22
*/

#include <bits/stdc++.h>

using namespace std;

bool is_in_range(int x) {
  return x >= 0 && x <= 7;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int k;
  cin >> k;
  vector< pair<int, int> > input_queens(k);
  for (int i = 0; i < k; i++) {
    int r, c;
    cin >> r >> c;
    input_queens[i] = make_pair(r, c);
  }

  vector<int> cols(8);
  for (int i = 1; i <= 8; i++) {
    cols[i - 1] = i;
  }
  do {
    vector< vector<bool> > field(8, vector<bool>(8, false));
    vector< pair<int, int> > queens;
    for (int i = 0; i < cols.size(); i++) {
      field[i][cols[i] - 1] = true;
      queens.push_back(make_pair(i, cols[i] - 1));
    }

    bool ok = true;
    for (int i = 0; i < input_queens.size(); i++) {
      if (!field[input_queens[i].first][input_queens[i].second]) ok = false;
    }
    if (!ok) continue;

    vector< vector<bool> > naname_field(8, vector<bool>(8, false));
    for (int i = 0; i < queens.size(); i++) {
      for (int j = 1; j < 8; j++) {
        if (is_in_range(queens[i].first - j) && is_in_range(queens[i].second - j)) {
          naname_field[queens[i].first - j][queens[i].second - j] = true;
        }
        if (is_in_range(queens[i].first + j) && is_in_range(queens[i].second + j)) {
          naname_field[queens[i].first + j][queens[i].second + j] = true;
        }
        if (is_in_range(queens[i].first - j) && is_in_range(queens[i].second + j)) {
          naname_field[queens[i].first - j][queens[i].second + j] = true;
        }
        if (is_in_range(queens[i].first + j) && is_in_range(queens[i].second - j)) {
          naname_field[queens[i].first + j][queens[i].second - j] = true;
        }
      }
    }

    for (int i = 0; i < queens.size(); i++) {
      if (naname_field[queens[i].first][queens[i].second]) ok = false;
    }
    if (!ok) continue;

    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        string output = field[i][j] ? "Q" : ".";
        cout << output;
      }
      cout << endl;
    }
  } while(next_permutation(cols.begin(), cols.end()));

  return 0;
}
