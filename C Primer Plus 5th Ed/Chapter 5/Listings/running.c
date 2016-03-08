#include<stdio.h>

int main(void)
{
  const int S_PER_M = 60;
  const int S_PER_H = 3600;
  const double M_PER_K = 0.62137;

  double distk = 0.0, distm = 0.0;
  double rate = 0.0;             // average speed in mph
  int min = 0, sec = 0;          // mins and seconds of running time
  int time = 0;                  // running time in seconds only
  double mtime = 0.0;            // time in seconds for one mile
  int mmin = 0, msec =0;         // mins and seconds for one mile

  printf("This program converts your time for a metric race\n");
  printf("to a time for running a mile and to your average\n");
  printf("speed in miles per hour.\n");
  printf("Please enter, in kilometers, the distance run.\n");
  scanf("%lf", &distk);
  printf("Next enter the time in minutes and seconds.\n");
  scanf("%d", &min);
  printf("Now enter the seconds.\n");
  scanf("%d", &sec);

  time  = S_PER_M * min + sec;
  distm = M_PER_K * distk;
  rate  = distm/time * S_PER_H;
  mtime = (double)time / distm;
  mmin  = (int)mtime / S_PER_M;
  msec  = (int)mtime % S_PER_M;

  printf("You ran %1.2f km (%1.2f miles) in %d min, %d sec.\n",
         distk, distm, min, sec);
  printf("That pace corresponds to running a mile in %d min, ",
         mmin);
  printf("%d sec.\nYour average speed was %1.2f mph.\n", msec,
         rate);

  return 0;
}