/*
*  3. Polar coordinates describe a vector in terms of magnitude and the counterclockwise angle
* from the x-axis to the vector. Rectangular coordinates describe the same vector in terms
* of x and y components (see Figure 16.3). Write a program that reads the magnitude and
* angle (in degrees) of a vector and then displays the x and y components. The relevant
* equations are these:
*    x = r cos A
*    y = r sin A
*  To do the conversion, use a function that takes a structure containing the polar
* coordinates and returns a structure containing the rectangular coordinates (or use
* pointers to such structures, if you prefer).
*/

#include<stdio.h>
#include<math.h>

typedef struct rect_v{
   double x;
   double y;
} Rect_V;

typedef struct polar_v{
   double magnitude;
   double angle;
} Polar_V;

Rect_V polar_to_rect(Polar_V);

int main(void)
{
   Polar_V input;
   Rect_V result;

   puts("Enter a vector's magnitude and angle: ");
   while(scanf("%lf%lf", &input.magnitude, &input.angle)==2){
      result = polar_to_rect(input);
      printf("Coord(X) = %0.3f, Coord(Y) = %0.3f\n",
              result.x, result.y);
      puts("\nEnter another vector's magnitude and angle('q' to quit): ");
   } 
   puts("Bye.");

   return 0;
}

Rect_V polar_to_rect(Polar_V pv)
{
   #define PI (4.0*atan(1))
   #define DEG_TO_RAD(X) ((X)*(PI/180.0))
   Rect_V rv;
   register double A = DEG_TO_RAD(pv.angle);
   
   rv.x = pv.magnitude*cos(A);
   rv.y = pv.magnitude*sin(A);

   return rv;   
}