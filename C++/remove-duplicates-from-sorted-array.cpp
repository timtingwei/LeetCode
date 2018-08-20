// Copyright [2018] <mituh>
// remove-duplicates-from-sorted-array.cpp

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return n;
    int i = 0;
    while (i < n) {
      int j = i + 1;
      while (j < n && nums[j] == nums[j-1]) j++;
      n -= j - i- 1;
      for (int p = i+1, q = 0; q < n; p++, q++) {
        nums[p] = nums[j+q];
      }
      i++;
    }
    return n;
  }
};

int main() {
  Solution solution;
  // vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 5};
  // vector<int> nums = {-3,-3,-2,-1,-1,0,0,0,0,0};
  vector<int> nums = {};
  int len = solution.removeDuplicates(nums);
  cout << len << endl;
  for (int i = 0; i < len; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
  return 0;
}
