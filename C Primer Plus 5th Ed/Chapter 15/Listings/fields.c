#include<stdio.h>
#include<stdbool.h>

// Line Styles
#define SOLID 0
#define DOTTED 1
#define DASHED 2

// Primary colors
#define RED 1
#define GREEN 2
#define BLUE 4
// Mixed colors
#define BLACK 0
#define YELLOW (RED|GREEN)
#define MAGENTA (RED|BLUE)
#define CYAN (GREEN|BLUE)
#define WHITE (RED|GREEN|BLUE)

const char *colors[8] = {"black", "red", "green", "yellow",
                         "blue", "magenta", "cyan", "white"};

typedef struct box_props{
   _Bool opaque              : 1;
   unsigned int fill_color   : 3;
   unsigned int              : 4;
   _Bool show_border         : 1;
   unsigned int border_color : 3;
   unsigned int border_style : 2;
   unsigned int              : 2;
} Box_Props;

void show_settings(const Box_Props *pb);

int main(void)
{
   Box_Props box = {true, YELLOW, true, GREEN, DASHED};
   
   printf("Original box settings:\n");
   show_settings(&box);

   box.opaque = false;
   box.fill_color = WHITE;
   box.border_color = MAGENTA;
   box.border_style = SOLID;

   printf("\nModified box settings:\n");
   show_settings(&box);

   return 0;
}

void show_settings(const Box_Props *pb)
{
   printf("Box is %s.\n",
          pb->opaque? "opaque" : "transparent");
   printf("The fill colors is %s\n", colors[pb->fill_color]);
   printf("Border %s.\n",
          pb->show_border? "shown" : "not shown");
   printf("The border color is %s\n", colors[pb->border_color]);
   printf("The border style is ");
   switch(pb->border_style){
      case SOLID : puts("solid"); break;
      case DOTTED: puts("dotted"); break;
      case DASHED: puts("dashed"); break;
      default    : puts("unknown type");
   }
}
