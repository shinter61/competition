/*
*    author:  shinter_pres
*    created: 29.04.2021 05:30:49
*/

#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > G;
vector<bool> seen;
int timestamp = 1;
vector<int> first_order;
vector<int> last_order;

void dfs(int v) {
  first_order[v] = timestamp++;
  seen[v] = true;

  for (int i = 0; i < G[v].size(); i++) {
    int next_v = G[v][i] - 1;
    if (seen[next_v]) continue;
    dfs(next_v);
  }

  last_order[v] = timestamp++;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  G.resize(n);
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    vector<int> vs(k);
    for (int j = 0; j < k; j++) {
      cin >> vs[j];
    }
    G[u - 1] = vs;
  }

  seen.assign(n, false);
  first_order.resize(n);
  last_order.resize(n);
  for (int i = 0; i < n; i++) {
    if (seen[i]) continue;
    dfs(i);
  }

  for (int i = 0; i < n; i++) {
    cout << i + 1 << ' ' << first_order[i] << ' ' << last_order[i] << endl;
  }

  return 0;
}
