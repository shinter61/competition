/*
*    author:  shinter_pres
*    created: 24.04.2021 20:43:43
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) { cin >> a[i]; }
  for (int i = 0; i < n; i++) { cin >> b[i]; }

  int left = INT_MIN, right = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (a[i] > left) left = a[i];
    if (b[i] < right) right = b[i];
  }

  if (left > right) {
    cout << 0 << endl;
  } else {
    cout << right - left + 1 << endl;
  }

  return 0;
}
