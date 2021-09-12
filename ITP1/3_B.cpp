#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> x(10000);
  for (int i = 0; i < x.size(); i++) {
    cin >> x[i];
    if (x[i] == 0) break;
  }
  for (int i = 0; i < x.size(); i++) {
    if (x[i] == 0) break;
    cout << "Case " << i + 1 << ": " << x[i] << endl;
  }
  return 0;
}
