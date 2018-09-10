// Copyright [2018] <mituh>
// merge-two-sorted-lists.cpp
// Time:O(n), Space:O(1)
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(INT_MIN);
    ListNode* tail = &dummy;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
      // if (head == nullptr) head = tail;   // null head node
    }
    tail->next = (l1) ? l1:l2;
    return dummy.next;   // why not dummy->next
  }
};
