#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  vector < vector<int> > edges;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    vector<int> edge(2);
    cin >> edge[0] >> edge[1];
    edges.push_back(edge);
  }

  vector<int> nums(n);
  iota(nums.begin(), nums.end(), 1);
  int cnt = 0;
  do {
    if (nums[0] != 1) continue;
    vector<bool> exists(n - 1, false);
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        if (edges[j][0] == nums[i] && edges[j][1] == nums[i + 1]) exists[i] = true;
        if (edges[j][1] == nums[i] && edges[j][0] == nums[i + 1]) exists[i] = true;
      }
    }

    bool ok = true;
    for (auto exist: exists) {
      if (!exist) ok = false;
    }

    if (ok) {
      cnt++;
    }
  } while (next_permutation(nums.begin(), nums.end()));

  cout << cnt << endl;

  return 0;
}
