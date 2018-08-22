// Copyright [2018] <mituh>
// plus-one.cpp
// Time:O(n), Space:O(1)
#include <iostream>
#include <vector>
using namespace std;

// 先后两遍扫描
// 从右开始向左计算, 当前位置满10修改成0, 左位置+1.
// 若首位10, vector尾部添加0, 首位修改成0, 中间添0
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

int main() {
  vector<int> nums1 = {1, 2, 3};
  vector<int> nums2 = {0};
  vector<int> nums3 = {9};
  plusOne()
  return 0;
}
