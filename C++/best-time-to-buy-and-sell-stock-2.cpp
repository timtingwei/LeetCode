// Copyright [2018] <mituh>
// best-time-to-buy-and-sell-stock-2.cpp
// Time:O(n), Space:O(1)
#include <iostream>
#include <vector>
using namespace std;
/*
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
*/


/*
Wrong answer
Input:
[1,2]
Output:
0
Expected:
1
*/

// 没有注意到判断出最低点时, 当前点已经时最高点的情况

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


int main() {
  Solution s;
  // vector<int> prices = {7, 1, 5, 3, 6, 4};   // 7
  // vector<int> prices = {1, 2, 3, 4, 5};      // 4
  // vector<int> prices = {7, 6, 4, 3, 1};      // 0
  vector<int> prices = {1, 2};                 // 1
  int ans = s.maxProfit(prices);
  printf("profit = %d\n", ans);
  return 0;
}
