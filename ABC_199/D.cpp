/*
*    author:  shinter_pres
*    created: 24.04.2021 21:37:25
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> seen;

long long dfs(vector< vector<int> > &G, int v) {
  if (v == n) return 1; // 存在しないn+1番目の頂点に来たときは、掛け算でansを増やしていくために1を返すようにする

  if (G[v].empty()) return dfs(G, v + 1) * 3; // 孤立点の場合

  long long ans = 0;
  for (int i = 0; i < 3; i++) {
    bool flg = false;
    for (auto next_v: G[v]) {
      if (seen[next_v] == i) { 
        cout << "next_v: " << next_v << " v: " << v << " i: " << i << endl;
        flg = true; break; 
      } // 同じ色の隣接点がある場合スキップする
    }
    if (flg) continue;
    seen[v] = i;
    ans += dfs(G, v + 1);
    seen[v] = -1; // ?
  }

  cout << "v: " << v << " ans: " << ans << endl;
  return ans;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  vector< vector<int> > G(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  seen.assign(n, -1);
  cout << dfs(G, 0) << endl;

  return 0;
}
