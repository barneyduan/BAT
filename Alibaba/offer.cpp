// Author: duanlian1210@163.com (Duan Lian)

#include <iostream>

using namespace std;

class CMyString {
 public:
  CMyString();
  CMyString(const CMyString &str);

  CMyString &operator= (const CMyString &str) {
    if (this == &str) {
      return *this;
    }
    delete[] data_;
    data_ = NULL;

    data_ = new char[strlen(str.data_) + 1];
    strcpy(data, str.data_);
    return *this;
  }

  CMyString &operator = (const CMyString &str) {
    if (this != &str) {
      CMyString strTemp(str);

      char *pTemp = strTemp.data_;
      strTemp.data_ = data_;
      data_ = pTemp;
    }
    return *this;
  }
  ~CMyString();
 private:
  char *data_;
};

// Lazy Singleton 2 lock safety.
class Singleton {
 public:
  static Singleton& getInstance() {
    if (!Instance) {
      lock();
      if (!Instance) {
        Instance = new Singleton();
      }
    }
    return *Instance;
  }
 private:
  Singleton();
  Singleton(const Singleton &s);
  Singleton &operator = (const Singleton &s);
  ~Singleton();

  static Singleton *Instance;
}

// Meyers Singleton
class Singleton {
 public: 
  static Singleton &GetInstance() {
    static Singleton instance;
    return instance;
  }
 private:
  Singleton();
  Singleton(const Singleton &);
  Singleton &operator=(const Singleton &);
  ~Singleton();
}

// Array back to pointer
template<typename T, int n>
void Print(T (&arr)[n]) {
  for (int i = 0; i < n; i ++) {
    printf("%d", arr[i]);
  }
}


// transform int to char *
void PrintToMax(int n) {
  if (n <= 0) {
    return;
  }

  char *number = new char[n + 1];
  memset(number, '0', n);
  number[n] = '\0';

  delete[] number;
}

bool Increment(char *num) {
  int length = strlen(num);
  bool flag = false;
  int take = 0;
  for (int i = length - 1; i >= 0; i --) {
    int sum = num[i] - '0' + take;
    if (i == length - 1) {
      sum ++;
    }
    if (sum >= 10) {
      if (i == 0) {
        flag = true;
      } else {
        sum -= 10;
        take = 1;
        num[i] = '0' + sum;
      }

    } else {
      num[i] = '0' + sum;
      break;
    }
  }
}