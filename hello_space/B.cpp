/*
*    author:  shinter_pres
*    created: 01.05.2021 21:02:51
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  double d, h;
  cin >> n >> d >> h;
  vector<pair<double, double>> objects(n);
  for (int i = 0; i < n; i++) {
    double Di, Hi;
    cin >> Di >> Hi;
    objects[i] = make_pair(Di, Hi);
  }

  double max_height = 0;
  for (auto object: objects) {
    double zantei = 0;
    if (d == object.first) {
      zantei = object.second;
    } else {
      double a = (h - object.second) / (d - object.first);
      zantei = h - a * d;
    }

    if (zantei > max_height) max_height = zantei;
  }

  cout << max_height << endl;

  return 0;
}
