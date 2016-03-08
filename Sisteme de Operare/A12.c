/*
*   A12. (4 puncte) Scrieti un program care numara aparitiile unui sir de caractere
*  ca subcuvant in alt sir de caractere (cele doua siruri sunt date ca argumente
*  in linia de comanda). De fiecare data cand se verifica daca primul sir apare
*  ca subcuvant incepand de pe o pozitie, verificarea se va face de catre un 
*   proces fiu (obtinut cu fork) iar procesul tata nu asteapta ca acesta sa se
*  termine pentru a initia o cautare incepand de la o alta pozitie - astfel
*  verificarile au loc in paralel. Fiecare proces fiu returneaza 0 = nu s-a 
*  verificat (nu apare ca subcuvant de la pozitia respectiva), 1 = s-a verificat.
*  Dupa initierea tuturor cautarilor, procesul tata asteapta sa i se termine
*  toti fii si aduna codurile lor de retur - acesta valoarea se afisaza (este
*  numarul de aparitii ca subcuvant). 
*/

#include <sys/types.h>
#include <sys/unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 100
#define VERIFIED 1

int main(int argc, char *argv[])
{
   char str[BUFSIZE], substr[BUFSIZE];
   pid_t pid, wpid;
   int status = 0;
   size_t occurs = 0;

   if(argc!=3){
      printf("Insufficient arguments specified.\n");
      exit(EXIT_FAILURE);
   }

   strncpy(str, argv[1], sizeof(str));
   str[BUFSIZE-1] = '\0';
   strncpy(substr, argv[2], sizeof(substr));
   substr[BUFSIZE-1] = '\0';

   for(size_t i=0, length=strlen(str); i<length; ++i){
      pid = fork();

      if(pid == -1){
         fprintf(stderr, "Fork failed!\n");
         perror("Reason");
         exit(EXIT_FAILURE);
      }
      else if(pid == 0){  /* if pid is 0, it means we're in the child process */
        if(!strncmp(str+i, substr, strlen(substr)))
            return VERIFIED;
          else
            return !VERIFIED;
      }
   }

   while((wpid = wait(&status)) != -1){   /* i.e. while there's a child process available */
      if(WIFEXITED(status)){
         if(WEXITSTATUS(status)){
            printf("Child process %ld found an instance of \"%s\"\n",
                   (long) wpid, substr);
            ++occurs;
         }
      }
      else
         fprintf(stderr, "Child process %ld didn't end normally\n", (long) wpid);
   }

   printf("Total number of occurrences: %zu\n", occurs);

   return 0;
}
