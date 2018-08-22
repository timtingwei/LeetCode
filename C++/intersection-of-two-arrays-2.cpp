// Copyright [2018] <mituh>
// intersection-of-two-arrays-2.cpp
#include <iostream>
#include <vector>
using namespace std;

/*
// nums1找到num2中的存在的元素, nums2共同存在的元素删除, nums1不存在元素删除
class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() == 0 || nums2.size() == 0) return {};
    int i = 0;
    while (i < nums1.size()) {
      int exist = 0;
      for (int j = 0; j < nums2.size(); j++) {
        if (nums1[i] == nums2[j]) {
          nums2.erase(nums2.begin() + j);
          exist = 1;
          break;
        }
      }
      if (!exist) {
        nums1.erase(nums1.begin() + i);
      } else {
        i++;
      }
    }
    return nums1;
  }
};

int main() {
  Solution s;
  // vector<int> nums1 = {1, 2, 2, 1};
  // vector<int> nums2 = {2};
  vector<int> nums1 = {4, 9, 5};
  vector<int> nums2 = {9,4,9,8,4};
  s.intersect(nums1, nums2);
  for (int i = 0; i < nums1.size(); i++) {
    cout << nums1[i] << " ";
  }
  cout << endl;
  return 0;
}
*/


// 两个有序数组求交
class Solution {
 public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> ans_v;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] == nums2[j]) {
        ans_v.push_back(nums1[i]); i++; j++;
      } else {
        nums1[i] < nums2[j] ? i++ : j++;
      }
    }
    return ans_v;
  }
};


int main() {
  Solution s;
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 1};
  // vector<int> nums1 = {4, 9, 5};
  // vector<int> nums2 = {9, 4, 9, 8, 4};
  vector<int> nums_rst = s.intersect(nums1, nums2);
  for (int i = 0; i < nums_rst.size(); i++) {
    cout << nums_rst[i] << " ";
  }
  cout << endl;
  return 0;
}
