#define PRINT(X,L,S) _Generic((X),\
unsigned char*: print_ucarr,\
char*: print_carr,\
unsigned short*: print_usarr,\
short*: print_sarr,\
unsigned int*: print_uiarr,\
int* : print_iarr,\
unsigned long*: print_ularr,\
long*: print_larr,\
unsigned long long*: print_ullarr,\
long long*: print_llarr,\
float*: print_farr,\
double*: print_darr,\
long double*: print_ldarr)(X,L,S)

void print_str(const char *ar, FILE *stream);
void print_ucarr(const unsigned char ar[], size_t length, FILE *stream);
void print_carr(const char ar[], size_t length, FILE *stream);
void print_usarr(const unsigned short ar[], size_t length, FILE *stream);
void print_sarr(const short ar[], size_t length, FILE *stream);
void print_ularr(const unsigned long ar[], size_t length, FILE *stream);
void print_larr(const long ar[], size_t length, FILE *stream);
void print_ullarr(const unsigned long long ar[], size_t length, FILE *stream);
void print_llarr(const long long ar[], size_t length, FILE *stream);
void print_iarr(const int ar[], size_t length, FILE *stream);
void print_uiarr(const unsigned int ar[], size_t length, FILE *stream);
void print_farr(const float ar[], size_t length, FILE *stream);
void print_darr(const double ar[], size_t length, FILE *stream);
void print_ldarr(const long double ar[], size_t length, FILE *stream);

