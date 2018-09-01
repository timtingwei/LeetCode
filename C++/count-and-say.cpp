// Copyright [2018] <mituh>
// count-and-say.cpp
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

/*
// 栈实现的版本
class Solution {
 public:
  string countAndSay(int n) {
    if (n == 0) return "";
    string ans = "1"; n--;
    stack<char> stk;
    while (n--) {
      string temp;
      int i = 0;
      for (int i = 0; i < ans.length(); i++) {
        if (!stk.empty() && stk.top() != ans[i]) {
          temp += stk.size() + '0';
          temp += stk.top();
          while (!stk.empty()) stk.pop();
        }
        stk.push(ans[i]);
      }
      if (!stk.empty()) {
        temp += stk.size() + '0';
        temp += stk.top();
        while (!stk.empty()) stk.pop();
      }
      ans = temp;
    }
    return ans;
  }

};
*/


// Time:O(n), Space:O(n)
// 指针的版本, for循环中用while跳跃
class Solution {
 public:
  string countAndSay(int n) {
    if (n == 0) return "";
    string res = "1";
    while (--n) {
      string cur = "";
      for (int i = 0; i < res.size(); i++) {
        int cnt = 1;
        while ((i+1 < res.size()) && res[i] == res[i+1]) {
          cnt++;
          i++;
        }
        cur += to_string(cnt) + res[i];
      }
      res = cur;
    }
    return res;
  }
};



int main() {
  Solution solution;
  cout << solution.countAndSay(0) << endl;
  cout << solution.countAndSay(1) << endl;
  cout << solution.countAndSay(2) << endl;
  cout << solution.countAndSay(3) << endl;
  cout << solution.countAndSay(4) << endl;
  cout << solution.countAndSay(10) << endl;
  return 0;
}
