// Copyright[2018] <mituh>
// move-zeroes.cpp
// Time:O(n^2), Space:O(1)

// 从右向左找到0, 用j标记位置, i交换到尾部, 找到下一个0, 交换到尾部之前的位置.
// Time:O(n^2), Space:O(1)
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    
    int n = nums.size();
    int i = n-1, j;
    while (i >= 0) {
      if (nums[i] == 0) {
        while (i < n-1) {
          swap(nums[i], nums[i+1]); i++;
        }
        n--;
        i = j;
      }
      i--;
    }
  }
};

// 考虑一种能够将0直接和尾部对应位置交换, 然后再交换前面元素序列的做法

