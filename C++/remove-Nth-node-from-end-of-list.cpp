// Copyright [2018] <mituh>
// remove-Nth-node-from-end-of-list.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *p = head; int size = 0;
    while (p) {
      p = p -> next;
      size++;
    }
    p = head;
    for (int i = 0; i < size-n; i++) {
      printf("val = %d\n", p->val);
      p = p->next;
    }
    if (p->next) {
      p->val = p->next->val;
      ListNode *delNode = p->next;
      p->next = delNode->next;
      delete(delNode);
    } else {
      if (p == head) {
        head = nullptr;
      }
      ListNode *delNode = p->next;    // 无法删除尾结点
      p = nullptr;
      delete(delNode);
    }
    return head;
  }
};

