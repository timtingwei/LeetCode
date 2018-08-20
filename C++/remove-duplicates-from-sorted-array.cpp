// Copyright [2018] <mituh>
// remove-duplicates-from-sorted-array.cpp
// Time:O(n), Space:O(1)

#include <iostream>
#include <vector>
using namespace std;

/*
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
};  // 实现了一个蠢萌版本
*/

/*
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return n;

    int j = 1;
    for (int i = 1; i < n; i++) {
      if (nums[i] != nums[j-1]) {
        int tmp = nums[i]; nums[i] = nums[j]; nums[j] = tmp;
        j++;
      }
    }
    return j;
  }
};  // 精简了几个指针, 只对数组做一遍的扫描, Time:O(n), Space:O(1), 但不用交换赋值就可以
*/

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
      if (nums[j] != nums[i]) {
        i++;
        nums[i] = nums[j];
      }
    }
    return i+1;
  }
};
// i指向当前归并的第一个元素, 初始为0, 用j指针从1开始向左遍历数组, 若j指向与
// i不同的元素, i后面一个元素赋值为j所指向的元素, (有可能赋值自身)
// 循环结束时, i是归并后最后一个元素的索引, 返回长度需要+1

int main() {
  Solution solution;
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 5};
  // vector<int> nums = {-3,-3,-2,-1,-1,0,0,0,0,0};
  // vector<int> nums = {};
  int len = solution.removeDuplicates(nums);
  cout << len << endl;
  for (int i = 0; i < len; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
  return 0;
}
