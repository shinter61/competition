/*
*    author:  shinter_pres
*    created: 30.04.2021 13:02:58
*/

#include <bits/stdc++.h>

using namespace std;

int h, w, ans = 0;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

void dfs(int ch, int cw, vector<vector<int>> &field, vector<vector<bool>> &seen, vector<vector<int>> &depth) {
  seen[ch][cw] = true;

  for (int dir = 0; dir < 4; dir++) {
    int next_h = ch + dy[dir];
    int next_w = cw + dx[dir];

    if (next_h < 0 || next_h >= h || next_w < 0 || next_w >= w) continue;
    if (field[next_h][next_w] == 0) continue;
    if (seen[next_h][next_w]) continue;

    if (depth[ch][cw] > depth) {

    } else {
      depth[next_h][next_w] += depth[ch][cw];
    }

    dfs(next_h, next_w, field, seen, depth);
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> w;
  cin >> h;

  vector<vector<int>> field(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> field[i][j];
    }
  }

  vector<vector<bool>> seen(h, vector<bool>(w, false));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (seen[i][j]) continue;
      if (field[i][j] == 0) continue;

      vector<vector<int>> depth(h, vector<int>(w, 1));
      dfs(i, j, field, seen, depth);

      int zantei = 0;
      if (zantei > ans) ans = zantei;
    }
  }

  cout << ans << endl;

  return 0;
}
