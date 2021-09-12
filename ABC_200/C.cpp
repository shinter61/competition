/*
*    author:  shinter_pres
*    created: 08.05.2021 20:49:41
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<long long> amari(200, 0);
  rep(i, n) {
    long long ai;
    cin >> ai;
    amari[ai % 200]++;
  }


  long long ans = 0;
  rep(i, 200) {
    if (amari[i] < 2) continue;
    ans += amari[i] * (amari[i] - 1) / 2;
  }

  cout << ans << endl;

  return 0;
}
