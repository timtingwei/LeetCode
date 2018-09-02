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

// 扫描两遍, 保存前一个结点的方法
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) return head;
    ListNode* prev = head, *p = prev->next;
    int size = 1;
    while (p) {
      prev = prev->next;
      p = prev->next;
      size++;
    }

    prev = head; p = prev->next;
    for (int i = 0; i < size-n-1; i++) {
      prev = prev->next;
      p = prev->next;
    }

    if (prev && !p) {
      prev = nullptr;
      delete(prev); delete(p);
      head = nullptr;
    } else {
      if (prev == head && size-n == 0) {
        delete(prev);
        head = p;
      } else {
        prev->next = p->next;
        delete(p);
      }
    }
    return head;
  }
};






