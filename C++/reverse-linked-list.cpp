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

// basic reverse
// Time:O(n), Space:O(1)
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* reverseHead = nullptr;
    ListNode* pNode = head;
    ListNode* pPrev = nullptr;
    while (pNode != nullptr) {
      ListNode* pNext = pNode->next;
      if (pNext == nullptr) {
        reverseHead = pNode;
      }
      pNode->next = pPrev;
      pPrev = pNode;
      pNode = pNext;
    }
    return reverseHead;
  }

};


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


// follow up1: iteratively
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

// follow up2: recursively
class Solution {
 public:
  ListNode* reverseList(ListNode* head, int k) {
    if (head == nullptr || k <= 1) return head;

    ListNode *pNode = head, *reverseHead = nullptr,
        *lastHead = head, *lastTail = nullptr;
    for (;;) {
      for (int i = 0; i < k-1; i++) {
        if (pNode->next == nullptr) return reverseHead;
        pNode = pNode->next;
      }
      ListNode *segHead = pNode, *nextNode = pNode->next;
      if (reverseHead == nullptr) {
        reverseHead = segHead;
      }
      if (lastTail != nullptr) {
        lastTail->next = segHead;
      }

      while (pNode != lastHead) {
        ListNode *p = lastHead;
        while (p->next != pNode) {
          p = p->next;
        }
        pNode->next = p;
        pNode = p;
      }
      pNode->next = nextNode;
      lastTail = lastHead;
      lastHead = nextNode;
      pNode = nextNode;
      if (lastHead == nullptr) {
        return reverseHead;
      }
    }
    return reverseHead;
  }
};


/*
input:
[1,2,3,4,5,6,7,8]
3

[3, 2, 1, 6, 5, 4, 7, 8]


input:
[1,2,3,4,5,6,7,8]
2

[2, 1, 4, 3, 6, 5, 8, 7]
*/
