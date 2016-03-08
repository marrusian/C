/* 
* 1. Find out what your system does with integer overflow, floating-point overflow, and
* floating-point underflow by using the experimental approach;
*/

#include<stdio.h>
#include<limits.h> // UINT_MAX, INT_MAX;
#include<float.h>  // FLT_MAX, FLT_MIN;

int main(void)
{
  unsigned int mui = UINT_MAX;
  int mi = INT_MAX;
  float mfo = FLT_MAX;
  float mfu = FLT_MIN;
  
  printf("Initial values:\n");
  printf("mui = %u\t mi = %d\t\nmfo = %e\t mfu = %e\n", mui, mi, mfo, mfu);
 
  mui+=1;
  mi+=1;
  mfo*=2.0f;
  mfu/=2.0f;

  printf("Modified values:\n");
  printf("mui = %u\t mi = %d\t\nmfo = %e\t mfu = %e\n", mui, mi, mfo, mfu);

  return 0;
}