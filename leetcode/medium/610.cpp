/*
*    author:  shinter_pres
*    created: 15.07.2021 15:38:35
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

class Solution {
  public:
    int triangleNumber(vector<int>& nums) {
      int ans;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
          auto itr = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]);
          int idx = itr - nums.begin() - 1;

          if (idx - j > 0) {
            // cout << nums[i] << " " << nums[j] << " " << idx - j << endl;
            ans += idx - j;
          }
        }
      }
      return ans;
    }
};

int main() {
  vector<int> nums{2,2,3,4};
  Solution().triangleNumber(nums);
  return 0;
}
