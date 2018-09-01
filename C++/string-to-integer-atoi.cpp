// Copyright [2018] <mituh>
// string-to-integer-atoi.cpp

#include <iostream>
#include <string>
using namespace std;

/*
class Solution {
 public:
  int myAtoi(string str) {
    int ans = 0, judge = 0;
    int n = str.length();
    int i = 0;
    while (i < n && str[i] == ' ') i++;
    int cnt = 0, flag = 1;
    while (str[i] == '-' || str[i] == '+') {
      if (str[i] == '-') flag = -1;
      i++; cnt++;
    }
    if (isdigit(str[i]) && (cnt == 0 || cnt == 1)) {     // error: what2.3
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
      ans *= flag;
    }
    return ans;
  }
};
*/


/*
Input:
"+-2"
Output:
2
Expected:
0
*/


/*
Input:
"2147483648"
Output:
-2147483648
Expected:
2147483647
*/


// Time:O(n), Space:O(1)
class Solution {
 public:
  int myAtoi(string str) {
    long long int ans = 0;
    int flag = 1;
    int i = str.find_first_not_of(' ');
    if (str[i] == '-' || str[i] == '+') {
      flag = (str[i++] == '-') ? -1 : 1;
    }
    while ('0' <= str[i] && str[i] <= '9') {
      ans = ans*10 + (str[i++] - '0');
      if (ans * flag >= INT_MAX) return INT_MAX;
      if (ans * flag <= INT_MIN) return INT_MIN;
    }
    return ans * flag;
  }
};

int main() {
  Solution solution;
  string s1 = "42.3", s2 = "  30", s3 = "what 2.3", s4 = "-23.3",
      s5 = "-91283472332", s6 = "4193with words", s7 = "-+-212",
      s8 = "2147483648";
  cout << solution.myAtoi(s1) << endl;  // 42;
  cout << solution.myAtoi(s2) << endl;  // 30;
  cout << solution.myAtoi(s3) << endl;  // 0
  cout << solution.myAtoi(s4) << endl;  // -23;
  cout << solution.myAtoi(s5) << endl;  // -2147483648
  cout << solution.myAtoi(s6) << endl;  // 4193
  cout << solution.myAtoi(s7) << endl;  // 0
  cout << solution.myAtoi(s8) << endl;  // -2147483648

  return 0;
}
