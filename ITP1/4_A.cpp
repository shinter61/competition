#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  cout << a / b << " " << a % b << " " << fixed << setprecision(6) << (double)a / (double)b << endl;
  return 0;
}
