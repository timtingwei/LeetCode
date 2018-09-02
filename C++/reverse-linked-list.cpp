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

/*
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

*/


// follow1: iteratively
class Solution {
 public:
  ListNode* reverseList(ListNode* head, int k) {
    if (head == nullptr) return head;
    ListNode *pNode = head;
    for (int i = 0; i < k-1; i++) {
      if (pNode->next == nullptr) return head;
      pNode = pNode->next;
    }
    ListNode *reverseHead = pNode, *nextNode = pNode->next;
    while (pNode != head) {
      ListNode *p = head;
      while (p->next != pNode) {
        p = p->next;
      }
      pNode->next = p;
      pNode = p;
    }
    pNode->next = nextNode;
    return reverseHead;
  }
};


/*
[1, 2, 3, 4, 5]
int k = 2;

[2, 1, 3, 4, 5]
*/

