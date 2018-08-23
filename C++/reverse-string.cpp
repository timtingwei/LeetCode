// Copyright [2018] <mituh>
// reverse-string.cpp
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
// 创建新串
// Time:O(n), Space:O(n);
class Solution {
 public:
  string reverseString(string s) {
    string str;
    for (int i = s.length()-1; i >= 0; i--) {
      str += s[i];
    }
    return str;
  }
};
*/


/*
// 折半交换
// Time: O(n), Space: O(1)
class Solution {
 public:
  string reverseString(string s) {
    int n = s.length();
    for (int i = 0; i <= floor(n/2)-1; i++) {
      char tmp = s[i]; s[i] = s[n-1-i];; s[n-1-i] = tmp;
    }
    return s;
  }
};
*/

// two pointers
// Time: O(n), Space: O(1)
class Solution {
 public:
  string reverseString(string s) {
    int n = s.length();
    int i = 0, j = n-1;
    while (i < j) {
      int tmp = s[i]; s[i] = s[j]; s[j] = tmp;
      i++; j--;
    }
    return s;
  }
};

int main() {
  Solution s;
  string str = "A man, a plan, a canal: Panama";
  cout << s.reverseString(str) << endl;
  return 0;
}
