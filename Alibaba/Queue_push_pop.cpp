// Author: duanlian1210@163.com

#include <iostream>
#include <stack>

using namespace std;

/*用两个栈来实现一个队列，完成队列的Push和Pop操作。
 队列中的元素为int类型。
*/

class Solution_Queue_push_pop
{
public:
    void push(int node) {
      stack1.push(node);
    }

    int pop() {
      if (!stack2.empty()) {
        int p = stack2.top();
        stack2.pop();
        return p;
      } else {
        while (!stack1.empty()) {
          int p = stack1.top();
          stack1.pop();
          stack2.push(p);
        }
        int r = stack2.top();
        stack2.pop();
        return r;
      }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

/*输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为
该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是
某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但
4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度
是相等的）*/

bool IsPopOrder(vector<int> pushV,vector<int> popV) {

  if (pushV.empty() || popV.empty() || pushV.size() != popV.size()) {
    return false;
  }
  vector<int> stack;
  int i = 0, j = 0;
  for (; i < pushV.size();) {
   stack.push_back(pushV[i++]);
   while (j < popV.size() && stack.back() == popV[j]) {
       stack.pop_back();
       j++;
   }
  }
  return stack.empty();
}

/*定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。*/


class Solution_Stack_min {
public:
    void push(int value) {
      if (stack2.empty()) {
        stack2.push(value);
      } else if (stack2.top() > value) {
        stack2.push(value);
      }
      stack1.push(value);
    }
    void pop() {
      if (stack1.top() == stack2.top()) {
        stack2.pop();
      }
      stack1.pop();
    }
    int top() {
      return stack1.top();
    }
    int min() {
      return stack2.top();
    }
private:
  stack<int> stack1;
  stack<int> stack2;
};