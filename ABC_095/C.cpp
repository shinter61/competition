#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  long long min_sum = INT_MAX, tmp;
  min_sum = a * x + b * y;
  for (int i = max(x, y); i >= 0; i--) {
    tmp = a * max(0, (x - i)) + b * max((y - i), 0) + c * i * 2;

    if (tmp < min_sum) min_sum = tmp;
  }

  cout << min_sum << endl;

  return 0;
}
