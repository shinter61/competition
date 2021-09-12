/*
*    author:  shinter_pres
*    created: 20.04.2021 17:33:59
*/

#include <bits/stdc++.h>

using namespace std;

int m, n;
vector< pair<int, int> > stars(0);
vector< pair<int, int> > seiza(0);

bool is_in_range(int x) {
  return x >= 0 && x <= 1000000;
}

bool find(int x, int y) {
  bool found = false;
  for (int i = 0; i < n; i++) {
    if (stars[i].first == x && stars[i].second == y) {
      found = true;
      break;
    }
  }

  return found;
}

bool check(
  int dep,
  int diff_x,
  int diff_y
) {
  // cout << "depth = " << dep << endl;
  if (dep == m) return true;
  // cout << "(seiza_m_x, seiza_m_y) = (" << seiza[dep].first << ", " << seiza[dep].second << ")" << endl;
  // cout << "(x, y) = (" << seiza[dep].first + diff_x << ", " << seiza[dep].second + diff_y << ")" << endl;
  if (is_in_range(seiza[dep].first + diff_x) && is_in_range(seiza[dep].second + diff_y) && find(seiza[dep].first + diff_x, seiza[dep].second + diff_y)) {
    return check(dep + 1, diff_x, diff_y);
  } else {
    return false;
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> m;
  seiza.resize(m);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    seiza[i] = make_pair(x, y);
  }
  cin >> n;
  stars.resize(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    stars[i] = make_pair(x, y);
  }

  int ans_x = 0, ans_y = 0;
  for (auto star: stars) {
    int diff_x, diff_y;
    diff_x = star.first - seiza[0].first;
    diff_y = star.second - seiza[0].second;
    // cout << "(target_x, target_y) = (" << star.first << "," << star.second << ")" << endl;
    // cout << "(diff_x, diff_y) = (" << diff_x << "," << diff_y << ")" << endl;
    bool is_seiza_start = check(0, diff_x, diff_y);
    // cout << "is_seiza_start = " << is_seiza_start << endl;
    if (is_seiza_start) {
      ans_x = diff_x; ans_y = diff_y;
      break;
    }
  }

  cout << ans_x << " " << ans_y << endl;

  return 0;
}
