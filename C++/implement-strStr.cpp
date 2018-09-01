// Copyright [2018] <mituh>
// implement-strStr.cpp
// 03:56, 16:23

#include <iostream>
#include <string>
using namespace std;

/*
// Time:O(n*m), Space:O(1)
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int n = haystack.length(), m = needle.length();
    if (!m) return 0;

    int i = 0, j = 0;
    while (i < n) {
      if (haystack[i] == needle[j]) {
        int ok = 1, k = i;
        while (k < n && j < m) {
          if (haystack[k++] != needle[j++]) {
            ok = 0; break;
          }
        }
        if (ok && j == m && k <= n)
          return i;
        j = 0;
      }
      i++;
    }
    return -1;
  }

};
*/


// Time:O(n*m), Space:O(1)
class Solution {
 public:
  int strStr(string haystack, string needle) {
    for (int i = 0; ; i++) {
      for (int j = 0; ; j++) {
        if (j == needle.length()) return i;
        if (i+j == haystack.length()) return -1;
        if (haystack[i+j] != needle[j]) break;
      }
    }
  }
};


/*
// 第一个版本的简化版本
// Time:O(n*m), Space:O(1)
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int n = haystack.length(), m = needle.length();
    if (!m) return 0;

    int i = 0, j = 0;
    while (i <= n-m) {
      if (haystack[i] == needle[j]) {
        while (j < m && haystack[i+j] == needle[j]) j++;
        if (j == m) return i;
        j = 0;
      }
      i++;
    }
    return -1;
  }
};
*/

int main() {
  Solution solution;
  string h1 = "hello", n1 = "ll",
      h2 = "aaaaa",    n2 = "bba",
      h3 = "aaa",      n3 = "";
  cout << solution.strStr(h1, n1) << endl;
  cout << solution.strStr(h2, n2) << endl;
  cout << solution.strStr(h3, n3) << endl;
  return 0;
}

