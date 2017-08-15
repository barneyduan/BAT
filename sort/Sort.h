#ifndef SORT_H__
#define SORT_H__

#include <algorithm>

using namespace std;

template<typename T>
void InsertSort(T arr[], int n) {
  for (int i = 1; i < n; ++ i) {
    T temp = arr[i];
    for (int j = i; j >= 0; -- j) {
      if (j != 0 && arr[j - 1] > temp) {
        arr[j] = arr[j -1];
      } else {
        arr[j] = temp;
        break;
      }
    }
  }
}

// Bubble Sort 1
template<typename T>
void BubbleSort1(T arr[], int n) {
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n - 1 - i; ++ j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

// Bubble Sort 2
template<typename T>
void BubbleSort2(T arr[], int n) {
  for (int i = 0 ; i < n; ++ i) {
    for (int j = n; j >= i + 1; -- j) {
      if (arr[j] < arr[j - 1]) {
        swap(arr[j - 1], arr[j]);
      }
    }
  }
}

// Merge Sort
// iteration
template<typename T>
void MergeSortIteration(T arr[], int n) {
  T *a = arr;
  T *b = new T[n];
  for (int seg = 1; seg < n; seg += seg) {
    for (int start = 0; start < n; start += seg * 2) {
      int low = start;
      int mid = min(start + seg, n);
      int high = min(start + seg * 2, n);
      int k = low;
      int s1 = low, e1 = mid;
      int s2 = mid, e2 = high;
      while (s1 < e1 && s2 < e2) {
        b[k++] = a[s1] < a[s2] ? a[s1++] : a[s2++];
      }
      while (s1 < e1) {
        b[k++] = a[s1++];
      }
      while (s2 < e2) {
        b[k++] = a[s2++];
      }
    }
    T *temp = a;
    a = b;
    b = temp;
  }

  delete[] b;
  return;
}


// recurrence
template<typename T>
void __MergeSortRecurrence(T arr[], int l, int mid, int r) {
  T aux[r - l + 1];
  // *****************************************************
  // pay attention to aux[3] when i =3 j = 5;
  // k from 3 to 5, but index of aux is from 0 to 2
  // ******************************************************
  
  int i = l, j = mid + 1;
  int k = l;
  while (i <= mid && j <= r) {
    aux[k-l] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    k++;
  }
  while (i <= mid) {
    aux[k-l] = arr[i++];
    k++;
  }
  while (j <= r) {
    aux[k-l] = arr[j++];
    k++;
  }

  for (int i = l; i <= r; i ++) {
    arr[i] = aux[i-l];
  }
}

template<typename T>
void __MergeSortRecurrence(T arr[], int l, int r) {
  if (l >= r) {
    return;
  }
  int mid = l + (r - l) / 2;
  __MergeSortRecurrence(arr, l, mid);
  __MergeSortRecurrence(arr, mid + 1, r);
  __MergeSortRecurrence(arr, l, mid, r);
}

template<typename T>
void MergeSortRecurrence(T arr[], int n) {
  __MergeSortRecurrence(arr, 0, n - 1);
}


#endif