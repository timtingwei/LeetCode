## LeetCode-cpp

### 237. Delete Node in a Linked List -u

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Given linked list -- head = [4,5,1,9], which looks like following:
```
    4 -> 5 -> 1 -> 9
```
#### Example 1:
```
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list
             should become 4 -> 1 -> 9 after calling your function.
```
#### Example 2:
```
Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list
             should become 4 -> 5 -> 9 after calling your function.
```
#### Note:

> * The linked list will have at least two elements.
> * All of the nodes' values will be unique.
> * The given node will not be the tail and it will always be a valid node of the linked list.
> * Do not return anything from your function.

#### Solution:

刚开始的思路是, 用被删除结点前的前一个结点prev, prev->next = node->next; 再释放node的内存。

但因为是单向链表, 只给出一个结点, 因此要删除这个结点就不能找prev结点.

<span sytle="color:red">将下一个结点的值赋给该结点, 该结点指向跳过下一结点, 释放下一个结点。实际上是删除了下一个结点, 但将值赋值给了当前node</span>

```cpp
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
    void deleteNode(ListNode* node) {
      node->val = node->next->val;
      ListNode* delNode = node->next;
      node->next = delNode->next;
      delete(delNode);
    }
};
```


### 19. Remove Nth Node From End of List -u

Given a linked list, remove the n-th node from the end of list and return its head.

#### Example:
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

#### Note:
Given n will always be valid.

#### Follow up:
Could you do this in one pass?

#### Solution:



```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// two-pass, 扫描两遍, 保存前一个结点的方法
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
```

#### Solution2:

一个node先在原地等待, 当p到达n=1的位置时候, cur和p一起移动, 当p移动到最后一个结点时， cur就是要删除的结点。
```cpp
// one-pass, 更新删除结点的操作
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr || n == 0) return head;

    ListNode *cur = head, *p = head;
    for (int i = 0; p->next; i++) {
      if (i >= n-1) cur = cur->next;
      p = p->next;
    }
    
    
    // 删除cur结点的操作
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
```


删除链表结点的操作要记得熟练.
先讨论不是尾结点, 再讨论既是尾结点也是头结点, 最后讨论尾结点.


### 206. Reverse Linked List -u

Reverse a singly linked list.

#### Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
#### Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

#### Solution:
```
1->2->3->4->5;

当5作为头结点指向4的时, 4仍旧指向5, 可以通过每次保留上一次处理的结点, 从末尾前指向
```

几个注意点:
> 1, 主要在中间过程中, 找出反转后的头结点;
> 2, 在反转结束后, 尾指针指向nullptr;
> 3, 要注意空链表的情况;

```cpp
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

```
