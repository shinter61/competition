/*
*    author:  shinter_pres
*    created: 01.05.2021 21:39:16
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  vector<long long> a, b, c, d, e;

  int n;
  cin >> n;
  a.resize(n);
  b.resize(n);
  c.resize(n);
  d.resize(n);
  e.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
  }

  auto a_itr = max_element(a.begin(), a.end());
  auto b_itr = max_element(b.begin(), b.end());
  auto c_itr = max_element(c.begin(), c.end());
  auto d_itr = max_element(d.begin(), d.end());
  auto e_itr = max_element(e.begin(), e.end());


  vector<int> kouho;
  for (int i = 0; i < n; i++) {
    auto result = find(kouho.begin(), kouho.end(), i);
    if (result != kouho.end()) continue;
    if (a[i] == *a_itr) {
      kouho.push_back(i);
      continue;
    }
    if (b[i] == *b_itr) {
      kouho.push_back(i);
      continue;
    }
    if (c[i] == *c_itr) {
      kouho.push_back(i);
      continue;
    }
    if (d[i] == *d_itr) {
      kouho.push_back(i);
      continue;
    }
    if (e[i] == *e_itr) {
      kouho.push_back(i);
      continue;
    }
  }

  for (int i = 0; i < kouho.size(); i++) {
    cout << "kouho: " << i << endl;
  }

  return 0;
}
