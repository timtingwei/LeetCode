// Copyright[2018] <mituh>
// rotate-array.cpp
#include <iostream>
#include <vector>
using namespace std;

/*
// Time:O(n), Space:O(n);
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    if (nums.size() == 0 || k == 0 || k % nums.size() == 0) return;
    vector<int> v;
    int n = nums.size();
    for (int i = k; i < k+n; i++) {
      v.push_back(nums[i % n]);
    }
    nums = v;
  }
};  // 方向问题, 但可以实现
*/


/*
// Time:O(n^2), Space:O(1);
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n-1; j++) {
        int tmp = nums[j]; nums[j] = nums[j+1]; nums[j+1] = tmp;
      }
    }
  }
};  // 从左往右写反
*/

/*
// Time:O(n^2), Space:O(1);
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    for (int i = 0; i < k; i++) {
      for (int j = n-1; j > 0; j--) {
        int tmp = nums[j]; nums[j] = nums[j-1]; nums[j-1] = tmp;
      }
    }
  }
};  // 改成从右往左

// 但是Time Limit Exceeded
*/

/*
// Time:   Space:O(n)
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    if (nums.size() == 0 || k == 0 || k % nums.size() == 0)
      return;
    int n = nums.size(), m = k % n;

    for (int i = n-m; i <= n-1; i++) {
      for (int j = i; j > i-(n-m); j--) {
        int tmp = nums[j]; nums[j] = nums[j-1]; nums[j-1] = tmp;
      }
    }
  }
};  // 改成从右往左, 添加数组为空, k为零的情况, 求余也为0的情况
*/



int main() {
  Solution s;
  vector<int> nums1 = {0, 1, 2, 3, 4};
  vector<int> nums2 = {0, 1};
  vector<int> nums3 = {};
  int k = 2;
  s.rotate(nums1, k);
  for (int i = 0; i < nums1.size(); i++) cout << nums1[i] << " ";
  cout << endl;

  s.rotate(nums2, k);
  for (int i = 0; i < nums2.size(); i++) cout << nums2[i] << " ";
  cout << endl;

  s.rotate(nums3, k);
  for (int i = 0; i < nums3.size(); i++) cout << nums3[i] << " ";
  cout << endl;
  return 0;
}
