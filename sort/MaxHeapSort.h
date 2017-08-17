#ifndef MAX_HEAP_SORT_H__
#define MAX_HEAP_SORT_H__

#include <cmath>
#include <assert.h>
#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;


// Max Heap Sort
/****
 * Max Heap: parent(i) = i / 2; left child (i) = 2 * i;
 * right child (i) = 2 * i + 1;
 */

template<typename T>
class MaxHeap {
 public:
  MaxHeap(int capacity) {
    data = new T[capacity + 1];
    count = 0;
    this->capacity = capacity;
  }

  MaxHeap(T arr[], int capacity) {
    data = new T[capacity + 1];
    count = 0;
    this->capacity = capacity;

    for (int i = 1; i < capacity + 1; i ++) {
      data[i] = arr[i];
      count ++;
    }
    Heapify();

  }
  ~MaxHeap() {
    delete[] data;
  }

  int Size() {
    return count;
  }

  bool IsEmpty() {
    return count == 0;
  }

  void Insert(T item) {
    assert(count + 1 <= capacity);
    data[++count] = item;
    ShiftUp(count);
  }

  T ExtractMax() {
    assert(count > 0);
    swap(data[1], data[count]);
    count --;
    ShiftDown(1);
    return data[count + 1];
  }

 private:
  T *data;
  int count;
  int capacity;

 private:
  // for Insertion
  void ShiftUp(int k) {
    while ( k > 1 && data[k / 2] < data[k]) {
      swap(data[k / 2], data[k]);
      k /= 2;
    }
  }

  // for delete
  void ShiftDown(int k) {
    int max;
    while (k <= count / 2) {
      if (2 * k + 1 <= count) {
        max = data[2 * k] > data[2 * k + 1] ? 2 * k : 2 * k + 1;
      } else {
        max = data[2 * k] > data[k] ? 2 * k : k;
      }
      if (data[k] < data[max]) {
        swap(data[k], data[max]);
        k = max;
      } else {
        break;
      }
    }
  }

  void Heapify() {
    int start = count / 2;
    while (start >= 1) {
      ShiftDown(start);
      start --;
    }
  }



 public:
  void testPrint() {

    if( Size() >= 100 ){
        cout<<"Fancy print can only work for less than 100 int";
        return;
    }

    if( typeid(T) != typeid(int) ){
        cout <<"Fancy print can only work for int item";
        return;
    }

    cout<<"The Heap size is: "<<Size()<<endl;
    cout<<"data in heap: ";
    for( int i = 1 ; i <= Size() ; i ++ )
        cout<<data[i]<<" ";
    cout<<endl;
    cout<<endl;

    int n = Size();
    int max_level = 0;
    int number_per_level = 1;
    while( n > 0 ) {
        max_level += 1;
        n -= number_per_level;
        number_per_level *= 2;
    }

    int max_level_number = int(pow(2, max_level-1));
    int cur_tree_max_level_number = max_level_number;
    int index = 1;
    for( int level = 0 ; level < max_level ; level ++ ){
        string line1 = string(max_level_number*3-1, ' ');

        int cur_level_number = min(count-int(pow(2,level))+1,int(pow(2,level)));
        bool isLeft = true;
        for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
            putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
            isLeft = !isLeft;
        }
        cout<<line1<<endl;

        if( level == max_level - 1 )
            break;

        string line2 = string(max_level_number*3-1, ' ');
        for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
            putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
        cout<<line2<<endl;

        cur_tree_max_level_number /= 2;
    }
  }

 private:
  void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else{
            if( isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }


};

#endif