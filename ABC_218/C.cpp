/*
*    author:  shinter_pres
*    created: 11.09.2021 20:40:59
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using G = vector<string>;

G rotate(int n, G &g) {
  string s = "";
  rep(i, n) s += ".";
  G copy(n, s);


  rep(i, n) {
    rep(j, n) {
      copy[j][n-i-1] = g[i][j];
    }
  }

  // rep(i, n) {
  //   cout << copy[i] << endl;
  // }
  // cout << "-------------" << endl;


  return copy;
}

G move(int n, int x, int y, G &g) {
  string s = "";
  rep(i, n) s += ".";
  G copy(n, s);

  rep(i, n) {
    if (i+y>=n || i+y < 0) continue;
    rep(j, n) {
      if (j+x>=n || j+x <0) continue;
      copy[i][j] = g[i+y][j+x];
    }
  }

  return copy;
}

bool check(int n, G &s, G &t) {
  bool flag = true;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      flag = false;
      break;
    }
  }

  return flag;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  G s(n), t(n);
  for (int i = 0; i < n; i++) { cin >> s[i]; }
  for (int i = 0; i < n; i++) { cin >> t[i]; }

  bool flag = false;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < i; j++) {
      s = rotate(n, s);
    }

    for (int x = -n; x < n; x++) {
      for (int y = -n; y < n; y++) {
        s = move(n, x, y, s);
      }
    }

    rep(i, n) {
      cout << s[i] << endl;
    }

    if (check(n, s, t)) { flag = true; break; }
  }


  cout << (flag ? "Yes" : "No") << endl;

  return 0;
}
