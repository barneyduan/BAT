// Author: duanlian1210@163.com (Duan Lian)

#include <iostream>
#include <vector>
#include <stack>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x)
                  , next(NULL) {

  }
};

using namespace std;

ListNode *findTail(ListNode *head) {
  if (!head) {
    return NULL;
  }
  ListNode *f = head;
  while(head->next != NULL) {
    head = head->next;
  }
  ListNode *r = head;
  head = f;
  return r;
}

ListNode *findPrevious(ListNode *head, ListNode *index) {
  if (head == index) {
    return NULL;
  }
  ListNode *pre = head;
  while (head->next != NULL) {
    if (head->next == index) {
      ListNode *r = head;
      head = pre;
      return r;
    }
    head = head->next;
  }
  head = pre;
  return NULL;
}

vector<int> printListFromTailToHead2(ListNode *head) {
  ListNode *tail = findTail(head);
  if (!tail) {
    return vector<int>();
  }
  vector<int> res;
  res.push_back(tail->val);
  ListNode *pre;
  while ((pre = findPrevious(head, tail)) != NULL) {
    res.push_back(pre->val);
    tail = pre;
  }
  return res;
}

/*输入一个链表，从尾到头打印链表每个节点的值。*/
// recurrence
vector<int> printListFromTailToHead1(ListNode *head) {
  if (!head) {
    return vector<int>();
  }
  vector<int> res = printListFromTailToHead1(head->next);
  res.push_back(head->val);
  return res;
}

vector<int> printListFromTailToHead(ListNode *head) {
  if (!head) {
    return vector<int>();
  }
  vector<int> res;
  stack<int> s;
  while (head) {
    s.push(head->val);
    head = head->next;
  }
  while (!s.empty()) {
    res.push_back(s.top());
    s.pop();
  }
  return res;
}

int main() {
  ListNode *head = new ListNode(0);
  ListNode *pre = head;
  for (int i = 1; i < 10; i ++) {
    ListNode *item = new ListNode(i);
    head->next = item;
    head = head->next;
  }
  vector<int> res = printListFromTailToHead(pre);
  for (size_t i = 0; i < res.size(); i ++) {
    cout << res[i] <<"->";
  }
  cout << endl;

  return 0;
}
