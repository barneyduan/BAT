#ifndef THREE_SUM_H__
#define THREE_SUM_H__

#include <iostream>
#include <vector>

using namespace std;

class Solution_3Sum_2 {
 public:
  vector<vector<int> > threeSum(vector<int> &nums) {
    MergeSort(nums);
    int a, b, c;
    size_t size = nums.size();
    vector<vector<int> > res;
    if (size == 0) {
      return res;
    }
    for (size_t i = 0; i < size - 2; ++ i) {
      if (i == 0 || (i > 0 && nums[i] != nums[i - 1]) ) {
        size_t j = i + 1;
        size_t k = size - 1;
        int sum = 0 - nums[i];
        while (j < k) {
          if (nums[j] + nums[k] == sum) {
            vector<int> tmp{nums[i], nums[j], nums[k]};
            res.push_back(tmp);
            while (nums[j + 1] == nums[j]) {
              j ++;
            }
            while (nums[k - 1] == nums[k]) {
              k --;
            }
            j ++;
            k --;
          } else if (nums[j] + nums[k] < sum) {
            j ++;
          } else {
            k --;
          }
        }
      }

    }
    return res;
  }

 private:
  void MergeSort(vector<int> &num) {
    int n = num.size();
    if (n <= 0) {
      return;
    }
    __MergeSort(num, 0, n - 1);
  }

  void __MergeSort(vector<int> &num, int l, int r) {
    if (l >= r) {
      return;
    }

    int mid = l + (r - l) / 2;
    __MergeSort(num, l, mid);
    __MergeSort(num, mid + 1, r);

    vector<int> temp(r - l + 1);
    int s1 = l;
    int e1 = mid;
    int s2 = mid + 1;
    int e2 = r;
    int i = l;
    while (s1 <= e1 && s2 <= e2) {
      temp[i - l] = num[s1] < num[s2] ? num[s1++] : num[s2++];
      i ++;
    }
    while (s1 <= e1) {
      temp[i - l] = num[s1++];
      i ++;
    }
    while (s2 <= e2) {
      temp[i - l] = num[s2++];
      i ++;
    }

    for (int i = l; i <= r; i ++) {
      num[i] = temp[i - l];
    }

   }
}


class Solution_3Sum_1 {
 public:
  vector<vector<int> > threeSum(vector<int>& nums) {
    int a, b, c;
    size_t size = nums.size();
    vector<vector<int> > res;
    for (size_t i = 0; i < size; ++ i) {
      for (size_t j = i + 1; j < size; ++ j) {
        for (size_t k = 0; k < size; ++ k) {
          a = nums[i];
          b = nums[j];
          c = nums[k];
          if (k != i && k != j && a + b + c == 0) {
            vector<int> temp{a, b, c};
            vector<vector<int> >::iterator iter = res.begin();
            bool is_exits = false;
            for (; iter != res.end(); iter ++) {
              if (IsThreeIndexEqual(*iter, temp)) {
                is_exits = true;
              }
            }
            if (!is_exits) {
              res.push_back(temp);
            }
          }
        }
      }
    }
    return res;
  }

 private:
  bool IsThreeIndexEqual(vector<int> arr1, vector<int> arr2) {
    if (arr1.size() != arr2.size()) {
      return false;
    }
    // Insertion Sort
    size_t size = arr1.size();
    for (int i = 1; i < size; ++ i) {
      int temp1 = arr1[i];
      for (int j = i; j >= 0; j --) {
        if (j != 0 && arr1[j - 1] > temp1) {
          arr1[j] = arr1[j - 1];
        } else {
          arr1[j] = temp1;
          break;
        }
      }

    }

    for (int i = 1; i < size; ++ i) {
      int temp2 = arr2[i];
      for (int j = i; j >= 0; j --) {
        if (j != 0 && arr2[j - 1] > temp2) {
          arr2[j] = arr2[j - 1];
        } else {
          arr2[j] = temp2;
          break;
        }
      } 
    }

    //Judge the same or not

    for (int i = 0; i < size; ++ i) {
      if (arr1[i] != arr2[i]) {
        return false;
      }
    }
    return true;
  }


};

#endif