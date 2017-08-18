// Author : duanlian1210@163.com(Duan Lian)

#include <iostream>

#include "Container_with_most_water.h"

using namespace std;

int main(int argc, char *argv[]) {
  Solution s;
  int arr[2] = {1, 1};
  vector<int> v(arr, arr + 2);

  int r = s.MaxArea(v);

  return 0;
}