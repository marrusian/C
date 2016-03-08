/*
*  6. Design a bit-field structure that holds the following information:
* Font ID: A number in the range 0–255
* Font Size: A number in the range 0–127
* Alignment: A number in the range 0–2 represented the choices Left, Center, and Right
* Bold: Off (0) or on (1)
* Italic: Off (0) or on (1)
* Underline: Off (0) or on (1)
* Use this structure in a program that displays the font parameters and uses a looped menu
* to let the user change parameters. For example, a sample run might look like this:
*
*    ID SIZE ALIGNMENT  B   I   U
*     1   12   left    off off off
*
*  f)change font   s)change size    a)change alignment
*  b)toggle bold   i)toggle italic  u)toogle underline
*  q)quit
*  s
*  Enter font size (0-127): 36
*
*    ID SIZE ALIGNMENT  B   I   U
*     1   36   left    off off off
*  f)change font   s)change size   a)change alignment
*  b)toggle bold   i)toggle italic u)toogle underline
*  q)quit
*  a
*  Select alignment:
*  l)left c)center r)right
*  r
*
*    ID SIZE ALIGNMENT  B   I   U
*     1   36   right   off off off
*
*/

#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
   unsigned int id:    8;
   unsigned int size:  7;
   unsigned int align: 2;
   unsigned int bold:  1;
   unsigned int itlc:  1;
   unsigned int undln: 1;
} Font;

/* Menus */
void show_menu(void);
bool main_range(int ch);

void show_font(Font *ptf);


/* Principal Functions */
void change_font(Font *ptf);
bool font_id_range(int val);

void change_size(Font *ptf);
bool font_sz_range(int val);

void change_align(Font *ptf);
bool fnt_align_range(int ch);

void toogle_fnt_style(Font *ptf, int ch);

// Utility functions
int get_int(const char *err_msg, bool (*pfun)(int));
int get_choice(const char *err_msg, bool (*pfun)(int));
char *s_gets(char *st, int n);

int main(void)
{
   #define QUIT 'q'
   int choice = 0;
   Font fto = {1, 36, 0, false, false, false};
   
   show_font(&fto);
   show_menu();
   while(!feof(stdin)&&
        (choice=get_choice("Please select f, s, a, b, i, u, or q: ", main_range))!=QUIT){
     
      switch(choice){
         case 'f': change_font(&fto);  break;
         case 's': change_size(&fto);  break;
         case 'a': change_align(&fto); break;
         case 'b':
         case 'i':
         case 'u': toogle_fnt_style(&fto, choice); break;
      }

      show_font(&fto);
      show_menu();
   }
   puts("Bye!");

   return 0;
}

void change_font(Font *ptf)
{
   printf("Enter font id [0-255]: ");
   ptf->id = get_int("Please enter an integer in range [0-255]: ", font_id_range);
}

void change_size(Font *ptf)
{
   printf("Enter font size [0-127]: ");
   ptf->size = get_int("Please enter an integer in range [0-127]: ", font_sz_range);
}

void change_align(Font *ptf)
{
   #define LEFT   0
   #define CENTER 1
   #define RIGHT  2

   int ch = 0;
   printf("Select alignment:\n"
          "l)left  c)center  r)right\n");
   ch = get_choice("Please select l, c, or r: ", fnt_align_range);

   switch(ch){
      case 'l': ptf->align = LEFT;   break;
      case 'c': ptf->align = CENTER; break;
      case 'r': ptf->align = RIGHT;  break;
   }
}

void toogle_fnt_style(Font *ptf, int ch)
{
   #define BOLD      'b'
   #define ITALIC    'i'
   #define UNDERLINE 'u'  

   switch(ch){
      case BOLD:      ptf->bold^=1;  break;
      case ITALIC:    ptf->itlc^=1;  break;
      case UNDERLINE: ptf->undln^=1; break;
      default: printf("Unknown font style\n");
   }    
}

char *s_gets(char *st, int n)
{
   char *ret_val, *find;

   if((ret_val=fgets(st, n, stdin))){
      if((find=strchr(st,'\n')))
         *find = '\0';
      else
         while(getchar()!='\n')
            continue;
   }

   return ret_val;
}

bool font_sz_range(int val){return val<0 || val>127;}
bool font_id_range(int val){return val<0 || val>255;}

int get_int(const char *err_msg, bool (*pfun)(int))
{
   int val = 0;
   char buffer[10] = {0};
   char *endptr;

   do{
      if(buffer[0])
         printf("%s", err_msg);
      s_gets(buffer, sizeof(buffer));
      val = strtol(buffer, &endptr, 10);
   }while(!feof(stdin)&&(*endptr || !buffer[0] || pfun(val)));
   
   return val;
}

bool main_range(int ch){return !strchr("abfisuq", ch);}
bool fnt_align_range(int ch){return !strchr("lcr", ch);}

int get_choice(const char *err_msg, bool (*pfun)(int))
{
   int ch = 0;
   
   do{
      if(ch)
         printf("%s", err_msg);
      s_gets((char*)&ch, 2);
   }while(!feof(stdin) && (!ch || pfun(ch)));

   return ch;
}

void show_font(Font *ptf)
{
   #define LEFT   0
   #define CENTER 1
   #define RIGHT  2

   printf("\n%3s SIZE ALIGNMENT %3s %3s %3s\n",
          "ID", "B", "I", "U");
   printf("%3u", ptf->id);
   printf("%5u", ptf->size);
   switch(ptf->align){
      case LEFT:   printf("%7s    ", "left");   break;
      case CENTER: printf("%9s  ", "center"); break;
      case RIGHT:  printf("%8s   ", "right");  break;
      default:     printf("Unknown alignment");
   }
   printf("%4s", ptf->bold?  "on" : "off");
   printf("%4s", ptf->itlc?  "on" : "off");
   printf("%4s", ptf->undln? "on" : "off");
}

void show_menu(void)
{
   printf("\nf)change font  s)change size    a)change alignment\n"
          "b)toggle bold  i)toggle italic  u)toggle underline\n"
          "q)quit\n");
}