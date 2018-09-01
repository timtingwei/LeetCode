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




### 8. String to Integer (atoi) -u

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

### 28. Implement strStr() -u

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

#### Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
#### Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

#### Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's [strstr()](http://www.cplusplus.com/reference/cstring/strstr/) and Java's [indexOf()](https://docs.oracle.com/javase/7/docs/api/java/lang/String.html#indexOf(java.lang.String)).

#### Solution1:

two pointers, 放在while循环中

```cpp
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
```



#### Solution2:

for循环, j作为needle的下标, i作为判断的头指针, i+j是haystack的下标,
> * 1, 若两个指针指向的字符不同, 推出内层循环；
> * 2, 如果j能够在上述条件下, 到达哨兵位置, 表明完全匹配;
> * 3, 如果i+j到了haystack的哨兵位置, 扫描结束, 未找到;

```cpp
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
```


根据这个思路, 对Solution1进行简化, 
> * 用达到哨兵位置取代对ok变量的操作;
> * 用i+j取代新增的k变量;
> * i的范围在n-m之内.

```cpp
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
```

### 38. Count and Say -u
The count-and-say sequence is the sequence of integers with the first five terms as following:
```
1.     1
2.     11
3.     21
4.     1211
5.     111221
```
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

#### Note: Each term of the sequence of integers will be represented as a string.

#### Example 1:
Input: 1
Output: "1"

#### Example 2:
Input: 4
Output: "1211"

#### Solution1:

用栈实现, 从低递推, 扫描一遍, 不同的数字将栈清空并加入到字符串中; 注意最后若非空栈也需要清空一次.

```cpp
class Solution {
 public:
  string countAndSay(int n) {
    if (n == 0) return "";
    string ans = "1"; n--;
    stack<char> stk;
    while (n--) {
      string temp;
      int i = 0;
      for (int i = 0; i < ans.length(); i++) {
        if (!stk.empty() && stk.top() != ans[i]) {
          temp += stk.size() + '0';
          temp += stk.top();
          while (!stk.empty()) stk.pop();
        }
        stk.push(ans[i]);
      }
      if (!stk.empty()) {
        temp += stk.size() + '0';
        temp += stk.top();
        while (!stk.empty()) stk.pop();
      }
      ans = temp;
    }
    return ans;
  }

};
```


#### Solution2:

在for循环中, 循环体中改变i是可行的; for语句执行的顺序是
```
for (进入循环之前的定义和声明等; 循环体执行条件; 循环体执行后的变量改变) {
    // 循环体
}
```

因此, 在内部改变i, 可以使得只扫描一次.

```cpp
// Time:O(n), Space:O(n)
// 指针的版本, for循环中用while跳跃
class Solution {
 public:
  string countAndSay(int n) {
    if (n == 0) return "";
    string res = "1";
    while (--n) {
      string cur = "";
      for (int i = 0; i < res.size(); i++) {
        int cnt = 1;
        while ((i+1 < res.size()) && res[i] == res[i+1]) {
          cnt++;
          i++;
        }
        cur += to_string(cnt) + res[i];
      }
      res = cur;
    }
    return res;
  }
};
```


### 14. Longest Common Prefix -u

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

#### Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

#### Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

#### Note:
All given inputs are in lowercase letters a-z.


#### Solution:

注意向量为空的情况

```cpp
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

```
