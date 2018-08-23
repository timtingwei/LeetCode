// Copyright [2018] <mituh>
// reverse-string.cpp
#include <iostream>
#include <string>
using namespace std;

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

int main() {
  Solution s;
  string str = "hello";
  cout << s.reverseString(str) << endl;
  return 0;
}
