/*
*    author:  shinter_pres
*    created: 24.04.2021 06:01:14
*/

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> heights, speeds;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  heights.resize(n);
  speeds.resize(n);
  for (int i = 0; i < n; i++) { cin >> heights[i] >> speeds[i]; }
  long long left = 0;
  long long right = LLONG_MAX;

  while(right - left > 1) {
    long long mid = (left + right) / 2;
    bool flag = true;
    vector<long long> t(n);
    for (int i = 0; i < n; i++) {
      if (mid < heights[i]) flag = false;
      else t[i] = (mid - heights[i]) / speeds[i];
    }

    sort(t.begin(), t.end());
    for (int i = 0; i < n; i++) { if (t[i] < i) flag = false; }

    if (flag) right = mid;
    else left = mid;
  }

  cout << right << endl;

  return 0;
}
