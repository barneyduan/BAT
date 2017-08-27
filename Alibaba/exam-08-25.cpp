// Author: duanlian1210@163.com (Duan Lian)

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <set>

using namespace std;

bool search(const string &str, const string &sub, int &k) {
  int m = str.length();
  int n = sub.length();
  if (m == 0 || n == 0 || m < n){
    return false;
  }
  bool exist = true;
  for (int i = 0; i < m - n; i ++) {
    int j = 0;
    if (str[i] == sub[j]){
       for (j = 0; j < n ; j ++) {
          if (str[i + j] != sub[j]) {
            exist = false;
            break;
          }
       }
       if (exist) {
         k = i;
         return true;
       }
    } else {
      exist = false;
    }
  }
  return exist;
}


list<string> __mincut(const string &str, const set<string> &dict) {
  if (str.empty()) {
    return list<string>();
  }
  list<string> res;
  if (dict.find(str) != dict.end()) {
    res.push_back(str);
    return res;
  }
  set<string>::reverse_iterator iter = dict.rbegin();
  for (; iter != dict.rend(); iter ++) {
    int k = 0;
    if (search(str, *iter, k)) {
      //dir ? res.push_back(*iter) : res.push_front(*iter);
      res.push_back(*iter);
      string left(str, 0, k);
      string right(str, k + iter->length(), str.length());
      list<string> l = __mincut(left, dict);
      while (!l.empty()) {
        res.push_front(l.back());
        l.pop_back();
      }
      list<string> r = __mincut(right, dict);
      while (!r.empty()) {
        res.push_back(r.front());
        r.pop_front();
      }
      return res;
    }
  }


}

void mincut(const string& str, const set<string>& dict) {
  if (str.empty()) {
    return;
  }
  list<string> res;
  res = __mincut(str, dict);
  list<string>::iterator iter =res.begin();
  for (; iter!=res.end(); iter++) {
    cout << *iter << " ";
  }
  cout << endl;
  return;
}

int main() {
    string strS;
    string dictStr;
    int nDict;
    set<string> dict;
    
    cin>>strS;
    cin>>nDict;
    for (int i = 0; i < nDict; i++)
    {
        cin>>dictStr;
        dict.insert(dictStr);
    }
    mincut(strS, dict);
    
    return 0;
}