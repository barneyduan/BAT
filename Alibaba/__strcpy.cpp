// Author: duanlian1210@163.com (Duan Lian)
#ifndef __STRCPY_H__
#define __STRCPY_H__

#include <assert.h>
#include <iostream>

using namespace std;

char *__strcpy(char *strDest, const char *strSrc) {
  assert((strDest != nullptr) && (strSrc != nullptr));
  char *address = strDest;
  while((*strDest++ = *strSrc++) != '\0');
  return address;
}

int __strlen(const char *s) {
  assert(s != nullptr);
  int t = 0;
  while (*s++ != '\0') {
    t ++;
  }
  return t;
}

char *__strcat(char *des, const char *src) {
  assert(des != nullptr && src != nullptr);
  char *address = des;
  while (*des != '\0') des++;
  while ((*des++ = *src++) != '\0');
  return address;
}

int strcmp(const char *s1, const char *s2) {
  assert(s1 != nullptr && s2 != nullptr);
  while (*s1 == *s2) {
    if (*s1 == '\0') {
      return 0;
    }
    s1++;
    s2++;
  }
  return *s1 - *s2;
}

int main() {
  const char *s = "hahaha";
  int x = __strlen(s);
  cout << x << endl;

  char src[50], dest[50];
  __strcpy(src, "This is source");
  __strcpy(dest, "This is dest");
  char * ss = __strcat(dest, src);

  cout << ss << endl;
}

#endif