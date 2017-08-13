#include <iostream>
#include "SelectSort.h"

using namespace std;

int main() {
  int *array1 = new int[100];
  for (int i = 100; i > 0; i --) {
    array1[i - 1] = i;
  }
  SelectSort(array1, 100);
  for (int i = 0; i < 100; i ++) {
    cout << array1[i];
  }
  cout << endl;
  delete[] array1;
}