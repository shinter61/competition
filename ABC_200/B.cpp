/*
*    author:  shinter_pres
*    created: 08.05.2021 20:49:44
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  long long n, k;
  cin >> n >> k;

  rep(i, k) {
    if (n % 200 == 0) {
      n /= 200;
    } else {
      n = n * 1000 + 200;
    }
  }

  cout << n << endl;

  return 0;
}
