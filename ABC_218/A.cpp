/*
*    author:  shinter_pres
*    created: 11.09.2021 20:40:55
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  string s;
  cin >> n;
  cin >> s;

  if (s[n-1] == 'o') {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
