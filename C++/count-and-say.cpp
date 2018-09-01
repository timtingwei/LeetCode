// Copyright [2018] <mituh>
// count-and-say.cpp
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

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


int main() {
  Solution solution;
  cout << solution.countAndSay(0) << endl;
  cout << solution.countAndSay(1) << endl;
  cout << solution.countAndSay(2) << endl;
  cout << solution.countAndSay(3) << endl;
  cout << solution.countAndSay(4) << endl;
  cout << solution.countAndSay(5) << endl;
  return 0;
}
