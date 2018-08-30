// Copyright [2018] <mituh>
// valid-palindrome.cpp
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

/*
// Time:O(n), Space:O(n)
class Solution {
 public:
  bool isPalindrome(string s) {
    if (s.length() == 0) return true;
    string t;
    for (char c : s) {
      if (isdigit(c) || isalpha(c)) {
        t += tolower(c);
      }
    }
    // cout << "t = " << t << endl;
    int n = t.length();
    for (int i = 0; i <= n/2; i++) {
      if (t[i] != t[n-1-i]) return false;
    }
    return true;
  }
};
*/

// Time:O(n), Space:O(1)
// two pointers, in-place
class Solution {
 public:
  bool  isPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
      while (isalnum(s[i]) == false && i < j) i++;
      while (isalnum(s[j]) == false && i < j) j--;
      if (tolower(s[i]) != tolower(s[j])) return false;
      i++;
      j--;
    }
    return true;
  }
};

int main() {
  Solution solution;
  string s1 = "A man, a plan, a canal: Panama";
  string s2 = "race a car";
  cout << solution.isPalindrome(s1) << endl;
  cout << solution.isPalindrome(s2) << endl;
  return 0;
}
