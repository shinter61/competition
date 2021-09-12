/*
*    author:  shinter_pres
*    created: 15.07.2021 15:38:35
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

class Solution {
  public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
      vector<int> ans(nums.size(), -1);
      rep(i, nums.size()) {
        if (ans[index[i]] == -1) {
          ans[index[i]] = nums[i];
        } else {
          for (int j = nums.size() - 2; j >= index[i]; j--) {
            ans[j+1] = ans[j];
          }
          ans[index[i]] = nums[i];
        }

        rep(j, ans.size()) {
          cout << ans[j] << " ";
        }
        cout << endl;
      }

      return ans;
    }
};

int main() {
  vector<int> nums{0,1,2,3,4}, index{0,1,2,2,1};
  Solution().createTargetArray(nums, index);
  return 0;
}
