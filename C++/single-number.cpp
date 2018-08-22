// Copyright [2018] <mituh>
// single-number.cpp
#include <vector>
#include <iostream>
using namespace std;

/*

// Time:O(n^2), Space:O(1);
class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    if (nums.size() == 1) return nums[0];
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int ok = 0;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (nums[i] == nums[j]) {ok = 1; break;}
      }
      if (!ok) return nums[i];
    }
    return 0;
  }
};
*/

// ^异或操作, 两次异或同一数, 结果相同
// Time:O(n), Space:O(1);
class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      ans ^= nums[i];     // 4 ^ 2 ^ 2 ^ 3 ^ 3 = 4 ^ 0 = 4
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums1 = {1, 1, 2};
  vector<int> nums2 = {4, 1, 2, 1, 2};
  vector<int> nums3 = {1};
  vector<int> nums4 = {1, 1, 3, 2, 2};
  cout << s.singleNumber(nums1) << endl;
  cout << s.singleNumber(nums2) << endl;
  cout << s.singleNumber(nums3) << endl;
  cout << s.singleNumber(nums4) << endl;
  return 0;
}
