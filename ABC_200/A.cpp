/*
*    author:  shinter_pres
*    created: 08.05.2021 20:49:46
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, d, a;
  cin >> n;

  d = n / 100;
  a = n % 100;
  if (a != 0) {
    cout << d + 1 << endl;
  } else {
    cout << d << endl;
  }

  return 0;
}
