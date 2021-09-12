/*
*    author:  shinter_pres
*    created: 11.09.2021 20:40:57
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  vector<int> a(26);
  for (int i = 0; i < 26; i++) cin >> a[i];

  string s = "";
  for (int i = 0; i < 26; i++) {
    s += ('a' + (a[i] - 1));
  }
  cout << s << endl;

  return 0;
}
