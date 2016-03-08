#include <stdlib.h>
#include <stdio.h>

extern char **environ;

// Alternatively: int main(int argc, char *argv[], char *envp[])
int main(int argc, char *argv[])
{
   char **ep;

   for(ep = environ; *ep!=NULL; ++ep)
      puts(*ep);

   exit(EXIT_SUCCESS);
}