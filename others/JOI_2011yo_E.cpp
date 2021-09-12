/*
*    author:  shinter_pres
*    created: 05.05.2021 05:35:24
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, 1, 0, -1};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int h, w, n;
  cin >> h >> w >> n;
  vector<vector<char>> fields(h, vector<char>(w));
  vector<pair<int, int>> goals(n + 1);
  rep(i, h) {
    rep(j, w) {
      char cij;
      cin >> cij;
      fields[i][j] = cij;

      if (cij == 'S') goals[0] = make_pair(i, j);
      if (cij - '0' >= 1) goals[cij - '0'] = make_pair(i, j);
    }
  }

  int sum = 0;
  rep (i, n) {
    vector<vector<int>> dict(h, vector<int>(w, -1));
    queue<pair<int, int>> que;
    pair<int, int> start = goals[i];
    pair<int, int> goal = goals[i + 1];

    dict[start.first][start.second] = 0;
    que.push(start);
    while (!que.empty()) {
      pair<int, int> v = que.front();
      que.pop();

      rep(j, 4) {
        pair<int, int> next_v = make_pair(v.first + dy[j], v.second + dx[j]);
        if (next_v.first < 0 || next_v.first >= h || next_v.second < 0 || next_v.second >= w) continue;
        if (fields[next_v.first][next_v.second] == 'X') continue;
        if (dict[next_v.first][next_v.second] != -1) continue;

        dict[next_v.first][next_v.second] = dict[v.first][v.second] + 1;
        que.push(next_v);
      }
    }

    sum += dict[goal.first][goal.second];
  }

  cout << sum << endl;

  return 0;
}
