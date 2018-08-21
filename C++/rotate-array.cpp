// Copyright[2018] <mituh>
// rotate-array.cpp
#include <iostream>
#include <vector>
using namespace std;


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
