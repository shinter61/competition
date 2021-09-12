#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) continue;
    int cnt = 0;
    for (int j = 1; j <= i; j++) {
      if (i % j == 0) cnt++;
    }
    if (cnt == 8) sum++;
  }

  cout << sum << endl;

  return 0;
}
