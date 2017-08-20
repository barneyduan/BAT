// Author : duanlian1210@163.com(Duan Lian)

#include <iostream>

#include "Container_with_most_water.h"
#include "3Sum.h"

using namespace std;

int main(int argc, char *argv[]) {

  /*************************************
    Test for Container_with_most_water.h
  **************************************/

/*  Solution s;
  int arr[2] = {1, 1};
  vector<int> v(arr, arr + 2);

  int r = s.MaxArea(v);*/

   /*************************************
    Test for 3Sum.h
  **************************************/
  Solution_3Sum s;
  int arr[] = {-1, 0, 1, 2, -1, -4};
  vector<int> v(arr, arr + 6);
  vector<vector<int> > r = s.threeSum(v);

  return 0;
}