#include <bits/stdc++.h>
using namespace std;

int main() {
  int w, h, x, y, r;
  cin >> w >> h >> x >> y >> r;

  if (x >= r && w - x >= r && y >= r && h - y >= r) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
