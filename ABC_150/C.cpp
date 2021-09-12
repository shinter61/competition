#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> q(n);
  int p_rank, q_rank, cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> q[i];
  }
  
  vector<int> nums(n);
  iota(nums.begin(), nums.end(), 1);
  do {
    cnt++;
    bool p_match = true;
    bool q_match = true;
    for (int i = 0; i < n; i++) {
      if (nums[i] != p[i]) p_match = false;
      if (nums[i] != q[i]) q_match = false;
    }
    if (p_match) p_rank = cnt;
    if (q_match) q_rank = cnt;
  } while (next_permutation(nums.begin(), nums.end()));

  cout << abs(p_rank - q_rank) << endl;

  return 0;
}
