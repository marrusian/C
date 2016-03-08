#include<stdio.h>
#include"Ex3h.h"
#define EU 0
#define US 1

int set_mode(int prev_mode, int current_mode){
   if(current_mode!=EU && current_mode!=US){
      printf("Invalid mode specified. Mode %d(%s) used.\n",
             prev_mode, prev_mode? "US" : "EU");
      return prev_mode;
   }

   return current_mode;
}

float get_distance(int mode)
{
   float distance;
   printf("Enter distance traveled in %s: ", mode? "miles" : "kilometers");
   while(scanf("%f", &distance) && distance<0){
      puts("Invalid distance. Try again!");
      printf("Enter distance traveled in %s: ", mode? "miles" : "kilometers");
   }
   
   return distance;
}

float get_fuel(int mode)
{  
   float fuel_consumed;
   printf("Enter fuel consumed in %s: ", mode? "gallons" : "liters");
   while(scanf("%f", &fuel_consumed) && fuel_consumed<0){
      puts("Invalid fuel consumption. Try again!");
      printf("Enter fuel consumed in %s: ", mode? "gallons" : "liters");
   }

   return fuel_consumed;
}

void show_consumption(float distance, float fuel_consumed, int mode)
{
   if(mode==EU)
      printf("Fuel consumption is %.2f liters per 100 km.\n", 
             (fuel_consumed/distance)*100.0f);
   else if(mode==US)
      printf("Fuel consumption is %.2f miles per gallon.\n",
             distance/fuel_consumed);
}