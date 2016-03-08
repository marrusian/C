#define _XOPEN_SOURCE 500
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

int main(int argc, char *argv[])
{
   char *t1, *t2;

   for(int j=1; j<argc; ++j){
     if(!(t1 = strdup(argv[j])))
        errExit("strdup()");
  
     if(!(t2 = strdup(argv[j])))
        errExit("strdup()");

     printf("%s ==> %s + %s\n", argv[j], dirname(t1), basename(t2));
    
     free(t1);
     free(t2);
   }

   exit(EXIT_SUCCESS);
}

