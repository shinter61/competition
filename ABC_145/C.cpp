#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector< vector<int> > coordinates(0);
  for (int i = 0; i < n; ++i) {
    vector<int> input(2);
    cin >> input[0] >> input[1];
    coordinates.push_back(input);
  }
  double sum = 0;
  int cnt = 0;
  vector<int> nums(n);
  iota(nums.begin(), nums.end(), 1);
  do {
    for (int i = 0; i < n - 1; ++i) {
      vector<int> current;
      vector<int> next;
      current = coordinates[nums[i] - 1];
      next = coordinates[nums[i + 1] - 1];
      sum += sqrt(pow(current[0] - next[0], 2) + pow(current[1] - next[1], 2));
    }
    cnt++;
  } while(next_permutation(nums.begin(), nums.end()));

  cout << fixed << setprecision(10) <<  sum / cnt << endl;

  return 0;
}
