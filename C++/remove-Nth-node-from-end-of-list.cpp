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


/*
// 扫描一遍, 无法删除最后一个结点的错误版本:
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *cur = head, *p = head;
    for (int i = 0; p->next; i++) {
      if (i >= n-1) cur = cur->next;
      p = p->next;
    }
    if (cur == head) {
      if (p == head) {
        delete(cur);
        head = nullptr;
      } else {
        head = cur->next;
        delete(cur);
      }
    } else {
      if (cur == p) {
        cur->next = nullptr;
        cur = nullptr;
        free(cur);
      } else {
        cur->val = cur->next->val;
        ListNode *delNode = cur->next;
        cur->next = delNode->next;
        delete(delNode);
      }
    }
    // delete(p);
    return head;
  }

};
*/

/*
  // 删除不了最后一个结点
[1,2,3,4,5]
1

[1, 2, 3, 5]
*/


// 更新删除结点的操作
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr || n == 0) return head;

    ListNode *cur = head, *p = head;
    for (int i = 0; p->next; i++) {
      if (i >= n-1) cur = cur->next;
      p = p->next;
    }

    if (cur->next != nullptr) {   // cur不是尾结点
      ListNode *delNode = cur->next;
      cur->val = delNode->val;
      cur->next = delNode->next;
      delete(delNode);
      delNode = nullptr;
    } else if (cur == head) {     // cur既是头结点也是尾结点
      delete(cur);
      cur = nullptr;
      head = nullptr;
    } else {                      // cur是尾结点
      p = head;
      while (p->next != cur) {
        p = p->next;
      }
      p->next = nullptr;
      delete(cur);
      cur = nullptr;
    }
    return head;
  }
};
