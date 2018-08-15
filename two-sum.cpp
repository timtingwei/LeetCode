// Copyright [2018] <mituh>
#include <vector>
#include <iostream>
using namespace std;

/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

/*
class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    static vector<int> ans;
    int N = nums.size();
    for (int i = 0; i < N; i++) {
      for (int j = i+1; j < N; j++) {
        if (nums[i] + nums[j] == target) {
          ans.push_back(i);
          ans.push_back(j);
          return {i, j};
        }
      }
    }
    return {};
  }
};
*/


// two pointers解法, 排序O(N^2)不稳定, two pointers O(n);
class Solution {
 public:
  void exch(vector<int> &a, int i, int j) {
    int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
  }

  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> rank;
    int N = nums.size();
    for (int i = 0; i < N; i++) { rank.push_back(i); }
    for (int i = 1; i < N; i++) {
      for (int j = i; j > 0 && nums[j] < nums[j-1]; j--) {
        exch(nums, j, j-1);
        exch(rank, j, j-1);
      }
    }
    int i = 0, j = nums.size() - 1;
    while (i < j) {
      if (nums[i] + nums[j] == target) {
        return {rank[i], rank[j]};
      } else if (nums[i] + nums[j] < target) {
        i++;
      } else if (nums[i] + nums[j] > target) {
        j--;
      }
    }
    return {};
  }
};




int main() {
  Solution solution;
  // vector<int> nums = {2, 7, 11, 15};
  vector<int> nums = {3, 2, 4};
  int target = 6;
  vector<int> rst = solution.twoSum(nums, target);
  for (int i = 0; i < rst.size(); i++) {
    cout << rst[i] << " ";
  }
  cout << endl;
  return 0;
}
