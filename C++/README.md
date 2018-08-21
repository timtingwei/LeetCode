## LeetCode-cpp

### 26. Remove Duplicates from Sorted Array - LeetCode

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

#### Solution:

```cpp
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
```

```cpp
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
```



i指向当前归并的第一个元素, 初始为0, 用j指针从1开始向左遍历数组, 若j指向与i不同的元素, i后面一个元素赋值为j所指向的元素, (有可能赋值自身)。循环结束时, i是归并后最后一个元素的索引, 返回长度需要+1

```cpp
// Time: O(n), Space: O(1)
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
```

### 122. Best Time to Buy and Sell Stock II - LeetCode

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).


#### Solution:

```cpp
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() == 0 || prices.size() == 1) return 0;
    int profit = 0, flag = 0, min;
    for (int i = 1; i < prices.size(); i++) {
      if (!flag && prices[i] > prices[i-1]) {
        min = prices[i-1]; flag = 1;
      } else if (flag) {
        if (prices[i] < prices[i-1]) {
          profit += prices[i-1] - min; flag = 0;
        } else if (i == prices.size() - 1) {
          profit += prices[i] - min;
        }
      }
    }
    return profit;
  }
};

/*
Wrong answer
Input:
[1,2]
Output:
0
Expected:
1
*/
```

没有注意到判断出最低点时, 当前点已经时最高点的情况.

```cpp
// Time:O(n), Space:O(1)
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() == 0 || prices.size() == 1) return 0;
    int profit = 0, flag = 0, min;
    for (int i = 1; i < prices.size(); i++) {
      if (!flag && prices[i] > prices[i-1]) {
        min = prices[i-1]; flag = 1;
        if (i == prices.size()-1) {
          profit += prices[i] - min;
        }
      } else if (flag) {
        if (prices[i] < prices[i-1]) {
          profit += prices[i-1] - min; flag = 0;
        } else if (i == prices.size() - 1) {
          profit += prices[i] - min;
        }
      }
    }
    return profit;
  }
};
```
    
