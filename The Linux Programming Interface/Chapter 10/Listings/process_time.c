#include <sys/types.h>
#include <unistd.h>
#include <sys/times.h>
#include <time.h>    
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

static void displayProcessTime(const char *msg);

int main(int argc, char *argv[])
{
   int numCalls;

   printf("CLOCKS_PER_SEC=%jd, sysconf(_SC_CLK_TCK)=%jd\n\n",
          (intmax_t) CLOCKS_PER_SEC, (intmax_t) sysconf(_SC_CLK_TCK));

   displayProcessTime("At program start:\n");

   numCalls = (argc>1)? getInt(argv[1], GN_GT_0, "num-calls") : 100000000;
   for(int j=0; j<numCalls; ++j)
      getppid();

   displayProcessTime("After getppid() loop:\n");

   exit(EXIT_SUCCESS);
}

static void displayProcessTime(const char *msg)
{
   struct tms t;
   clock_t clockTime;
   static long clockTicks = 0;

   if(msg)
      printf("%s", msg);

   if(!clockTicks){     /* Fetch clock ticks on first call */
      if((clockTicks = sysconf(_SC_CLK_TCK)) == -1)
         errExit("sysconf()");      
   }

   if((clockTime = clock()) == (clock_t)-1)
      errExit("clock()");

   printf("        clock() returns: %jd clocks-per-sec (%.2f secs)\n",
          (intmax_t) clockTime, (double) clockTime/CLOCKS_PER_SEC);

   if(times(&t) == (clock_t)-1)
      errExit("times");

   printf("        times() yields: user CPU = %.2f; system CPU: %.2f\n",
          (double) t.tms_utime / clockTicks,
          (double) t.tms_stime / clockTicks);
}