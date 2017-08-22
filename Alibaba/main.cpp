// Author: duanlian1210@163.com (Duan Lian)
#include <iostream>
#include "Rabbit.h"

using namespace std;

int main(int argv, char *argc[]) {
  int x, y;
  cout << "age of rabbit:";
  cin >> x;
  cout << "years:";
  cin >> y;
  int r = result(x, y);
  cout << "sum age is:" << r << endl;
  return 0;
}