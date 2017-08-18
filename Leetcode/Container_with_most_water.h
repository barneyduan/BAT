// Author : duanlian1210@163.com(Duan Lian)

#ifndef CONTAINER_WITH_MOST_WATER_H__
#define CONTAINER_WITH_MOST_WATER_H__

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// We should search from two side of this array, if i < j, the 
// true height of container is i, whereever we move j (vers left), it
// couldn't be more, so we should move i (vers right);

//   i  ---------------  j
//   |                   |
//   |                   |
//   |                   |

class Solution {
 public:
  int MaxArea(vector<int> &height) {
    int max = 0;
    size_t i = 0;
    size_t j = height.size() -1;
    while(i < j) {
      if (height[i] <= height[j]) {
        int area = height[i] * (j - i);
        max = area > max ? area : max;
        i ++;
      } else {
        int area = height[j] * (j - i);
        max = area > max ? area : max;
        j --;
      }
    }
    return max;
  }
};


#endif