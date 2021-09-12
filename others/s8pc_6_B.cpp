/*
*    author:  shinter_pres
*    created: 20.04.2021 11:19:23
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  vector<long long> aa(n);
  vector<long long> bb(n);
  for (int i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    aa[i] = a;
    bb[i] = b;
  }

  long long min_time = __LONG_LONG_MAX__;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      long long zantei_time = 0;
      for (int k = 0; k < n; k++) {
        zantei_time += labs(aa[k] - aa[i]) + labs(bb[k] - aa[k]) + labs(bb[j] - bb[k]);
      }
      if (zantei_time < min_time) {
        min_time = zantei_time;
      }
    }
  }

  cout << min_time << endl;

  return 0;
}
