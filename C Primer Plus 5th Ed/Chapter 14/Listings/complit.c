#include<stdio.h>

#define MAXTITL 40+1
#define MAXAUTL 30+1

struct book{
   char title[MAXTITL];
   char author[MAXAUTL]; 
   float value;
};

int main(void)
{
   struct book readfirst;
   int score;

   printf("Enter test score: ");
   scanf("%d", &score);

   if(score>=84)
      readfirst = (struct book) {"Crime and Punishment",
                                 "Fyodor Dostoyevsky",
                                 11.25};
   else
      readfirst = (struct book) {"Mr. Bouncy's Nice Hat",
                                 "Fred Winsome",
                                 5.99};

   puts("Your assigned reading:");
   printf("%s by %s: $%.2f\n", readfirst.title,
          readfirst.author, readfirst.value);

   return 0;
}