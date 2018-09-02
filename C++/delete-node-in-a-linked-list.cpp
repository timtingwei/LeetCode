// Copyright [2018] <mituh>
// delete-node-in-a-linked-list.cpp

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  void deleteNode(ListNode* node) {
    node->val = node->next->val;
    ListNode* delNode = node->next;
    node->next = delNode->next;
    delete(delNode);
  }
};

/*
// a try
class Solution {
 public:
  void deleteNode(ListNode* node, int val) {
    ListNode * prev = node, *p = prev->next;
    if (prev->val == val) {
      free(prev);
      node = p;
      return;
    }

    while (p -> val != val) {
      prev = prev->next;
      p = p->next;
    }

    prev->next = p->next;
    free(p);
    return;
  }
};
*/


int main() {
  return 0;
}
