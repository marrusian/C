#include<stdio.h>
#include<stdlib.h>

int main(void)
{
   int urn[5] = {100,200,300,400,500};
   int *ptr1, *ptr2, *ptr3;

   ptr1 = urn;
   ptr2 = &urn[2];

   printf("pointer value, dereferenced pointer, pointer address:\n");
   printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",
         (void*)ptr1, *ptr1, (void*)&ptr1);
   
   // Pointer addition
   ptr3 = ptr1 + 4;

   printf("\nadding an int to a pointer:\n");
   printf("ptr1 + 4 = %p, *(ptr1 + 3) = %d\n", (void*)(ptr1+4), *(ptr1+3));

   ++ptr1;
   printf("\nvalues after ++ptr1:\n");
   printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",
         (void*)ptr1, *ptr1, (void*)&ptr1);

   --ptr2;
   printf("\nvalues after --ptr2:\n");
   printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",
         (void*)ptr2, *ptr2, (void*)&ptr2);

   --ptr1;
   ++ptr2;
   printf("\nPointers reset to original values:\n");
   printf("ptr1 = %p, ptr2 = %p\n", (void*)ptr1, (void*)ptr2);

   printf("\nsubstracting one pointer from another:\n");
   printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n",
         (void*)ptr2, (void*)ptr1, ptr2-ptr1);

   printf("\nsubstracting an int from a pointer:\n");
   printf("ptr3 = %p, ptr3 - 2 = %p\n", (void*)ptr3, (void*)(ptr3-2));

   return 0;
}