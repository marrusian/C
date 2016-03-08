#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#define OPT_SIZE 1

enum op{LINES = 0, HELP = 1};

#define O_NOVAL -1  // The option takes no further argument(s)
typedef struct cmdline_args{
   bool status;     // 0 - option ommitted, 1 - option specified;
   long value;      // Store the corresponding option argument;
} optBlock;

int check_options(int argc, char *argv[], optBlock opts[]);
void show_help_menu(void);
int print_lines(long num_lines, int fd);

int main(int argc, char *argv[])
{
   optBlock opts[OPT_SIZE+1] = {{0}};   // Options + help;
   int no_opts;
   int fd;
   bool multiple_files = false;

   if(!check_options(argc, argv, opts))
      exit(EXIT_FAILURE);

   if(opts[HELP].status){
      show_help_menu();
      exit(EXIT_SUCCESS);
   }

   if(argc-no_opts > 2)
      multiple_files = true;

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

void init_long_opts(char *lng_opts[], size_t lng_opts_len[])
{
   lng_opts[LINES] = "lines";
   lng_opts_len[LINES] = sizeof("lines")-1;
}

int check_options(int argc, char *argv[], optBlock opts[])
{
   extern int optind, optopt;
   extern char *optarg;
   extern int getopt(int argc, char * const argv[], const char *optstring);

   int opt;
   int i=0;
   char *long_opts[OPT_SIZE] = {0};
   size_t long_opts_lengths[OPT_SIZE] = {0};
   init_long_opts(long_opts, long_opts_lengths);

   char *parse_str;

   while((opt = getopt(argc, argv, "+:n:-:")) != -1){
      switch(opt){
         case 'n': opts[LINES].status = true;
                   if(!get_num(optarg, &opts[LINES].value)){
                     fprintf(stderr, "%s: invalid number of lines\n", optarg);
                     return false;
                   }
                   break;
         case '-': /* Parse long options */
                   if(!strcmp(optarg, "help")){
                      opts[HELP].status = true;
                      return true;
                   }

                   for(i=0; i<OPT_SIZE; ++i){
                     if(!strncmp(optarg, long_opts[i], long_opts_lengths[i])){
                        opts[i].status = true;
                        parse_str = strchr(optarg, '=');
                        if(!parse_str){
                           parse_str = argv[optind];
                           ++optind;
                        }
                        else
                           ++parse_str;

                        if(!parse_str){
                           fprintf(stderr, "Option \'%s\' requires an argument\n", argv[optind-2]);
                           return false;                           
                        }

                        if(!get_num(parse_str, &opts[i].value)){
                           fprintf(stderr, "%s: invalid number of %s\n", parse_str, long_opts[i]);
                           return false;
                        }

                        break;
                     }
                   }

                   if(i==OPT_SIZE){
                     fprintf(stderr, "Unrecognized option \'%s\'\n", argv[optind-1]);
                     return false;
                   }

                   break;
         case '?': fprintf(stderr, "Invalid option \'%c\'\n", optopt);
                   return false;
         case ':': fprintf(stderr, "Option \'%s\' requires an argument\n", argv[optind-1]);
                   return false;

         default: fprintf(stderr, "DUNNO, LAWL"); exit(EXIT_FAILURE);
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