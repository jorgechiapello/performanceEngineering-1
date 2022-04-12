// Copyright (c) 2012 MIT License by 6.172 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void swap(int * i, int * j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}

int main() {
  int k = 1;
  int m = 2;
    // What does this print?
  printf("before swap: k = %d, m = %d\n", k, m);
  
  swap(&k, &m);
  
  // What does this print?
  printf("after swap: k = %d, m = %d\n", k, m);

  return 0;
}
