// Author: duanlian1210@163.com
#ifndef REPLACE_SPACE_H__
#define REPLACE_SPACE_H__

#include <cassert>
#include <iostream>

using namespace std;

char *__strcpy(char *des, const char *src) {
  assert(des != NULL && src != NULL);
  char *address = des;
  while((*des++ = *src++) != '\0');
  return address;
}

void replaceSpace(char *str,int length) {
  if (str == NULL || length < 0) {
    return;
  }
  int space_num = 0;
  int old_len = 0;
  char *add = str;
  while (*str != '\0') {
    old_len ++;
    if (*str == ' ') {
      space_num ++;
    }
    str ++;
  }
  int new_len = old_len + 1 + 2 * space_num;
  if (new_len > length) {
    return;
  }
  str = add;
  char *tmp = new char[old_len + 1];
  char *head = __strcpy(tmp, str);
  while (*tmp != '\0') {
    if (*tmp == ' ') {
      *str++ = '%';
      *str++ = '2';
      *str++ = '0';
      tmp ++;
    } else {
      *str++ = *tmp++;
    }

  }
  *str = '\0';
  str = add;

  /*****
   * delete should be head of pointer!!!!
   */
  delete[] head;
  return;
}



char *__strcat(char *des, const char *src) {
  assert(des != NULL && src != NULL);
  char *address = des;
  while(*des != '\0') des++;
  while((*des++ = *src++) != '\0');
  return address;
}

int main() {
  char s[50];
  cin.getline(s, 50);
  replaceSpace(s, 50);
  cout << s <<endl;
}

#endif