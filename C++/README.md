## LeetCode-cpp

### 48. Rotate Image

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

#### Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

#### Example 1:
```
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
```

#### Example 2:
```
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
```


#### Solution:
```
   1 2 3    7 8 9    7 4 1 
   4 5 6 -> 4 5 6 -> 8 5 2
   7 8 9    1 2 3    9 6 3
```

先将每一行反转, 然后在沿着对角线反转.

```cpp
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size()-1; i++) {
      for (int j = i+1; j < matrix.size(); j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};
```


### 344. Reverse String

Write a function that takes a string as input and returns the string reversed.

#### Example 1:
Input: "hello"
Output: "olleh"

#### Example 2:
Input: "A man, a plan, a canal: Panama"
Output: "amanaP :lanac a ,nalp a ,nam A"

#### Solution:

```cpp
// 创建新串
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
```


```cpp
// 折半交换
// Time: O(n), Space: O(1)
class Solution {
 public:
  string reverseString(string s) {
    int n = s.length();
    for (int i = 0; i <= floor(n/2)-1; i++) {
      char tmp = s[i]; s[i] = s[n-1-i];; s[n-1-i] = tmp;
    }
    return s;
  }
};
```

```cpp
// two pointers
// Time: O(n), Space: O(1)
class Solution {
 public:
  string reverseString(string s) {
    int n = s.length();
    int i = 0, j = n-1;
    while (i < j) {
      int tmp = s[i]; s[i] = s[j]; s[j] = tmp;
      i++; j--;
    }
    return s;
  }
};
```




### 8. String to Integer (atoi)

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

#### Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
#### Example 1:

Input: "42"
Output: 42

#### Example 2:
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
#### Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

#### Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.

#### Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
             
#### Solution:

思路:
> * 1, 除去`' '`, 之前是使用whil循环判断, 可直接用`str.find_first_not_of(' ')`找到第一个非空字符位置
> * 2, 用一个flag标记正负, 如果没有+-号, flag缺省为1
> * 3, ans等于扩大10倍+当前位, 如果溢出就要返回`INT_MIN或者INT_MAX`


错误的几个case
```cpp
/*
// case1
Input:
"+-2"
Output:
2
Expected:
0
*/


/*
// case2
Input:
"2147483648"
Output:
-2147483648
Expected:
2147483647
*/

/*
// case3
Input:
"-91283472332"
Output:
-1089159116
Expected:
-2147483648
*/
```

最后的代码:

```
// Time:O(n), Space:O(1)
class Solution {
 public:
  int myAtoi(string str) {
    long long int ans = 0;                        // case3
    int flag = 1;
    int i = str.find_first_not_of(' ');
    if (str[i] == '-' || str[i] == '+') {         // case1
      flag = (str[i++] == '-') ? -1 : 1;
    }
    while ('0' <= str[i] && str[i] <= '9') {
      ans = ans*10 + (str[i++] - '0');
      if (ans * flag >= INT_MAX) return INT_MAX;  // case2
      if (ans * flag <= INT_MIN) return INT_MIN;
    }
    return ans * flag;
  }
};
```
