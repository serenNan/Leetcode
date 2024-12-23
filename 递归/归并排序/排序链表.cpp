// TODO：看懂
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution
{
  public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        // 快慢指针找到链表中点
        // slow是链表中点
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 将fast设置为另一部分的起点
        fast = slow->next;

        // 分割两部分
        slow->next = nullptr;


        ListNode *left = sortList(head);
        ListNode *right = sortList(fast);
        ListNode *vHead = new ListNode(-1);
        ListNode *cur = vHead;
        while (left && right)
        {
            if (left->val <= right->val)
            {
                cur->next = left;
                left = left->next;
            }
            else
            {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        cur->next = left ? left : right;

        ListNode *result = vHead->next;
        delete vHead;
        return result;
    }
};
