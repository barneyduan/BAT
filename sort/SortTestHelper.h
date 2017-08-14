#ifndef SORT_TEST_HELPER_H__
#define SORT_TEST_HELPER_H__

#include <ctime>
#include <cassert>
#include <string>
#include <iostream>

namespace SortTestHelper {

template<typename T>
T* GenerateRandomArray(int n, T rl, T rr) {
  assert(rl <= rr);
  T *arr = new T[n];
  srand(time(NULL));
  for (int i = 0; i < n; i ++) {
    arr[i] = rand() % (rr - rl + 1) + rl;
  }
  return arr;
}

template<typename T>
bool IsSorted(T arr[], int n) {
  for (int i = 0; i < n - 1; ++ i) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }
  return true;
}

template<typename T>
void TestSort(string sortname, void(*sort)(T [], int), T arr[], int n) {
    
  clock_t start_time = clock();
  sort(arr, n);
  clock_t end_time = clock();

  assert(IsSorted(arr, n));
  cout << sortname << ":" << double(end_time - start_time) / CLOCKS_PER_SEC 
       << "s" << endl;
  return;
}


}

#endif