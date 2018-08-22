// Copyright [2018] <mituh>
// contains-duplicate.cpp
// Time:O(n*logn), Space:O(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
// 两遍扫描, Time:O(n), Spcae:O(1)
class Solution {
 public:
  bool containsDuplicate(vector<int> &nums) {
    if (nums.size() == 1 || nums.size() == 0) return 0;
    int n = nums.size();
    for (int i = 0; i < n-1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[i] == nums[j]) return 1;
      }
    }
    return 0;
  }
};
*/


// 先排序, 对排序后的的数组1开始的元素, 检查前一个元素是否相等。
// Time:O(n*logn), Space:O(1)
class Solution {
 public:
  bool containsDuplicate(vector<int> &nums) {
    if (nums.size() == 1 || nums.size() == 0) return 0;

    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i-1]) return 1;
    }
    return 0;
  }
};


int main() {
  Solution s;
  vector<int> nums1 = {0, 1, 2, 2, 2, 1, 5};
  vector<int> nums2 = {0, 1, 2, 3, 4, 5};
  vector<int> nums3 = {0, 1, 1};
  vector<int> nums4 = {0};
  vector<int> nums5 = {};
  cout << s.containsDuplicate(nums1) << endl;
  cout << s.containsDuplicate(nums2) << endl;
  cout << s.containsDuplicate(nums3) << endl;
  cout << s.containsDuplicate(nums4) << endl;
  cout << s.containsDuplicate(nums5) << endl;
  return 0;
}
