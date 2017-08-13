#ifndef SELECTSORT_H__
#define SELECTSORT_H__

#include <algorithm>

using namespace std;

template<typename T>
void SelectSort(T arr[], int n) {
  for (int i = 0; i < n; i ++) {
    int min = i;
  	for (int j = i + 1; j < n; j ++) {
  		if (arr[i] > arr[j]) {
        min = j;
  		}
  	}
    if (min != i) {
      swap(arr[i], arr[min]);  
    }
  }
}

#endif