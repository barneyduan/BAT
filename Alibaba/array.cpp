// Author: duanlian1210@163.com (Duan Lian)

#include <iostream>
#include <vector>

using namespace std;

/*把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，
该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。*/

/*special situation: {0, 1, 1, 1, 1} -> {1, 1, 1, 0, 1}
or -> {1, 0, 1, 1, 1}, in this situation, it must use order search
instead of binary search.*/

bool searchOrder(vector<int> &rotateArray, int left, int right) {
  for (int i = left; i <= right; i++) {
    if (rotateArray[i] < rotateArray[left] &&
      rotateArray[i] < rotateArray[right]) {
      return true;
    }
  }
  return false;
}

int minNumberInRotateArray(vector<int> rotateArray) {
  int left = 0;
  int right = rotateArray.size() - 1;
  int mid = left + (right - left) / 2;
  while (right - left > 1) {
    if (rotateArray[left] < rotateArray[mid] && 
       rotateArray[right] < rotateArray[mid]) {

      left = mid;
    } else if (rotateArray[left] > rotateArray[mid] &&
      rotateArray[right] > rotateArray[mid]) {

      right = mid;
    } else if (rotateArray[left] == rotateArray[mid] &&
      rotateArray[right] == rotateArray[mid]) {

      if (searchOrder(rotateArray, left, mid)) {
        right = mid;
      } else if (searchOrder(rotateArray, mid, right)) {
        left = mid;
      } else {
        return rotateArray[mid];
      }

    }
  }
  return rotateArray[right];

}


/*大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39*/

int Fibonacci(int n) {
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 1;
  }

  return Fibonacci(n - 1) + Fibonacci(n - 2);
}