#include <sys/types.h>
#include <stdint.h>
#include <locale.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

#define SECONDS_IN_TROPICAL_YEAR (365.24219 * 24 * 60 * 60)

int main(int argc, char *argv[])
{
   time_t t;
   struct tm *gmp, *locp;
   struct tm gm, loc;
   struct timeval tv;

   if((t = time(NULL)) == (time_t)-1)
      errExit("time()");

   printf("Seconds since the Epoch (1 Jan 1970): %jd", (intmax_t) t);
   printf(" (about %6.3f years)\n", t/SECONDS_IN_TROPICAL_YEAR);

   if(gettimeofday(&tv, NULL) == -1)
      errExit("Gettimeofday()");
   printf("  gettimeofday() returned %jd secs, %jd microsecs\n",
           (intmax_t) tv.tv_sec, (intmax_t) tv.tv_usec);

   if(!(gmp = gmtime(&t)))
      errExit("gmtime()");

   gm = *gmp;  /* Save local copy, since *gmp may be modified by asctime() or gmtime() */
   printf("Broken down by gmtime():\n");
   printf("  year=%d mon=%d mday=%d hour=%d min=%d sec=%d ", gm.tm_year,
           gm.tm_mon, gm.tm_mday, gm.tm_hour, gm.tm_min, gm.tm_sec);
   printf("wday=%d yday=%d isdst=%d\n", gm.tm_wday, gm.tm_yday, gm.tm_isdst);

   if(!(locp = localtime(&t)))
      errExit("localtime()");

   loc = *locp;   /* Save local copy */
   printf("Broken down by localtime():\n");
   printf("  year=%d mon=%d mday=%d hour=%d min=%d sec=%d ", loc.tm_year,
           loc.tm_mon, loc.tm_mday, loc.tm_hour, loc.tm_min, loc.tm_sec);
   printf("wday=%d yday=%d isdst=%d\n\n", loc.tm_wday, loc.tm_yday, loc.tm_isdst);

   printf("asctime() formats the gmtime() value as: %s", asctime(&gm));
   printf("ctime() formats the time() value as:     %s", ctime(&t));

   printf("mktime() of gmtime() value:    %jd secs\n", (intmax_t) mktime(&gm));
   printf("mktime() of localtime() value: %jd secs\n", (intmax_t) mktime(&loc));

   exit(EXIT_SUCCESS);
}