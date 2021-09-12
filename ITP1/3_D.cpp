#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> nums(b - a + 1);
  iota(nums.begin(), nums.end(), a);

  int cnt = 0;
  for (auto num : nums) {
    if (c % num == 0) ++cnt;
  }

  cout << cnt << endl;
  return 0;
}
