// Copyright [2018] <mituh>
// string-to-integer-atoi.cpp

#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int myAtoi(string str) {
    int ans = 0;
    int n = str.length();
    int i = 0;
    while (i < n && str[i] == ' ') i++;
    if (str[i] == '-' ||  str[i] == '+' || isdigit(str[i])) {
      int have = 0, flag = 0;
      if (isdigit(str[i])) {
        have = 0;
      } else {
        if (str[i] == '+') {
          flag = 1;
        } else {
          flag = -1;
        }
      }
      int flag = (str[i] == '-') ? -1 : 1;
      while (i < n && !isdigit(str[i])) i++;    // -+-222 error
      int judge = 0;
      while (i < n && isdigit(str[i])) {
        judge = ans * 10;
        if (judge / 10 != ans) {
          if (flag == -1) {
            return -2147483648;
          } else {
            return 2147483647;
          }
        }
        ans = judge;
        ans += str[i] - '0';
        i++;
      }
      // printf("next char = %c\n", str[i]);
      ans *= flag;
      return ans;
    } else {
      return 0;
    }
  }
};

/*
Input:
"+-2"
Output:
2
Expected:
0
*/

// "42"
// 42

// "   -42"
// -42

// "4193 with words"
// 4193

// "words and 987"
// 0

// "-91283472332"
// -2147483648
/*
Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
*/

int main() {
  Solution solution;
  string s1 = "42.3", s2 = "  30", s3 = "what 2.3", s4 = "-23.3",
      s5 = "-91283472332", s6 = "4193with words";
  cout << solution.myAtoi(s1) << endl;  // 42;
  cout << solution.myAtoi(s2) << endl;  // 30;
  cout << solution.myAtoi(s3) << endl;  // uncaught exception of type
  cout << solution.myAtoi(s4) << endl;  // -23;
  cout << solution.myAtoi(s5) << endl;  // -23;
  cout << solution.myAtoi(s6) << endl;  // -23;

  return 0;
}

