#include <sys/types.h>
#include <stdint.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

#define BUF_SIZE 256

int main(int argc, char *argv[])
{
   time_t t;
   struct tm *loc;
   char buf[BUF_SIZE];
 
   if(!setlocale(LC_ALL, ""))
      errExit("setlocale()");        /* Use locale settings in conversions */

   if((t = time(NULL)) == -1)
      errExit("time()");

   printf("ctime() of time() value is:  %s", ctime(&t));
   if(!(loc = localtime(&t)))
      errExit("localtime()");
 
   printf("asctime() of local time is:  %s", asctime(loc));
   
   if(!strftime(buf, BUF_SIZE, "%A, %d %B %Y, %H:%M:%S %Z", loc))
      fatal("strftime() returned 0");
   printf("strftime() of local time is: %s\n\n", buf);

   exit(EXIT_SUCCESS);
}
