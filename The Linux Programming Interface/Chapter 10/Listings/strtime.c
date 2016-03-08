#define _XOPEN_SOURCE
#include <sys/types.h>
#include <stdint.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

#define SBUF_SIZE 1024

int main(int argc, char *argv[])
{
   struct tm tm = {0};
   char sbuf[SBUF_SIZE];
   char *ofmt;
 
   if(argc<3 || !strcmp(argv[1], "--help"))
      usageErr("%s input-date-time in-format [out-format]\n", argv[0]);

   if(!setlocale(LC_ALL, ""))
      errExit("setlocale()");           /* Use locale settings in conversions */

   memset(&tm, 0, sizeof(struct tm));   /* Initialize 'tm' */
   if(!strptime(argv[1], argv[2], &tm))
      fatal("strptime()");

   tm.tm_isdst = -1;
   printf("Calendar time (seconds since Epoch): %jd\n", (intmax_t) mktime(&tm));

   ofmt = (argc>3)? argv[3] : "%H:%M:%S %A, %d %B %Y %Z";
   if(!strftime(sbuf, SBUF_SIZE, ofmt, &tm))
      fatal("strftime() returned 0");
   printf("strftime() yields: %s\n\n", sbuf);

   exit(EXIT_SUCCESS);
}