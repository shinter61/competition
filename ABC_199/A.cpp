/*
*    author:  shinter_pres
*    created: 24.04.2021 20:43:16
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int a, b, c;
  cin >> a >> b >> c;

  if (a*a + b*b < c*c) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
