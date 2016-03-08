#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

// BIT-FIELD CONSTANTS
// Line styles
#define SOLID  0
#define DOTTED 1
#define DASHED 2

// Primary colors
#define BLUE  4
#define GREEN 2
#define RED   1
// Mixed colors
#define BLACK 0
#define YELLOW (RED|GREEN)
#define MAGENTA (RED|BLUE)
#define CYAN (GREEN|BLUE)
#define WHITE (RED|GREEN|BLUE)

// BITWISE CONSTANTS
#define OPAQUE       0x1
#define FILL_BLUE    0x8
#define FILL_GREEN   0x4
#define FILL_RED     0x2
#define FILL_MASK    0xE
#define BORDER       0x100
#define BORDER_BLUE  0x800
#define BORDER_GREEN 0x400
#define BORDER_RED   0x200
#define BORDER_MASK  0xE00
#define B_SOLID      0
#define B_DOTTED     0x1000
#define B_DASHED     0x2000
#define STYLE_MASK   0x3000

const char *colors[8] = {"black", "red", "green", "yellow",
                         "blue", "mangeta", "cyan", "white"};

typedef struct box_props{
   _Bool opaque              : 1;
   unsigned int fill_color   : 3; 
   unsigned int              : 4;
   _Bool show_border         : 1;
   unsigned int border_color : 3;
   unsigned int border_style : 2;
   unsigned int              : 2;
} Box_Props;

typedef union{
   struct box_props st_view;
   unsigned short us_view;
} Views;

void show_settings(const Box_Props *pb);
void show_settings1(unsigned short);
char *itobs(int n, char *ps);

int main(void)
{
   Views box = {{true, YELLOW, true, GREEN, DASHED}};
   char bin_str[CHAR_BIT*sizeof(unsigned int)+1];

   puts("Original box settings");
   show_settings(&box.st_view);

   puts("\nBox settings using unsigned int view:");
   show_settings1(box.us_view);
   printf("bits are %s\n", itobs(box.us_view, bin_str));

   box.us_view &= ~FILL_MASK;  // Clear fill bits
   box.us_view |= (FILL_BLUE|FILL_GREEN);
   box.us_view ^= OPAQUE;      // Toogle opacity
   box.us_view |= BORDER_RED;  // wrong approach
   box.us_view &= ~STYLE_MASK; // Clear style bits
   box.us_view |= B_DOTTED;    

   puts("\nModified box settings:");
   show_settings(&box.st_view);
   puts("\nBox settings using unsigned int view");
   show_settings1(box.us_view);
   printf("bits are %s\n", itobs(box.us_view, bin_str));

   return 0;
}

void show_settings(const Box_Props *pb)
{
   printf("Box is %s.\n",
          pb->opaque? "opaque" : "transparent");
   printf("The fill color is %s.\n", colors[pb->fill_color]);
   printf("Border %s.\n",
          pb->show_border? "shown" : "not shown");
   printf("The border color is %s.\n", colors[pb->border_color]);
   printf("The border style is: ");
   switch(pb->border_style){
      case SOLID : puts("solid");  break;
      case DOTTED: puts("dotted"); break;
      case DASHED: puts("dashed"); break;
      default    : puts("unknown type");
   }
}

void show_settings1(unsigned short us)
{
   printf("Box is %s.\n",
          us&OPAQUE? "opaque" : "transparent");
   printf("The fill color is %s.\n", colors[(us>>1)&7]);
   printf("Border %s.\n",
          us&BORDER? "shown" : "not shown");
   printf("The border color is %s.\n", colors[(us>>9)&7]);
   printf("The border style is: ");
   switch(us&STYLE_MASK){
      case B_SOLID : puts("solid");  break;
      case B_DOTTED: puts("dotted"); break;
      case B_DASHED: puts("dashed"); break;
      default    : puts("unknown type");
   }
}

char *itobs(int n, char *ps)
{
   static const int size = CHAR_BIT*sizeof(int);
  
   for(int i=size-1; i>=0; --i, n>>=1)
      ps[i] = (1&n)+'0';
   ps[size] = '\0';

   return ps;
}