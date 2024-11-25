// TODO：看懂
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
      return head;

    // 找到链表的中点
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // 分割链表
    ListNode *mid = slow->next;
    slow->next = nullptr;

    // 递归排序左右两部分
    ListNode *left = sortList(head);
    ListNode *right = sortList(mid);

    // 合并两个有序链表
    return merge(left, right);
  }

private:
  ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    if (l1)
      tail->next = l1;
    if (l2)
      tail->next = l2;

    return dummy.next;
  }
};
