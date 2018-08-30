// Copyright [2018] <mituh>
// first-unique-character-in-a-string.cpp
#include <iostream>
#include <string>
using namespace std;



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



int main() {
  Solution solution;
  string s1 = "leetcode", s2 = "loveleetcode";
  string s3 = "uindrseqbljlhqvlwvgdebeihttirikuahlikgnahvgnptmqwbovmuwesxkvcitcwrwrucsbbfqvldridfviduqvmfcmeiphoqupbitnwdbvevouoaetisdmgvvvwoglwtgjrpcbghxkrkjthetxeexbphbjiehaicuicgnirslhdstgmqcdnlulpdpadjdltfouwhfqicfcqntnpeqaohslwkhbvflxaudembsrsindluthxapnmrqins";
  string s4 = "aaab";
  cout << solution.firstUniqChar(s1) << endl;
  cout << solution.firstUniqChar(s2) << endl;
  cout << solution.firstUniqChar(s3) << endl;
  cout << solution.firstUniqChar(s4) << endl;
  return 0;
}
