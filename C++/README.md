## LeetCode-cpp

### 136. Single Number

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#### Example 1:

Input: [2,2,1]
Output: 1

#### Example 2:
Input: [4,1,2,1,2]
Output: 4

#### Solution:


两遍遍历的方法:
```cpp
// Time:O(n^2), Space:O(1);
class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    if (nums.size() == 1) return nums[0];
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int ok = 0;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (nums[i] == nums[j]) {ok = 1; break;}
      }
      if (!ok) return nums[i];
    }
    return 0;
  }
};
```


异或操作的做法,
```cpp
// ^异或操作, 两次异或同一数, 结果相同
// Time:O(n), Space:O(1);
class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      ans ^= nums[i];     // 4 ^ 2 ^ 2 ^ 3 ^ 3 = 4 ^ 0 = 4
    }
    return ans;
  }
};
```

```sh
a ^ b   // 如果a, b相同, 则0; 如果不同则1
```

将两两相同的数字合并, 运算后只得到剩下的一个single number




### 350. Intersection of Two Arrays II

Given two arrays, write a function to compute their intersection.

#### Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

#### Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

#### Note:

Each element in the result should appear as many times as it shows in both arrays.

The result can be in any order.

#### Solution:

nums1找到num2中的存在的元素, nums2共同存在的元素删除, nums1不存在元素删除.

```cpp
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
```


#### Follow up:

1, What if the given array is already sorted? How would you optimize your algorithm?


```cpp
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
```



### 66. One Plus

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

#### Example 1:
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

#### Example 2:
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.


#### Solution:

先后两遍扫描,
从右开始向左计算, 当前位置满10修改成0, 左位置+1.
若首位10, vector尾部添加0, 首位修改成0, 中间添0.

```cpp
class Solution {
 public:
  vector<int> plusOne(vector<int> &digits) {
    int n = digits.size();
    int i = n; digits[--i]++;
    while (digits[i] == 10 && i > 0) {
      digits[i] = 0;
      digits[--i]++;
    }
    if (digits[0] == 10) {
      digits.push_back(0);
      digits[0] = 1;
      for (int j = 1; j < n; j++) digits[j] = 0;
    }

    return digits;
  }
};
```


### 283. Move Zeroes

```cpp
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
```
