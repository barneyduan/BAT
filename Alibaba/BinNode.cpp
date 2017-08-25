// Author: duanlian1210@163.com

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct BinTree {
  int val;
  BinTree *left;
  BinTree *right;
  BinTree(int x) : val(x)
                 , left(NULL)
                 , right(NULL) {

  }
};

typedef BinTree TreeNode;

// recurrence
void preOrder(BinTree *t) {
  if (t) {
    cout << t->val;
    preOrder(t->left);
    preOrder(t->right);
  }
}

void midOrder(BinTree *t) {
  if (t) {
    midOrder(t->left);
    cout << t->val;
    midOrder(t->right);
  }
}

void postOrder(BinTree *t) {
  if (t) {
    postOrder(t->left);
    postOrder(t->right);
    cout << t->val;
  }
}

void insert(BinTree **t, int val) {

  if (!(*t)) {
    BinTree *p = new BinTree(val);
    *t = p;
    return;
  }

  if (val < (*t)->val) {
    insert(&((*t)->left), val);
  } else {
    insert(&((*t)->right), val);
  }
}

void deleteTree(BinTree *t) {
  if (t) {
    deleteTree(t->left);
    deleteTree(t->right);
    delete t;
  }
}


TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> mid) {
  if (pre.empty() || mid.empty()) {
    return NULL;
  }
  TreeNode *root = new TreeNode(pre.front());
  int root_val = root->val;
  
  int root_index = 0;
  for (size_t i = 0; i < mid.size(); i ++) {
    if (mid[i] == root_val) {
      root_index = i;
      break;
    }
  }
  vector<int> pre_left(pre.begin() + 1, pre.begin() + 1 + root_index);
  vector<int> mid_left(mid.begin(), mid.begin() + root_index);
  vector<int> pre_right(pre.begin() + 1 + root_index, pre.end());
  vector<int> mid_right(mid.begin() + root_index + 1, mid.end());
  root->left = reConstructBinaryTree(pre_left, mid_left);
  root->right = reConstructBinaryTree(pre_right, mid_right);
  return root;
}



bool JudgeSameTree(TreeNode *p1, TreeNode *p2) {
  if (!p1 && p2) {
    return false;
  } else if (!p2) {
    return true;
  }
  if (p1->val != p2->val) {
    return false;
  }
  if (!JudgeSameTree(p1->left, p2->left)) {
    return false;
  }
  if (!JudgeSameTree(p1->right, p2->right)) {
    return false;
  }
  return true;
}

bool HasSubTree(TreeNode *father, TreeNode *son) {
  if (!father || !son) {
    return false;
  }
  
  if (father->val == son->val) {
    if (JudgeSameTree(father, son)) {
      return true;
    }
  }
  return (HasSubTree(father->left, son) || HasSubTree(father->right, son));

}

/*请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。*/

void Mirror(TreeNode *root) {
  if (!root || (!root->left && !root->right)) {
    return;
  }
  TreeNode *temp = root->left;
  root->left = root->right;
  root->right = temp;
  Mirror(root->left);
  Mirror(root->right);
}

bool isEqual(TreeNode *p1, TreeNode *p2) {
  if (!p1 && !p2) {
    return true;
  }
  if (!p1 || !p2) {
    return false;
  }
  if (p1->val = p2->val) {
    return (isEqual(p1->left, p2->right) && 
        isEqual(p1->right, p2->left))
  }
}

bool isSymmetrical(TreeNode* pRoot)
{
  if (!pRoot) {
    return false;
  }
  return isEqual(pRoot->left, pRoot->right);
    
}


vector<int> PrintFromTopToBottom(TreeNode *root) {
  vector<int> res;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    root = q.front();
    q.pop();
    if (!root) {
      continue;
    }
    q.push(root->left);
    q.push(root->right);
    res.push_back(root->val);
  }
  return res;
}

bool VerifySquenceOfBST(vector<int> sequence) {
  if (sequence.empty()) {
    return false;
  }

  int root = sequence.back();
  sequence.pop_back();
  int i = sequence.size() - 1;

  for (; i >= 0; i --) {
    if (sequence[i] < root) {
      break;
    }
  }
  for (int j = 0; j < i; j ++) {
    if (sequence[j] > root) {
      return false;
    }
  }
  vector<int> left(sequence.begin(), sequence.begin() + i + 1);
  vector<int> right(sequence.begin() + i + 1, sequence.end());
  return ((left.empty() ? true : VerifySquenceOfBST(left)) 
    && (right.empty() ? true : VerifySquenceOfBST(right)));

}

/*输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。*/

void __findPath(TreeNode *root, int expect,
  vector<vector<int> > &res, vector<int> path, int sum) {
  if (!root) {
    return;
  }
  sum += root->val;
  path.push_back(root->val);
  if (!root->left && !root->right) {
    if (sum == expect) {
      res.push_back(path);
      return;
    } 
  }
    __findPath(root->left, expect, res, path, sum);
    __findPath(root->right, expect, res, path, sum);
}


vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
  vector<vector<int> > res;
  vector<int> path;
  if (!root) {
    return res;
  }
  int sum = 0;
  __findPath(root, expectNumber, res, path, sum);
  return res;
}

/*请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。*/

vector<vector<int> > Print(TreeNode* pRoot) {
  vector<vector<int> > res;
  if (!pRoot) return res;
  vector<int> line;
  bool dir = true;
  queue<TreeNode *> q;
  TreeNode *sp = NULL;
  q.push(sp);
  q.push(pRoot);
  while (q.size() > 1) {
    pRoot = q.front();
    if (!pRoot) {
      q.pop();
      queue<int>::iterator iter = NULL;
      if (dir) {
        iter = queue.begin();
      } else {
        iter = queue.rbegin();
      }
      dir = !dir;
      vector<int> temp;
      while (!iter) {
        temp.push_back(iter->val);
      }
      res.push_back(temp);
      q.push(sp); // add a null ptr
    } else {
      if (pRoot->left) {
        q.push(pRoot->left);
      }
      if (pRoot->right) {
        q.push(pRoot->right);
      }
    }
  }
  return res;
}


int main() {
/*  int x[] = {6, 9, 3, 4, 2, 7, 5};
  BinTree *root = new BinTree(x[0]);

  for (int i = 1; i < 7; i ++) {
    insert(&root, x[i]);
  }

  preOrder(root);
  cout << endl;
  midOrder(root);
  cout << endl;
  postOrder(root);
  cout << endl;

  deleteTree(root);

  int p1[] = {1, 2, 4, 7, 3, 5, 6, 8};
  int p2[] = {4, 7, 2, 1, 5, 3, 6, 8};
  vector<int> pre(p1, p1 + 8);
  vector<int> mid(p2, p2 + 8);
  TreeNode *f = reConstructBinaryTree(pre, mid);
  preOrder(f);
  cout << endl;
  deleteTree(f);*/

  int x[] = {6, 9, 3, 4, 2, 7, 5};
  TreeNode *root = new TreeNode(x[0]);

  for (int i = 1; i < 7; i ++) {
    insert(&root, x[i]);
  }

  int y[] = {3, 2, 4};
  TreeNode *son = new TreeNode(y[0]);

  for (int j = 1; j < 3; j ++) {
    insert(&son, y[j]);
  }

  bool flag = HasSubTree(root, son);
  cout << flag << endl;

  return 0;
}

