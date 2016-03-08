#include<stdio.h>
#include"Ex2h.h"
#define EU 0
#define US 1

static int mode;
static float distance;
static float fuel_consumed;

void set_mode(int input_mode){
   if(input_mode!=EU && input_mode!=US)
      printf("Invalid mode specified. Mode %d(%s) used.\n",
             mode, mode? "US" : "EU");
   else
      mode = input_mode;
}

void get_info(void)
{
   printf("Enter distance traveled in %s: ", mode? "miles" : "kilometers");
   while(scanf("%f", &distance) && distance<0){
      puts("Invalid distance. Try again!");
      printf("Enter distance traveled in %s: ", mode? "miles" : "kilometers");
   }

   printf("Enter fuel consumed in %s: ", mode? "gallons" : "liters");
   while(scanf("%f", &fuel_consumed) && fuel_consumed<0){
      puts("Invalid fuel consumption. Try again!");
      printf("Enter fuel consumed in %s: ", mode? "gallons" : "liters");
   }
}

void show_info(void)
{
   if(mode==EU)
      printf("Fuel consumption is %.2f liters per 100 km.\n", 
             (fuel_consumed/distance)*100.0f);
   else if(mode==US)
      printf("Fuel consumption is %.2f miles per gallon.\n",
             distance/fuel_consumed);
}