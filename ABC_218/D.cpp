/*
*    author:  shinter_pres
*    created: 11.09.2021 21:14:46
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<pair<int, int>> coods(n);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    coods[i] = {x, y};
  }

  sort(coods.begin(),coods.end());

  int count = 0;
  rep(i, n) {
    vector<int> same_x_ys, same_y_xs;
    for (int j = i+1; j < n; j++) {
      if (coods[j].first == coods[i].first) {
        same_x_ys.push_back(coods[j].second);
      }
      if (coods[j].second == coods[i].second) {
        same_y_xs.push_back(coods[j].first);
      }
    }

    // cout << "----------------------" << endl;
    // rep(j, same_y_xs.size()) cout << same_y_xs[j] << " ";
    // cout << endl;
    // rep(j, same_x_ys.size()) cout << same_x_ys[j] << " ";
    // cout << endl;


    for (int j = 0; j < same_x_ys.size(); j++) {
      for (int k = 0; k < same_y_xs.size(); k++) {
        int target_y = same_x_ys[j], target_x = same_y_xs[k];
        // cout << target_x << " " << target_y << endl;
        for (int l = i; l < n; l++) {
          // cout << coods[l].first << " " << coods[l].second << endl;
          if (coods[l].first == target_x && coods[l].second == target_y) { count++; break; }
        }
      }
    }
  }

  cout << count << endl;

  return 0;
}
