#include <iostream>

#include "SelectSort.h"
#include "SortTestHelper.h"
#include "Sort.h"
#include "MaxHeapSort.h"

using namespace std;

int main() {
/*  int n = 50000;
  int *arr1 = SortTestHelper::GenerateRandomArray(n, 0, n);
  SortTestHelper::TestSort("Select Sort", SelectSort, arr1, n);

  int *arr2 = SortTestHelper::GenerateRandomArray(n, 0, n);
  SortTestHelper::TestSort("Insert Sort", InsertSort, arr2, n);

  int *arr3 = SortTestHelper::GenerateRandomArray(n, 0, n);
  int *arr4 = SortTestHelper::GenerateRandomArray(n, 0, n);
  SortTestHelper::TestSort("Bubble Sort 1", BubbleSort1, arr3, n);
  SortTestHelper::TestSort("Bubble Sort 2", BubbleSort2, arr4, n);

  int *arr5 = SortTestHelper::GenerateRandomArray(n, 0, n);
  int *arr6 = SortTestHelper::GenerateRandomArray(n, 0, n);
  SortTestHelper::TestSort("Merge Sort Iteration", 
    MergeSortIteration, arr5, n);
  SortTestHelper::TestSort("Merge Sort Recurrence",
    MergeSortRecurrence, arr6, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  delete[] arr4;
  delete[] arr5;
  delete[] arr6;

  int *arr = SortTestHelper::GenerateRandomArray(n, 0, n);
  SortTestHelper::TestSort("Fast Sort 3 roads", FastSort, arr, n);

  delete[] arr;*/



/*  srand(time(NULL));
  int arr[31];
  for (int i = 0; i < 31; i ++) {
    arr[i] = rand() % 100;
  }

  MaxHeap<int> maxheap = MaxHeap<int>(arr, 31);
  maxheap.testPrint();*/

  int n = 10;
  int *arr1 = SortTestHelper::GenerateRandomArray(n, 0, n);
  SortTestHelper::TestSort("SelfMaxHeapSort", SelfMaxHeapSort, arr1, n);
  delete[] arr1;


/*  srand(time(NULL));
  for (int i = 0; i < 31; i ++) {
    maxheap.Insert(rand() % 100);
  }

  maxheap.testPrint();

  while ( !maxheap.IsEmpty()) {
    cout << maxheap.ExtractMax() << " ";
  }
  cout << endl;*/


  return 0;
}