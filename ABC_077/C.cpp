/*
*    author:  shinter_pres
*    created: 23.04.2021 03:53:21
*/

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a, b, c;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  a.resize(n);
  b.resize(n);
  c.resize(n);
  for (int i = 0; i < n; i++) { cin >> a[i]; }
  for (int i = 0; i < n; i++) { cin >> b[i]; }
  for (int i = 0; i < n; i++) { cin >> c[i]; }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  long long sum = 0;
  for (int i = 0; i < n; i++) {
    auto a_itr = lower_bound(a.begin(), a.end(), b[i]);
    long long a_idx = a_itr - a.begin();
    auto c_itr = upper_bound(c.begin(), c.end(), b[i]);
    long long c_idx = c_itr - c.begin();

    sum += a_idx * (n - c_idx);
  }

  cout << sum << endl;

  return 0;
}
