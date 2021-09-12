/*
*    author:  shinter_pres
*    created: 30.04.2021 03:50:01
*/

#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<vector<int>> G;
vector<long long> counts;

void dfs(int v, int p = -1) {
  for (auto next_v: G[v]) {
    if (next_v == p) continue;
    counts[next_v] += counts[v];
    dfs(next_v, v);
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> q;
  G.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    G[a - 1].push_back(b - 1);
    G[b - 1].push_back(a - 1);
  }

  counts.assign(n, 0);
  for (int i = 0; i < q; i++) {
    int p, x;
    cin >> p >> x;
    counts[p - 1] += x;
  }

  dfs(0);

  for (auto cnt: counts) { cout << cnt << " "; }
  cout << endl;

  return 0;
}
