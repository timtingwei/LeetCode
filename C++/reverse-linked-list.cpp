// Copyright [2018] <mituh>
// reverse-linked-list.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time:O(n^2), Space:O(1)
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return head;
    ListNode *pNode = nullptr, *reverseHead = nullptr;
    while (pNode != head) {
      ListNode *p = head;
      while (p->next != pNode) {
        p = p->next;
      }

      if (pNode != nullptr) {
        pNode->next = p;
      } else {
        reverseHead = p;
      }
      pNode = p;
    }
    pNode->next = nullptr;
    return reverseHead;
  }
};

