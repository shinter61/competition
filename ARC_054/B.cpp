/*
*    author:  shinter_pres
*    created: 26.04.2021 08:01:29
*/

#include <bits/stdc++.h>

using namespace std;

long double p;

long double bibun(long double x) {
  return (1 - p * log(2) * pow(2, -x / 1.5) / 1.5);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> p;
  long double left = 0;
  long double right = p;
  long double middle;
  while(right - left > 1e-8) {
    middle = (left + right) / 2;
    if (bibun(middle) > 0) right = middle;
    else left = middle;
  }

  cout << fixed << setprecision(8) <<  middle + p * pow(2, -middle/1.5) << endl;

  return 0;
}
