/*
*    author:  shinter_pres
*    created: 01.05.2021 21:00:17
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  int ans = 0;
  for (int i = 0; i < 12; i++) {
    if (s[i] == 'Z' && s[i+1] == 'O' && s[i+2] == 'N' && s[i+3] == 'e') ans++;
  }

  cout << ans << endl;

  return 0;
}
