// Author: duanlian1210@163.com (Duan Lian)

#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x)
              , next(NULL) {

  }
};

using namespace std;


ListNode *reverseListNode(ListNode *head) {
  // ListNode *tail = NULL;
  // ListNode *p = head->next;
  // head->next = tail;
  // tail = head;
  // head = p;
  ListNode *tail = NULL;
  while (head) {
    ListNode *p_next = head->next;
    head->next = tail;
    tail = head;
    head = p_next;
  }
  return tail;
}

ListNode *removeDuplicate(ListNode *head) {
  if (!head) {
    return head;
  }
  ListNode *first = head;
  while (head) {
    if (!head->next) {
      break;
    }
    while (head->val == head->next->val) {
      ListNode *tmp = head->next;
      head->next = head->next->next;
      delete tmp;
    }
    head = head->next;
  }
  return first;
}


void deleteListNode(ListNode *head) {
  while (head) {
    ListNode *p = head->next;
    delete head;
    head = p;
  }
}

void printListNode(ListNode *head) {
  ListNode *p = head;
  while (head) {
    cout << head->val << "->";
    head = head->next;
  }
  cout <<endl;
  head = p;
}

ListNode *mergeListNode(ListNode *p1, ListNode *p2) {
  if (!p1 && !p2) {
    return NULL;
  }
  if (!p1) {
    return p2;
  }
  if (!p2) {
    return p1;
  }

  ListNode *dummy = new ListNode(0);
  ListNode *first = dummy;
  while (p1 && p2) {
    dummy->next = p1;
    dummy = p1;
    p1 = p1->next;
    dummy->next = p2;
    dummy = p2;
    p2 = p2->next;
  }
  while (p1) {
    dummy->next = p1;
    dummy = p1;
    p1 = p1->next;
  }
  while (p2) {
    dummy->next = p2;
    dummy = p2;
    p2 = p2->next;
  }

  // delete first dummy node
  ListNode *tmp = first;
  first = first->next;
  delete tmp;
  return first;

}

ListNode *insertNode(ListNode *head, ListNode *p) {
  p->next = head;
  return p;
}

void moveNode(ListNode **dest, ListNode **src) {
  ListNode *newNode = *src;
  *src = newNode->next;
  newNode->next = *dest;
  *dest = newNode;
}

// a->b->c, when **last = &b, f->next = b, *last = d->e->f, it turns: 
// a->d->e->f->b->c. 因为当a去搜寻b的地址时，会找到f的值。

ListNode *sortedMerge(ListNode *p1, ListNode *p2) {
  if (!p1 && !p2) {
    return NULL;
  }
  if (!p1) {
    return p2;
  }
  if (!p2) {
    return p1;
  }

  // **last = &dummy
  // 当搜寻dummy的地址时，会自动定位到其他的Node， 
  // dummy从指向NULL变为指向链表Head

  ListNode *dummy = NULL;
  ListNode **last = &dummy;

  // last = &(*last->next) 不再是&dummy， 无法控制dummy的内容了。

  for (; p1 && p2; last = &((*last)->next)) {
    if (p1->val <= p2->val) moveNode(last, &p1);
    else moveNode(last, &p2);
  }
  *last = p1 ? p1 : p2;
  return dummy;
}

void sortedInsert(ListNode **head, ListNode *newnode) {
  ListNode **cur = head;
  while (*cur != NULL && (*cur)->val < newnode->val) {
    cur = &((*cur)->next);
  }
  newnode->next = *cur;
  *cur = newnode;
}

/*输入一个链表，输出该链表中倒数第k个结点。*/

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

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
  if (!pListHead) {
    return NULL;
  }
  ListNode *tail = findTail(pListHead);
  for (int i = 1; i < k; i++) {
    tail = findPrevious(pListHead, tail);
  }
  return tail;
}

ListNode *FindKthToTail2(ListNode *pListHead, unsigned int k) {
  if (!pListHead) {
    return NULL;
  }
  ListNode *p1 = pListHead;
  for (int i = 0; i < k - 1; i ++) {
    if (!p1->next) {
      return NULL;
    }
    p1 = p1->next;
  }
  ListNode *p2 = pListHead;
  while (!p1->next) {
    p1 = p1->next;
    p2 = p2->next;
  }
  return p2;
}

void addToTail(ListNode **head, int val) {
  ListNode *tail = new ListNode(val);
  if (!*head) {
    *head = tail;
  } else {
    ListNode *p = *head;
    while (p->next) {
      p = p->next;
    }
    p->next = tail;
  }
}

bool IfExistLoop(ListNode *head, int &n, ListNode **node) {
  if (!head || !head->next || !head->next->next) {
    return false;
  }
  ListNode *f = head;
  ListNode *s = head;
  while (f->next && f->next->next) {
    f = f->next->next;
    s = s->next;
    if (f == s) {
      *node = f;
      n = 1;
      s = s->next;
      while (s != f) {
        s = s->next;
        n++;
      }
      return true;
    }
  }
  return false;
}

ListNode* EntryNodeOfLoop(ListNode* pHead) {
  int n = 0;
  ListNode *tmp = NULL;
  ListNode **node = &tmp;

  if (!IfExistLoop(pHead, n, node)) {
    return NULL;
  } else {
    ListNode *p = pHead;
    while (p != *node) {
      p = p->next;
      *node = (*node)->next;
    }
  }
  return *node;
}


/*
  Delete node by O(1) in ListNode
*/

void DeleteNode(ListNode **head, ListNode *node) {
  if (!head || !node) {
    return;
  }

  // n = 1
  if (!(*head)->next) {
    if (*head == node) {
      delete node;
      node = NULL;
      *head = NULL;
    } else {
      return;
    }
    // n >= 1
  }else {
    if (node->next) {
      ListNode *delete_next = node->next;
      node->val = delete_next->val;
      node->next = delete_next->next;
      delete delete_next;
    } else {
      ListNode *p = *head;
      while (p->next != node) {
        p = p->next;
      }
      p->next = NULL;
      delete node;
      node = NULL;
    }
  }
}


int main() {
  int x[] = {1, 2, 3, 4, 5, 6};
  ListNode *head = new ListNode(0);
  ListNode *first = head;
  for (int i = 0; i < 6; i ++) {
    ListNode *p = new ListNode(x[i]);
    head->next = p;
    head = p;
  }
  //head->next = first;
  int n = 0;
  printListNode(first);
  DeleteNode(&first, first->next->next);
  //addToTail(&first, 4);
  printListNode(first);
  //cout << IfExistLoop(first, n);
  //cout << endl << n << endl;
  deleteListNode(first);

  ListNode *test = NULL;
  addToTail(&test, 1);
  printListNode(test);


  // test 2
  int y[] = {4};
  int z[] = {1, 3, 5};

  ListNode *h1 = new ListNode(y[0]);
  ListNode *h2 = new ListNode(z[0]);
  
  ListNode *h11 = h1;
  ListNode *h22 = h2;

  for (int i = 1; i < 3; i ++) {
/*    ListNode *p1 = new ListNode(y[i]);
    h1->next = p1;
    h1 = p1;*/

    ListNode *p2 = new ListNode(z[i]);
    h2->next = p2;
    h2 = p2;
  }

  //ListNode *f = mergeListNode(h11, h22);
  //printListNode(f);
  //deleteListNode(f);
  sortedInsert(&h22, h1);

  return 0;

}



/*输入一个复杂链表（每个节点中有节点值，以及两个指针，
一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）*/

/*
 Solution: 
*/


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

RandomListNode* Clone(RandomListNode* pHead) {

        
}
