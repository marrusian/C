/*
*  7-2. (Advanced) Implement malloc() and free().
*/

#define _BSD_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../tlpi-dist/lib/tlpi_hdr.h"

typedef struct free_mem_block{
   size_t block_length;
   struct free_mem_block *prev;
   struct free_mem_block *next;
} FreeBlock;

#define ALIGNMENT 8            // 8-bits boundary
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~(ALIGNMENT-1))
#define HEADER_SIZE (ALIGN(sizeof(size_t)))
#define ALLOC_SIZE 0x20000     // 128kB
#define MIN_BLOCK_SIZE ALIGN(sizeof(FreeBlock))

FreeBlock *heap_start(void);
void init_heap(void);
void *find_fit(size_t length);
void *my_malloc(size_t size);
void  my_free(void* ptr);

int main(int argc, char *argv[])
{
   int *parr = (int*) my_malloc(337533536*sizeof(int));
   if(!parr)
     errExit("my_malloc()");

   parr[5] = parr[8] = 55;
   printf("%10p\n", (void*)parr);

   double *pdrr = (double*) my_malloc(5*sizeof(double));
   printf("%10p\n", (void*)pdrr);
   my_free(parr);

   char *ptr = (char*) my_malloc(100*sizeof(char));
   printf("%10p\n", (void*)ptr);

   char *pttr = (char*) my_malloc(100*sizeof(char));
   printf("%10p\n", (void*)pttr);

   my_free(pdrr);
   my_free(ptr);

   exit(EXIT_SUCCESS);
}

FreeBlock *heap_start(void)
{
   static void *head = NULL;

   if(!head)
      head = sbrk(0);

   return (FreeBlock*)head;
}

void init_heap(void){
   heap_start();

   FreeBlock *bp = (FreeBlock*) sbrk(ALIGN(sizeof(FreeBlock)));
   bp->block_length = 0;
   bp->prev = bp;
   bp->next = bp;
}

void *find_fit(size_t length)
{
   FreeBlock *bp = heap_start();
   FreeBlock *end = bp;

   for(bp=bp->next; bp!=end; bp=bp->next){
      if(bp->block_length>=length){
         bp->next->prev = bp->prev;
         bp->prev->next = bp->next;
         return bp;
      }
   }

   return NULL;
}

void my_free(void *ptr)
{
   FreeBlock *header = (FreeBlock*)((char*)ptr - HEADER_SIZE);
   FreeBlock *free_list_head = heap_start();

   // Add freed block to the free list just after head
   header->next = free_list_head->next;
   header->prev = free_list_head;
   free_list_head->next = free_list_head->next->prev = header;
}

void *my_malloc(size_t size)
{
   static int heap_init = 0;

   if(!heap_init){
      heap_init = 1;
      init_heap();
   }

   size_t *header;
   size_t block_size = ALIGN(size + HEADER_SIZE);

   block_size = (block_size < MIN_BLOCK_SIZE)? MIN_BLOCK_SIZE : block_size;

   if((header = (size_t*)find_fit(block_size))){
      if(*header > block_size){
         ((FreeBlock*)((char*)header+block_size))->block_length = *header-block_size;
          my_free((char*)header + block_size + HEADER_SIZE);
          *header = block_size;
      }
   }
   else{
      size_t total_alloc = 0;

      header = sbrk(0);
      while(block_size >= total_alloc)
        total_alloc += ALLOC_SIZE;

      if(sbrk(total_alloc) == (void*)-1)
         return NULL;

      ((FreeBlock*)((char*)header+block_size))->block_length = total_alloc-block_size;
      my_free((char*)header + block_size + HEADER_SIZE);
   }

   return (char*)header + HEADER_SIZE;
}
