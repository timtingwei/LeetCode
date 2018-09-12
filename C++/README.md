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
#### Solution1:

pNext用于移动pNode, pPrev和找到新的链表头,  保存pPrev用于创建新的链接.

三个变量: 新的链表头reverseHead, 游标结点pNode, 前序结点pPrev, 
四个操作: 循环内部创建下一结点, 改变游标指向前序结点, 前序结点移动到游标结点, 游标结点移动到下一结点.
两个判断: 游标结点非空指针时, 进行循环操作; 游标的下一结点为空指针时, 记录新的链表头
```cpp
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
```
#### Solution2:
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


#### Solution: Follow up1

从随意位置反转链表, 在该位置后的结点不变。
需要保存一个新的头结点, reverseHead; 以及另一结点, nextNode用于, 反转之后的结点拼接。

```
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
```


一个测试Sample
```
input:
[1, 2, 3, 4, 5]
int k = 2;

output:
[2, 1, 3, 4, 5]
```


#### Solution: Follow up2

反转呈现周期性, 但是若不满这个周期, 不会反转链表.

```cpp
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
```



```
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
```


### 234. Palindrome Linked List -uw

Given a singly linked list, determine if it is a palindrome.

#### Example 1:
Input: 1->2
Output: false

#### Example 2:
Input: 1->2->2->1
Output: true

#### Follow up:
Could you do it in O(n) time and O(1) space?

#### Solution:

Time要求O(n), Space要求O(1), 可以原地反转一部分链表, 然后比较反转后的两段链表的结点值是否对应相等。链表长度若是奇数, 中间结点可不比较; 若是偶数, 链表被切割成一半一半.

注意点: 
1, 链表为空或者链表长度为1, 都属于回文.
2, 反转链表需要三个结点.prevNode是前一个结点, pNode是工作结点, pNext是循环中指向下一结点, 改变pNode的指向性后, 若在之前不保存pNext就无法实现移动.

```cpp
// Time:O(n), Space:O(1)
class Solution {
 public:
  bool isPalindrome(ListNode *head) {
    // if (head == nullptr) return false;
    if (head == nullptr) return true;
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
    pNode = head;
    for (int i = 0; i < half_len; i++) {
      ListNode *pNext = pNode->next;
      pNode->next = prevNode;
      prevNode = pNode;
      pNode = pNext;
    }
    head_a = prevNode;
    head_b = (len % 2) ? pNode->next : pNode;

    while (head_a && head_b) {
      if (head_a->val != head_b->val) return false;
      head_a = head_a->next;
      head_b = head_b->next;
    }

    return true;
  }
};
```
