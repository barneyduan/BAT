#include <iostream>

#include "SelectSort.h"
#include "SortTestHelper.h"

using namespace std;

int main() {
  int n = 10000;
  int *arr1 = SortTestHelper::GenerateRandomArray(n, 0, n);
  SortTestHelper::TestSort("SelectSort", SelectSort, arr1, n);

  delete[] arr1;
}