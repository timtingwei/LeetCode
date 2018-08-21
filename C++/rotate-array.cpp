// Copyright[2018] <mituh>
// rotate-array.cpp
#include <iostream>
#include <vector>
using namespace std;

/*
// Time:O(n), Space:O(1);
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    vector<int> v;
    int n = nums.size();
    for (int i = k; i < n + k; i++) {
      v.push_back(nums[i % n]);
    }
    nums = v;
    // return v;
  }
};
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

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size(), p = k % n;
    for (int i = 0; i < p; i++) {
      for (int j = n - p; j <= n-1; j++) {
        for (int q = j; q > j - p; j--) {
          int tmp = nums[q]; nums[q] = nums[q-1]; nums[q-1] = tmp;
        }
      }
    }
  }
};  // 改成从右往左




int main() {
  Solution s;
  vector<int> nums1 = {0, 1, 2, 3};
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
