// https://leetcode.cn/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-100-liked

#include <unordered_map>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
public:
  unordered_map<Node *, Node *> map;
  Node *copyRandomList(Node *head) {
    if (head == nullptr)
      return head;
    if (!map.count(head)) {
      Node *newNode = new Node(head->val);
      map[head] = newNode;
      newNode->next = copyRandomList(head->next);
      newNode->random = copyRandomList(head->random);
      return newNode;
    }
    
    return map[head];
  }
};