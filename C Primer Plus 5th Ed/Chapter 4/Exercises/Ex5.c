/*
*  5. Write a program that requests the download speed in megabits per second (Mbps) and
* the size of a file in megabytes (MB). The program should calculate the download time
* for the file. Note that in this context one byte is eight bits. Use type float, and use /
* for division. The program should report all three values (download speed, file size, and
* download time) showing two digits to the right of the decimal point, as in the following:
*    "At 18.12 megabits per second, a file of 2.20 megabytes
*     downloads in 0.97 seconds."
*/

#include<stdio.h>
#define BITS_PER_BYTE 8

int main(void)
{
  float dl_speed = 0.0f; // measured in Mbps
  float file_size = 0.0f; // measured in MBs
  float dl_time = 0.0f;  // measured in seconds
  
  printf("Enter your download speed(in Mbps): ");
  scanf("%f", &dl_speed);
  printf("Enter the size of a file(in MBs): ");
  scanf("%f", &file_size);
  dl_time = file_size/(dl_speed/BITS_PER_BYTE); 

  printf("At %.2f megabits per second, a file of %.2f megabytes\n"
         "downloads in %.2f seconds.\n", dl_speed, file_size, dl_time);
  
  return 0;
}