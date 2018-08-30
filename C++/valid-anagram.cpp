// Copyright [2018] <mituh>
// valid-anagram.cpp
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;


// sort
/*
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
*/

/*
class Solution {
 public:
  bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t) return true;
    return false;
  }
};
*/

/*
// Hash unordered_map<char,int>
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
*/

// Hash array, ascii

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

int main() {
  Solution solution;
  string s1 = "anagram", t1 = "nagaram";
  string s2 = "cat", t2 = "tar";
  cout << solution.isAnagram(s1, t1) << endl;
  cout << solution.isAnagram(s2, t2) << endl;
  return 0;
}
