// Copyright [2018] <mituh>
// first-unique-character-in-a-string.cpp
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    char chars[200];
    memset(chars, -1, sizeof(chars));
    for (int i = 0; i < s.length(); i++) {
      cout << "i = " << i << endl;
      if (chars[s[i] - 'a'] == -1) {
        chars[s[i] - 'a'] = i;
      }
    }
    return -1;
  }
};

int main() {
  Solution solution;
  string s1 = "leetcode", s2 = "loveleetcode";
  cout << solution.firstUniqChar(s1) << endl;
  cout << solution.firstUniqChar(s2) << endl;
  return 0;
}
