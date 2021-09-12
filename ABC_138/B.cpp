/*
*    author:  shinter_pres
*    created: 30.04.2021 12:48:32
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<double> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  double bunbo = 0;
  for (int i = 0; i < n; i++) {
    bunbo += 1 / a[i];
  }

  cout << 1 / bunbo << endl;

  return 0;
}
