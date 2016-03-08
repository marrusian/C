#include<stdio.h>
#include<inttypes.h> // supports PORTABLE types

int main(void)
{
  int64_t me64 = 459339454593394;

  printf("First, assume int64_t is int: ");
  printf("me64 = %d\n", me64);
  printf("Next, let's not make any assumptions.\n");
  printf("Instead, use a \"macro\" from inttypes.h: ");
  printf("me64 = %"PRId64"\n", me64);

  return 0;
}

