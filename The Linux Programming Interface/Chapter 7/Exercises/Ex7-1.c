/*
*  7-1. Modify the program in Listing 7-1 (free_and_sbrk.c) to print out the current value of
* the program break after each execution of malloc(). Run the program specifying a
* small allocation block size. This will demonstrate that malloc() doesn’t employ sbrk()
* to adjust the program break on each call, but instead periodically allocates larger
* chunks of memory from which it passes back small pieces to the caller.
*/

#define _XOPEN_SOURCE 600
#include <stdlib.h>
#include <unistd.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

#ifndef MAX_ALLOCS
#define MAX_ALLOCS 1000000
#endif

int main(int argc, char *argv[])
{
   char *ptr[MAX_ALLOCS];
   int freeStep, freeMin, freeMax, blockSize, numAllocs;

   if(argc<3 || !strcmp(argv[1], "--help"))
      usageErr("%s num-allocs block-size [step [min [max]]]\n", argv[0]);

   printf("Current page size is: %zu\n", sysconf(_SC_PAGESIZE));
   numAllocs = getInt(argv[1], GN_GT_0, "num-allocs");
   if(numAllocs > MAX_ALLOCS)
      cmdLineErr("num-allocs > %d\n", MAX_ALLOCS);

   blockSize = getInt(argv[2], GN_GT_0|GN_ANY_BASE, "block-size");

   freeStep = (argc>3)? getInt(argv[3], GN_GT_0, "step") : 1;
   freeMin  = (argc>4)? getInt(argv[4], GN_GT_0, "min")  : 1;
   freeMax  = (argc>5)? getInt(argv[5], GN_GT_0, "max")  : numAllocs;

   if(freeMax>numAllocs)
      cmdLineErr("free-max > num-allocs\n");
 
   printf("Initial program break:        %10p\n", (void*) sbrk(0));

   printf("Allocating %d*%d bytes\n", numAllocs, blockSize);
   for(int j=0; j<numAllocs; ++j){
      printf("Program break %d is:       %10p\n", j, (void*)sbrk(0));
      ptr[j] = malloc(blockSize);
      if(!ptr[j])
         errExit("malloc");
   }

   printf("Program break is now:         %10p\n", (void*) sbrk(0));

   printf("Freeing blocks from %d to %d in steps of %d\n",
              freeMin, freeMax, freeStep);
   for(int j=freeMin-1; j<freeMax; j+=freeStep)
      free(ptr[j]);

   printf("After free(), program break is: %10p\n", (void*) sbrk(0));

   exit(EXIT_SUCCESS);
}