#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int static_store = 30;
const char *pcg = "String Literal";

int main(void)
{
   int auto_store = 40;
   char auto_string[] = "Auto char Array";
   int *pi;
   char *pcl;

   pi = (int*) malloc(sizeof(int));
   *pi = 35;
   
   pcl = (char*) malloc(strlen("Dynamic String")+1);
   strcpy(pcl, "Dynamic String");

   printf("static_store: %d at %p\n", static_store, (void*)&static_store);
   printf("  auto_store: %d at %p\n", auto_store, (void*)&auto_store);
   printf("         *pi: %d at %p\n", *pi, (void*)pi); 
   printf("  %s at %p\n", pcg, (void*)pcg);
   printf(" %s at %p\n", auto_string, (void*)auto_string);
   printf("  %s at %p\n", pcl, (void*)pcl);
   printf("   %s at %p\n", "Quoted String", (void*)"Quoted String");
   free(pi);
   free(pcl);

   return 0;
}