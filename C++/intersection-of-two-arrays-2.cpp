// Copyright [2018] <mituh>
// intersection-of-two-arrays-2.cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() == 0 || nums2.size() == 0) {
      return {};
    }
    for (int i = 0; i < nums1.size(); i++) {
      int exist = 0;
      for (int j = 0; j < nums2.size(); j++) {
        // if (i == j) continue;
        if (nums1[i] == nums2[j]) {
          nums2.erase(nums2.begin() + j);
          exist = 1;
          break;
        }
      }
      printf("exist = %d, i = %d\n", exist, i);
      if (!exist) nums1.erase(nums1.begin() + i);
    }
    return nums1;
  }
};

/*
Input:
[1,2,2,1]
[2]
Output:
[2,2]
Expected:
[2]
*/


int main() {
  Solution s;
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2};
  s.intersect(nums1, nums2);
  for (int i = 0; i < nums1.size(); i++) {
    cout << nums1[i] << " ";
  }
  cout << endl;
  return 0;
}
