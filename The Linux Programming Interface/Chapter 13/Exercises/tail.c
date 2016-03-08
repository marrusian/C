#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#define OPT_SIZE 2

enum op{LINES = 0, HELP = 1};

#define O_NOVAL -1  // The option takes no further argument(s)
typedef struct cmdline_args{
   bool status;     // 0 - option ommitted, 1 - option specified;
   int  pos;        // n-th argv element;
   long value;      // Store the corresponding option argument;
} optBlock;

bool check_options(const char *argv[], optBlock opts[], int *no_opts);
bool parse_options(const char *argv[], optBlock opts[], size_t length);
void show_help_menu(void);
int print_lines(long num_lines, int fd);

int main(int argc, char *argv[])
{
   optBlock opts[OPT_SIZE] = {{0}};
   int no_opts;
   int fd;
   bool multiple_files = false;

   if(!check_options((const char**)argv, opts, &no_opts))
      exit(EXIT_FAILURE);

   if(opts[HELP].status){
      show_help_menu();
      exit(EXIT_SUCCESS);
   }

   if(argc-no_opts > 2)
      multiple_files = true;

   if(!parse_options((const char**)argv, opts, OPT_SIZE))
      exit(EXIT_FAILURE);

   for(int i=1; argv[i]; ++i){
      if(argv[i][0] == '-')
         continue;

      if((fd = open(argv[i], O_RDONLY)) == -1){
         fprintf(stderr, "Cannot open \'%s\' for reading\n", argv[i]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }

      if(multiple_files)
         printf("\n==> %s <==\n", argv[i]);

      if(print_lines(opts[LINES].status? opts[LINES].value : 10, fd) == -1)
         exit(EXIT_FAILURE);

      if(close(fd) == -1){
         fprintf(stderr, "Cannot close \'%s\'\n", argv[i]);
         perror("Reason");
         exit(EXIT_FAILURE);
      }
   }

   exit(EXIT_SUCCESS);
}

int print_lines(long num_lines, int fd)
{
   off_t off, temp;
   char *buffer;
   long lines = 0;

   if((off = lseek(fd, 0, SEEK_END)) == (off_t)-1){
      perror("ERROR");
      return -1;
   }
   lseek(fd, 0, SEEK_SET);

   if(!(buffer = (char*) malloc(off*sizeof(char)))){
      perror("ERROR");
      return -1;
   }

   if(read(fd, buffer, off) == -1){
      fprintf(stderr, "Failed to read from file.\n");
      perror("Reason");
      return -1;
   }

   temp = off;
   while(off && lines<num_lines)
      if(buffer[--off-1] == '\n') ++lines;

   if(write(STDOUT_FILENO, buffer+off, temp-off) == -1){
      fprintf(stderr, "Failed to write the data\n");
      perror("Reason");
      return -1;
   }

   free(buffer);

   return 0;
}

bool check_options(const char *argv[], optBlock opts[], int *no_opts)
{
   *no_opts = 0;

   for(int i=0; argv[i]; ++i){
      if(argv[i][0] == '-'){
         ++(*no_opts);

         if(!argv[i][1]){
            fprintf(stderr, "Option set is empty.\n");
            return false;
         }

         if(!strcmp(argv[i], "-n") || !strncmp(argv[i], "--lines", 7)){
            if(strncmp(argv[i], "--lines=", 8) && !argv[i+1]){
               fprintf(stderr, "Option \'%s\' requires an argument\n", argv[i]);
               return false;
            }

            opts[LINES].status = true;
            opts[LINES].pos = i;
         }
         else if(!strcmp(argv[i], "--help")){
            opts[HELP].status = true;
            break;
         }
         else{
            if(argv[i][1] != '-')
               fprintf(stderr, "Invalid option \'%c\'\n", argv[i][1]);
            else
               fprintf(stderr, "Unrecognized option \'%s\'\n", argv[i]);

            return false;
         }
      }
   }

   return true;
}

bool get_num(const char *str, long *value)
{
   char *endptr;
   long val = 0;

   if(!str || !(*str))
      return false;

   errno = 0;
   val = strtol(str, &endptr, 10);
   if(errno || *endptr)
      return false;

   *value = val;
   return true;
}

bool parse_options(const char *argv[], optBlock opts[], size_t length)
{
   const char *parsing_str;

   for(size_t i=0; i<length; ++i){
      if(opts[i].status && opts[i].value!=O_NOVAL){
         switch(!strncmp(argv[opts[i].pos], "--", 2)){
            case false: if(!get_num(argv[opts[i].pos+1], &opts[i].value)){
                           fprintf(stderr, "%s: invalid number\n", argv[opts[i].pos+1]);
                           return false;
                        }
                        break;

            case true : parsing_str = strchr(argv[opts[i].pos], '=');
                        if(!parsing_str)
                           parsing_str = argv[opts[i].pos+1];
                        else
                           ++parsing_str;

                        if(!get_num(parsing_str, &opts[i].value)){
                           fprintf(stderr, "%s: invalid number\n", parsing_str);
                           return false;
                        }
                        break;
         }
      }
   }

   return true;
}

void show_help_menu(void)
{
   printf("Usage: tail [-n num]... [FILE]...\n"
          "Print the last 10 lines of each FILE to standard output.\n"
          "With more than one FILE, precede each with a header giving the file name.\n"
          "With no FILE, read standard input.\n\n");

   printf("-n, --lines=K\t\t output the last K lines, instead of the last 10;\n"
          "     --help  \t\t display this help and exit\n");
}