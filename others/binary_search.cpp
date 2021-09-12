/*
*    author:  shinter_pres
*    created: 21.04.2021 14:22:56
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> s, t;

int binary_search(int key) {
  int left = 0;
  int right = s.size() - 1;
  while(right >= left) {
    int middle = left + (right - left) / 2;
    if (s[middle] == key) return middle;
    else if (s[middle] > key) right = middle - 1;
    else if (s[middle] < key) left = middle + 1;
  }
  return -1;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n, q;
  cin >> n;
  s.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  cin >> q;
  t.resize(q);
  for (int i = 0; i < q; i++) {
    cin >> t[i];
  }

  int cnt = 0;
  for (int i = 0; i < t.size(); i++) {
    int idx = binary_search(t[i]);
    if (idx != -1) cnt++;
  }
  cout << cnt << endl;

  return 0;
}
