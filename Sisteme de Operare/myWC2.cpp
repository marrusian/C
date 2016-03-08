/*
*  F16. (5 puncte) Scrieti un program ce simuleaza comanda "wc", cu tot cu
*  cazul cand specificatorul fisierului este dat ca argument in linia de
*  comanda si avem optiuni. Programul va putea fi lansat astfel astfel:
*     wc f            ==>  citeste din f si scrie la stdout
*     wc -optiuni f   ==>  citeste din f si scrie la stdout
*     wc              ==> citeste de la stdin si scrie la stdout
*     wc -optiuni     ==> citeste de la stdin si scrie la stdout
*  Optiunile pot fi orice sir nevid format din literele l,w,c.
*/

#include <cstdio>	// FILE,printf,fprintf,scanf,fscanf,getc,feof;
#include <cstring>	// memset;
#include <cctype>	// isspace;
#include <cinttypes>     // uint_fast32_t, "PRIuFAST32"
#include <cstdlib>

bool check_options(const char* arg);
void unique_copy_options(char * dest, const char *source);
void wc(FILE* istr, uint_fast32_t* data);
void print_wc(const uint_fast32_t* data, const char* options,
              const char* file_name = NULL);

const int LINES = 0;
const int WORDS = 1;
const int BYTES = 2;

int main(int argc, char **argv)
{
    const int SIZE = 3;

    uint_fast32_t files_read = 0;
    uint_fast32_t data[SIZE] = {};
    uint_fast32_t totals[SIZE] = {};

    char opts[10] = {};
    if(argc>1)
        if(argv[1][0]=='-'){     // We take in consideration only the options from the first arg.
            if(!check_options(argv[1]))
                return 1;
            else
                unique_copy_options(opts,argv[1]);
        }

    for(int i = 1; i<argc; ++i){
        if(argv[i][0]=='-') continue;
        ++files_read;

        FILE* inFile;
        if(!(inFile = fopen(argv[i],"r"))){
            fprintf(stderr, "Cannot open %s\n",argv[i]);
            perror("Reason");
            exit(EXIT_FAILURE);
        }

        wc(inFile, data);
        print_wc(data, opts, argv[i]);
        fclose(inFile);

        for(int i = 0; i < SIZE; ++i)
            totals[i]+=data[i];

        memset(data,0,sizeof(data));
    }

    if(!files_read){
        wc(stdin, data);
        print_wc(data, opts);
    }
    else if(files_read>1){
        print_wc(totals, opts, "total");
    }

    return 0;
}

bool check_options(const char* arg)
{
    if(!arg[1]){    // i.e. "- ";
        printf("The option set is empty.\n");
        return false;
    }

    for(int i = 1; arg[i]!='\0'; ++i)
         switch(arg[i]){
             case 'l':
             case 'w':
             case 'c': break;
             default: fprintf(stderr, "Invalid option -- \'%c\'\n",arg[i]);
                      return false;
         }
    return true;
}

void unique_copy_options(char *dest, const char *source)
// Pre-conditions: length(dest)>=length(source)
{
   char *temp = dest;

   while(*source){
      while(*dest && *dest!=*source)
         ++dest;
      if(!*dest)
         *dest=*source;
      dest = temp;
      ++source;         
   }
}

void print_wc(const uint_fast32_t* data, const char* options,
              const char* file_name)
{
    if(options[0])  // i.e. there is at least one option specified.
        for(int i = 1; options[i]; ++i){
            switch(options[i]){
                case 'l': printf("%" PRIuFAST32 "\t",data[LINES]); break;
                case 'w': printf("%" PRIuFAST32 "\t",data[WORDS]); break;
                case 'c': printf("%" PRIuFAST32 "\t",data[BYTES]); break;
            }
        }
    else
        printf("%" PRIuFAST32 "\t%" PRIuFAST32 "\t%" PRIuFAST32 "\t",
               data[LINES], data[WORDS], data[BYTES]);

    if(file_name)
        printf("%s",file_name);

    printf("\n");
}

void wc(FILE* istr, uint_fast32_t* data)
{
    bool word = false;
    int_fast32_t w = 0;

    while((w=getc(istr))!=EOF){
	   ++data[BYTES];
	   if(isspace(w)){
	      if(w=='\n') ++data[LINES];
	      word = false;
	   }
	   else if(!word){
	      word = true;
	      ++data[WORDS];
	   }
    }
}
