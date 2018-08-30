// Copyright[2018] <mituh>
// reverse-integer.cpp


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// 123,  321
// -123, -321
// 120,  21

struct Bign {
  int d[1005];
  int len;
  Bign() {
    memset(d, 0, sizeof(d));
    len = 0;
  }
};

Bign change(int x) {
  Bign a;
  int flag = 0;
  if (x < 0) {
    x = -x;
    flag = 1;
  }
  while (x) {
    a.d[a.len++] = x % 10;
    x /= 10;
  }
  if (flag) {
    a.d[a.len-1] *= -1;
  }
  return a;
}

void show(Bign a) {
  for (int i = a.len-1; i >= 0; i--) {
    cout << a.d[i];
  }
  cout << endl;
}

int compare(Bign a, Bign b) {
  if (a.d[a.len-1] * b.d[b.len-1] < 0) {
    if (a.d[a.len-1] < 0) {
      return -1;
    } else {
      return 1;
    }
  }
  if (a.d[a.len-1] > 0) {
    if (a.len < b.len) return -1;
    else if (a.len > b.len) return 1;
    else {
      for (int i = 0; i < a.len; i++) {
        if (a.d[i] < b.d[i]) return -1;
        else if (a.d[i] > b.d[i]) return 1;
      }
      return 0;
    }
  } else if (a.d[a.len-1] < 0) {
    if (a.len < b.len) return 1;
    else if (a.len > b.len) return -1;
    else {
      for (int i = 0; i < a.len; i++) {
        if (a.d[i] < b.d[i]) return 1;
        else if (a.d[i] > b.d[i]) return -1;
      }
      return 0;
    }
  }
  return 0;
}

class Solution {
 public:
  int reverse(int x) {
    Bign a = change(x);
    Bign lower = change(pow(-2, 31)), upper = change(pow(2, 31)-1);
    if (compare(a, lower) < 0 || compare(a, upper) > 0) {
      return 0;
    }
    return 0;
  }
};


int main() {
  Bign a = change(pow(2, 31)-1), b = change(pow(-2, 31));
  Bign a1 = change(-1), b1 = change(-2);
  show(a1);
  show(b1);
  cout << "rst = " << compare(a1, b1) << endl;
  return 0;
}

/*
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
*/
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


/*
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

*/
