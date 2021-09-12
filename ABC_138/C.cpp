/*
*    author:  shinter_pres
*    created: 30.04.2021 12:51:16
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<double> guzai(n);
  for (int i = 0; i < n; i++) { cin >> guzai[i]; }

  sort(guzai.begin(), guzai.end());
  while (guzai.size() >= 2) {
    double new_guzai =(guzai[0] + guzai[1]) / 2;
    guzai.erase(guzai.begin());
    guzai.erase(guzai.begin());
    guzai.push_back(new_guzai);
    sort(guzai.begin(), guzai.end());
  }

  cout << guzai[0] << endl;

  return 0;
}
