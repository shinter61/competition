/*
*    author:  shinter_pres
*    created: 05.05.2021 03:27:35
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<vector<int>> G(n);

  rep(i, n) {
    int id, k;
    cin >> id >> k;
    rep(j, k) {
      int vk;
      cin >> vk;
      G[id - 1].push_back(vk - 1);
    }
  }

  vector<int> dist(n, -1);
  queue<int> que;

  dist[0] = 0;
  que.push(0);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (auto next_v: G[v]) {
      if (dist[next_v] != -1) continue;

      dist[next_v] = dist[v] + 1;
      que.push(next_v);
    }
  }

  rep(i, n) {
    cout << i + 1 << " " << dist[i] << endl;
  }

  return 0;
}
