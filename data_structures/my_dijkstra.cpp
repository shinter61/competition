#include <iostream>
#include <queue>
#include <vector>
#include <utility>

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A

using namespace std;
using P = pair<int, int>;

const int inf = 1e9;

int main() {
  // This part is entrying of data.
  int v, e, r;
  cin >> v >> e >> r;
  vector<vector<P>> edges(v);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    edges[s].push_back({d, t});
  }

  // Initializing distance from a starting point.
  vector<int> dist(v, inf);
  dist[r] = 0;

  // Using decending.
  priority_queue<P, vector<P>, greater<P>> pq; // Sort by cost.
  pq.push({0, r}); // Search from a starting point.

  // Loop until search queue become empty
  while (!pq.empty()) {
    P now = pq.top();
    int node = now.second; 
    pq.pop();
    for (P edge: edges[node]) {
      int next = edge.second, cost = edge.first;
      if (dist[node] + cost >= dist[next]) continue;
      dist[next] = dist[node] + cost;
      pq.push(edge);
    }
  }

  // Show results
  for (int i = 0; i < dist.size(); i++) {
    if (dist[i] == inf) {
      cout << "INF" << endl;
    } else {
      cout << dist[i] << endl;
    }
  }

  return EXIT_SUCCESS;
}
