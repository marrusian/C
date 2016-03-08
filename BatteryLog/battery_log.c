#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>

#define ENERGY_FULL_DESIGN_LINENUM   9
#define ENERGY_FULL_CURRENT_LINENUM  10
#define BUFFER_SIZE                  128

int main(void)
{
    FILE *uevent, *battery_log;
    long energy_full_design  = 0;
    long energy_full_current = 0;
    char buffer[BUFFER_SIZE] = {0};
    time_t date;

    errno = 0;
    uevent = fopen("/sys/class/power_supply/BAT0/uevent", "r");
    if(uevent == NULL){
        perror("Cannot open file \'uevent\'");
        exit(EXIT_FAILURE);
    }

    for(int i = 1; i <= ENERGY_FULL_DESIGN_LINENUM; ++i){
        errno = 0;
        if(fgets(buffer, sizeof(buffer), uevent) == NULL){
            perror("Error while reading from \'uevent\'");
            exit(EXIT_FAILURE);
        }
    }

    char *endptr;

    errno = 0;
    energy_full_design = strtol(strchr(buffer, '=')+1, &endptr, 10);
    if((errno == ERANGE && (energy_full_design == LONG_MAX || energy_full_design == LONG_MIN)) ||
       (errno != 0 && energy_full_design == 0)){
        perror("strtol()");
        exit(EXIT_FAILURE);
    }

    if(*endptr != '\n'){
        fprintf(stderr, "No digits were found; Offending character is \'%c\'\n", *endptr);
        exit(EXIT_FAILURE);
    }

    errno = 0;
    if(fgets(buffer, sizeof(buffer), uevent) == NULL){
        perror("Error while reading from \'uevent\'");
        exit(EXIT_FAILURE);
    }

    errno = 0;
    energy_full_current = strtol(strchr(buffer, '=')+1, &endptr, 10);
    if((errno == ERANGE && (energy_full_current == LONG_MAX || energy_full_current == LONG_MIN)) ||
       (errno != 0 && energy_full_current == 0)){
        perror("strtol()");
        exit(EXIT_FAILURE);
    }

    if(*endptr != '\n'){
        fprintf(stderr, "No digits were found; Offending character is \'%c\'\n", *endptr);
        exit(EXIT_FAILURE);
    }

    errno = 0;
    if(fclose(uevent)){
        perror("Cannot close file \'uevent\'");
        exit(EXIT_FAILURE);
    }

    errno = 0;
    battery_log = fopen("/home/marru/battery_log", "a");
    if(battery_log == NULL){
        perror("Cannot open file \'battery_log\'");
        exit(EXIT_FAILURE);
    }

    char current_date[BUFFER_SIZE] = {0};
    time(&date);
    strncpy(current_date, ctime(&date), sizeof(current_date));
    *strchr(current_date, '\n') = '\0';

    fprintf(battery_log, "%s: Battery capacity left - %lf%%\n",
            current_date, (double) energy_full_current/energy_full_design*100);

    if(ferror(battery_log)){
        perror("Cannot write to file \'battery_log\'");
        exit(EXIT_FAILURE);
    }

    errno = 0;
    if(fclose(battery_log)){
        perror("Cannot close file \'battery_log\'");
        exit(EXIT_FAILURE);
    }

    return 0;
}