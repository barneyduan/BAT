#ifndef RABBIT_H__
#define RABBIT_H__

#include <cmath>
#include <numeric>
#include <vector>

using namespace std;

int result(int x, int y) {
  int num = 0;
  int sum = 0;
  vector<int> r(y + 1, 0);
  for (int i = 0; i <= y ; i ++) {
    if (i == 0) {
      r[i] = 1;
      continue;
    }
    for (int j = i; j >= 1; j --) {
      if (j >= x) {
        r[j] = 0;
      } else {
        r[j] = r[j - 1];
        if (j <= x - 1 && j >= 2) {
          num += r[j];
        }  
      }
    }
    r[0] = num;
    num = 0;
    int k = 0;
    while (k <= y) {
      sum += r[k++];
    }
    if (sum > 10) {
      if (r[k - 1] > 1) {
        r[k - 1] -= 2;
      } else {
        r[k - 1] -= 1;
        r[k - 2] -= 1;
      }
      sum -= 2;
    }
    sum = 0;
  }
  int age = 0;
  int k = 0;
  while (k <= y) {
    age += 2 * r[k] * k;
    k ++;
  }
  return age;
}


#endif