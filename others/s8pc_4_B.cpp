/*
*    author:  shinter_pres
*    created: 21.04.2021 01:39:04
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;
vector<ll> buildings;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    buildings.push_back(a);
  }

  vector< vector<bool> > patterns(1<<n, vector<bool>(n, false));
  for (int i = 0; i < (1<<n); i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1<<j)) {
        patterns[i][j] = true;
      }
    }
  }

  long long sum_min = 1LL<<40;
  for (auto pattern: patterns) {
    vector<long long> buildings_copy = buildings;
    long long cost = 0;
    int colors = 0;
    int maxh = 0;

    for (int i = 0; i < n; i++) {
      if (maxh < buildings_copy[i]) {
        maxh = buildings_copy[i];
        colors++;
      } else {
        if (pattern[i]) {
          cost += (maxh - buildings_copy[i] + 1);
          maxh++;
          colors++;
        }
      }
    }

    if (colors >= k) sum_min = min(sum_min, cost);
  }
  cout << sum_min << endl;

  return 0;
}

