/*
*    author:  shinter_pres
*    created: 05.05.2021 05:00:25
*/

// ABC007-Cのコピー

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, 1, 0, -1};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int w, h, sy, sx, gy, gx;
  cin >> h >> w;
  cin >> sy >> sx;
  cin >> gy >> gx;
  sy--; sx--; gy--; gx--;

  vector<vector<char>> fields(h, vector<char>(w));
  vector<vector<int>> dist(h, vector<int>(w, -1));
  queue<pair<int, int>> que;

  rep(i, h) {
    rep(j, w) {
      char cij;
      cin >> cij;
      fields[i][j] = cij;
    }
  }

  dist[sy][sx] = 0;
  que.push(make_pair(sy, sx));

  while (!que.empty()) {
    pair<int, int> v = que.front();
    que.pop();

    rep(i, 4) {
      pair<int, int> next_v = make_pair(v.first + dy[i], v.second + dx[i]);
      if (next_v.first < 0 || next_v.first >= h || next_v.second < 0 || next_v.second >= w) continue;
      if (fields[next_v.first][next_v.second] == '#') continue;
      if (dist[next_v.first][next_v.second] != -1) continue;

      dist[next_v.first][next_v.second] = dist[v.first][v.second] + 1;
      que.push(next_v);
    }
  }

  cout << dist[gy][gx] << endl;

  return 0;
}
