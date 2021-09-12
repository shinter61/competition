#include <bits/stdc++.h>
using namespace std;

int f(long long a, long long b) {
  long long max = a > b ? a : b;
  return to_string(max).length();
}

int main() {
  long long n;
  cin >> n;
  int min_f = INT_MAX, tmp;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      tmp = f(i, n / i);
      if (tmp < min_f) min_f = tmp;
    }
  }

  cout << min_f << endl;

  return 0;
}
