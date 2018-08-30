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


### 7. Reverse Integer -u

Given a 32-bit signed integer, reverse digits of an integer.

#### Example 1:
Input: 123
Output: 321
#### Example 2:
Input: -123
Output: -321

#### Example 3:
Input: 120
Output: 21

#### Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.


#### Solution:

不需要重新写大整数类
> * 1, 位数*10代表着升位。
> * 2, 可通过乘10再除以10是否相等来判断是否溢出

AC的解法:
```cpp
class Solution {
 public:
  int reverse(int x) {
    int result = 0, judge = 0;
    while (x) {
      judge = result * 10;
      if (judge / 10 != result) {
        return 0;
      }
      result = judge;
      result += x % 10;
      x /= 10;
    }
    return result;
  }
};
```


之前错误百出的解法:
```cpp
class Solution {
 public:
  int reverse(int x) {
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
        if ((ans > pow(2, 31) - 1 - d) || (ans < pow(-2, 31) - d))
          return 0;
        ans += d;
      } else {
        return 0;
      }
      // if (ans < pow(-2, 31) || ans > pow(2, 31) - 1) return 0;
    }
    return ans;
  }
};
```


### 387. First Unique Character in a String -u
tags: [算法, LeetCode, Hash散列]

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

#### Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

#### Note: You may assume the string contain only lowercase letters.


#### Solution:


因为不到最后无法得知出现是否重复, 于是建立一个Hash表,大小为26个lower字母, 存放每个字符出现的次数.

```cpp
// Time:O(n), Space:O(1)
class Solution {
 public:
  int firstUniqChar(string s) {
    int cnt[30];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < s.length(); i++) {
      cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < s.length(); i++) {
      if (cnt[s[i] - 'a'] == 1) return i;
    }
    return -1;
  }
};
```


### 242. Valid Anagram -u

Given two strings s and t , write a function to determine if t is an anagram of s.

#### Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

#### Example 2:
Input: s = "rat", t = "car"
Output: false

#### Note:
You may assume the string contains only lowercase alphabets.

#### Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

#### Solution1:

使用sort
```cpp
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (int i = 0; i < s.length(); i++) {
      if (s[i] != t[i]) return false;
    }
    return true;
  }
};
```

简化版本
```cpp
class Solution {
 public:
  bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t) return true;
    return false;
  }
};
```


#### Solution2:
建立Hash表, key是char, 对应该字符出现的次数. 一个字符串加一个字符串减。
这里使用散列表实现的`unodered_map`
```cpp
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    unordered_map<char, int> counts;
    for (int i = 0; i < s.length(); i++) {
      counts[s[i]]++;
      counts[t[i]]--;
    }
    for (auto count : counts) {
      if (count.second) return false;
    }
    return true;
  }
};
```

#### Solution3
用ascii码作为key值, 不用map容器用数组
```cpp
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    int counts[26];
    memset(counts, 0, sizeof(counts));
    for (int i = 0; i < s.length(); i++) {
      counts[s[i] - 'a']++;
      counts[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (counts[i]) return false;
    }
    return true;
  }
};
```


### 125. Valid Palindrome -u

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

#### Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true

#### Example 2:
Input: "race a car"
Output: false

#### Solution1:

过滤成回文串去计算, 需要O(n)的空间复杂度
```cpp
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
    int n = t.length();
    for (int i = 0; i <= n/2; i++) {
      if (t[i] != t[n-1-i]) return false;
    }
    return true;
  }
};
```

#### Solution2:
用two pointers的方法, 在原地进行判断,

注意点:
> * 数字和字母, 可以用isalnum()这个函数..
> * 注意还要ignore case, 因此使用tolower在判断前。

```cpp
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
```
