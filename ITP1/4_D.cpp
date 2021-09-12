#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < x.size(); i++) {
    cin >> x[i];
  }
  long max = -2000000, min = 2000000, sum = 0;
  for (int i = 0; i < x.size(); i++) {
    if (max < x[i]) {
      max = x[i];
    }
    if (min > x[i]) {
      min = x[i];
    }

    sum += x[i];
  }

  cout << min << " " << max << " " << sum << endl;
  return 0;
}
