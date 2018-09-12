// Copyright [2018] <mituh>
// palindrome-linked-list.cpp

class Solution {
  bool isPalindrome(ListNode *head) {
    if (head == nullptr) return false;
    ListNode *head_a, *head_b, *pNode = head;
    int len = 0;
    while (pNode != nullptr) {
      len++;
      pNode = pNode->next;
    }
    if (len == 1) return true;

    // int half_len = (int)len/2;
    int half_len = len/2;
    ListNode *prevNode = nullptr;
    while (int i = 0; i < half_len; i++) {
      ListNode *pNext = pNode->next;
      pNode->next = prevNode;
      prevNode = pNode;
      pNode = pNext;
    }
    head_a = prevNode;
    head_b = (len % 2) pNode->next : pNode;

    while (head_a && head_b) {
      if (head_a->val != head_b->val) return false;
      head_a = head_a->next;
      head_b = head_b->next;
    }

    return true;
  }
};
