/*
*    author:  shinter_pres
*    created: 30.04.2021 01:36:13
*/

#include <bits/stdc++.h>

using namespace std;

const int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

void dfs(vector<vector<int> > &field, int ch, int cw, vector<vector<bool> > &seen, int h, int w) {
  seen[ch][cw] = true;

  for (int dir = 0; dir < 8; dir++) {
    int nh = ch + dy[dir];
    int nw = cw + dx[dir];

    if (nh < 0 || nh >= h || nw < 0 || nw >= w) continue; // 場外ならskip
    if (field[nh][nw] == 0) continue; // 海ならskip

    if (seen[nh][nw]) continue; // 探索済ならskip

    dfs(field, nh, nw, seen, h, w);
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  vector< tuple<int, int, vector<vector<int> > > > inputs;

  while(true) {
    int w, h;
    cin >> w >> h;

    if (w == 0 && h == 0) break;

    vector< vector<int> > field(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> field[i][j];
      }
    }
    inputs.push_back(make_tuple(h, w, field));
  }

  for (int tuple_cnt = 0; tuple_cnt < inputs.size(); tuple_cnt++) {
    int h = get<0>(inputs[tuple_cnt]);
    int w = get<1>(inputs[tuple_cnt]);
    vector<vector<int> > field = get<2>(inputs[tuple_cnt]);

    int island = 0;
    vector<vector<bool> > seen(h, vector<bool>(w, false));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (seen[i][j]) continue;
        if (field[i][j] == 0) continue;
        island++;
        dfs(field, i, j, seen, h, w);
      }
    }

    cout << island << endl;
  }

  return 0;
}
