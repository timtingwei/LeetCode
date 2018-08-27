// Copyright[2018] <mituh>
// reverse-integer.cpp


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// 123,  321
// -123, -321
// 120,  21
class Solution {
 public:
  int reverse(int x) {
    // cout << "x = " << x << endl;
    if (x < pow(-2, 31) || x > pow(2, 31) - 1) return 0;
    vector<int> nums;
    while (x) {
      nums.push_back(x % 10);
      x /= 10;
    }
    int ans = 0, n = nums.size();
    for (int i = n-1; i >= 0; i--) {
      int d = pow(10, i) * nums[n-1-i];
      printf("d = %d\n", d);
      if (d % 10 == 0 || d == 1 || d == -1) {
        // ..
        if ((ans > pow(2, 31) - 1 - d) || (ans < pow(-2, 31) - d))
          return 0;
        ans += d;
      } else {
        return 0;
      }
      // cout << "ans = " << ans << endl;
      // if (ans < pow(-2, 31) || ans > pow(2, 31) - 1) return 0;
    }
    return ans;
  }
};
/*
Input:
1534236469
Output:
-1501159297
Expected:
0
*/
/*
Input:
1563847412
Output:
-2147483645
Expected:
0
*/

/*
Input:
900000
Output:
0
Expected:
9
*/

int main() {
  Solution solution;
  int x1 = 123, x2 = -123, x3 = 120, x4 = 1534236469, x5 = 1563847412;
  int x6 = 900000;
  cout << solution.reverse(x1) << endl;
  cout << solution.reverse(x2) << endl;
  cout << solution.reverse(x3) << endl;
  cout << solution.reverse(x4) << endl;
  cout << solution.reverse(x5) << endl;
  cout << solution.reverse(x6) << endl;
  return 0;
}

