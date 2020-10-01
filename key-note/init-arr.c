/* This Program is basically to make the understanding about the 
   array of the Global type and the wway to print their values */
#include <stdio.h>    //Header File for input and output

int global[2];  // Global type of Array variables 
int global2[2] = {1};   // the value assigned 1 at index 2 of another array of global type.

int main() 
{
  int local[2];
  int local2[2] = {1};
  
  // Printing of the All necessary values that we want:
  
  printf("global[0]: %d\n", global[0]); 
  printf("global2: {%d, %d}\n", global2[0], global2[1]);
  printf("local[0]: %d\n", local[0]);
  printf("local2: {%d, %d}\n", local2[0], local2[1]);
  
  return 0;
}
