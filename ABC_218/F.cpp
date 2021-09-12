/*
*    author:  shinter_pres
*    created: 11.09.2021 21:54:17
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges(m);
  rep(i, m) {
    int s, t;
    cin >> s >> t;
    edges[i] = {s-1, t-1};
  }

  rep(i, m) {
    vector<vector<int>> graph(n);
    rep(j, m) {
      if (i == j) continue;
      graph[edges[j].first].push_back(edges[j].second);
    }

    vector<int> dist(n, -1);
    queue<int> que;

    dist[0] = 0;
    que.push(0);

    while (!que.empty()) {
      int v = que.front();
      que.pop();

      for (auto next_v: graph[v]) {
        if (dist[next_v] != -1) continue;
        dist[next_v] = dist[v] + 1;
        que.push(next_v);
      }
    }

    cout << dist[n-1] << endl;
  }

  return 0;
}
