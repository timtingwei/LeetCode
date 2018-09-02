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
*/

// 更为简洁的版本
class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    string res = "";
    for (int idx = 0; strs.size() > 0; res += strs[0][idx], idx++) {
      for (int i = 0; i < strs.size(); i++) {
        if (idx >= strs[i].length() ||
            (i > 0 && strs[i][idx] != strs[i-1][idx]))
          return res;
      }
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
