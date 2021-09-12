#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector< vector<long long> > a(n, vector<long long>(m));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].size(); j++) {
      cin >> a[i][j];
    }
  }

  long long sum = 0;
  for (int s = 0; s < m; s++) {
    for (int t = 0; t < m; t++) {
      if (s == t) continue;
      long long zantei = 0;
      for (int i = 0; i < a.size(); i++) {
        zantei += max(a[i][s], a[i][t]);
      }
      if (zantei > sum) sum = zantei;
    }
  }

  cout << sum << endl;
  return 0;
}
