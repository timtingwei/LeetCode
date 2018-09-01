// Copyright [2018] <mituh>
// longest-common-prefix.cpp

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    string res = "";

    for (int i = 0; ; i++) {
      int ok = 1;
      char pChar = strs[0][i];
      for (int j = 1; j < strs.size(); j++) {
        if (strs[j][i] != pChar) {
          ok = 0;
          break;
        }
        if (i == strs[j].size()) return res;
      }
      if (ok) {
        res += pChar;
      }
    }
    return res;
  }

};
*/

class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    string res = "";

    for (int i = 0; strs.size() > 0; i++) {
      for (int j = 0; j < strs.size(); j++) {
        if ((i >= strs[j].size()) ||  (j > 0 && strs[j][i] != strs[j-1][i])) {
          return res;
        }
      }
      res += strs[0][i];
    }
    return res;
  }

};


int main() {
  Solution solution;
  vector<string> str1 = {"flower", "flow", "flight"};
  vector<string> str2 = {"dog", "racecar", "car"};
  cout << solution.longestCommonPrefix(str1) << endl;
  cout << solution.longestCommonPrefix(str2) << endl;

  return 0;
}
