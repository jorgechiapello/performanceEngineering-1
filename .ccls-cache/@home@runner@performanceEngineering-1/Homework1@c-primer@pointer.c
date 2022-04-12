// Copyright (c) 2012 MIT License by 6.172 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// What is the type of argv? A vector is a one-dimensional array, and argv is a one-dimensional array of strings. Each string is one of the arguments that was passed to the program.
int main(int argc, char * argv[]) {  
  int i = 5;
  // The & operator here gets the address of i and stores it into pi
  int * pi = &i;
  // The * operator here dereferences pi and stores the value -- 5 --
  // into j.
  int j = *pi;

  char c[] = "6.172"; // string, an special array of char, with a \0 at the end
  char * pc = c;  // Valid assignment: c acts like a pointer to c[0] here (more precisely &c[0])
  char d = *pc;
  printf("char d = %c\n", d);  // What does this print? "6" the value being pointed to

  // compound types are read right to left in C.
  // pcp is a pointer to a pointer to a char, meaning that
  // pcp stores the address of a char pointer.
  char ** pcp;
  pcp = argv;  // Why is this assignment valid? argv is the same &argv[0], a pointer to a string (argv[0])
  printf("char ** pcp = %p\n", pcp);
  printf("char argv = %p\n", argv);
  printf("char &argv[0] = %p\n", &argv[0]);
  
  printf("char argv[1] = %s\n", argv[0]); // accessing the first string argument
  printf("char argv[1] = %c\n", argv[0][0]); 
  printf("char *argv[1] = %c\n", *argv[1]); // first char of the second argument
  printf("char **argv = %c\n", **argv); // double dereference to argv is the first char of the first string
  
  const char * pcc = c;  // pcc is a pointer to char constant
  // What is the type of pcc2? a pointer to a char constant, is the same as above as long as 
  // char and const are before *
  char const * pcc2 = c;  

  // For each of the following, why is the assignment:
  // *pcc = "7";  // invalid? no, char value is const
  // We can change pcc because the pointer is not constant
  pcc = "7"; // "7" is an string, a type of array
  pcc = *pcp;  // valid? yes, in pcp we had stored a pointer to argv[0]
  pcc = argv[0];  // valid? argv[0] is a pointer to an array
  
  char * const cp = c;  // cp is a const pointer to char
  // For each of the following, why is the assignment:
  // cp = *pcp;  // invalid? Yes, cp is a constant pointer so we can't change its value
  *cp = **pcp;  // Fix? Modifiying it to change the value referenced
  // cp = *argv;  // invalid? Yes, cp is a constant
  *cp = **argv; // to be fair, we assign argv to pcp earlier
  *cp = '!';  // valid? yes, becuase we are storing a char into a char variable
  
  const char * const cpc = c;  // cpc is a const pointer to char const
  // For each of the following, why is the assignment:
  // NONE is valid because both pointer and value are constant
  // cpc = *pcp;  // invalid?
  // cpc = argv[0];  // invalid?
  // *cpc = '@';  // invalid?

  return 0;
}
