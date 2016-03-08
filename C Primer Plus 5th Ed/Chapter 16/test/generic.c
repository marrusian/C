#include<stdio.h>

void print_str(const char *ar, FILE *stream){
   while(*ar)
      putc(*ar++, stream);
   putc('\n', stream);
}

void print_ucarr(const unsigned char ar[], size_t length, FILE *stream){
   for(size_t i=0; i<length; ++i)
      fprintf(stream, "%hhu ", ar[i]);
   putc('\n', stream);
}

void print_carr(const char ar[], size_t length, FILE *stream){
   for(size_t i=0; i<length; ++i)
      fprintf(stream, "%hhd ", ar[i]);
   putc('\n', stream);
}

void print_usarr(const unsigned short ar[], size_t length, FILE *stream){
   for(size_t i=0; i<length; ++i)
      fprintf(stream, "%hu ", ar[i]);
   putc('\n', stream);
}

void print_sarr(const short ar[], size_t length, FILE *stream){
   for(size_t i=0; i<length; ++i)
      fprintf(stream, "%hd ", ar[i]);
   putc('\n', stream);
}

void print_ularr(const unsigned long ar[], size_t length, FILE *stream){
   for(size_t i=0; i<length; ++i)
      fprintf(stream, "%lu ", ar[i]);
   putc('\n', stream);
}

void print_larr(const long ar[], size_t length, FILE *stream){
   for(size_t i=0; i<length; ++i)
      fprintf(stream, "%ld ", ar[i]);
   putc('\n', stream);
}

void print_ullarr(const unsigned long long ar[], size_t length, FILE *stream){
   for(size_t i=0; i<length; ++i)
      fprintf(stream, "%llu ", ar[i]);
   putc('\n', stream);
}

void print_llarr(const long long ar[], size_t length, FILE *stream){
   for(size_t i=0; i<length; ++i)
      fprintf(stream, "%lld ", ar[i]);
   putc('\n', stream);
}

void print_iarr(const int ar[], size_t length, FILE *stream){
   for(size_t i=0; i<length; ++i)
      fprintf(stream, "%d ", ar[i]);
   putc('\n', stream);
}

void print_uiarr(const unsigned int ar[], size_t length, FILE *stream){
   for(size_t i=0; i<length; ++i)
      fprintf(stream, "%u ", ar[i]);
   putc('\n', stream);
}

void print_farr(const float ar[], size_t length, FILE *stream){
   for(size_t i=0; i<length; ++i)
      fprintf(stream, "%f ", ar[i]);
   putc('\n', stream);
}

void print_darr(const double ar[], size_t length, FILE *stream){
   for(size_t i=0; i<length; ++i)
      fprintf(stream, "%f ", ar[i]);
   putc('\n', stream);
}

void print_ldarr(const long double ar[], size_t length, FILE *stream){
   for(size_t i=0; i<length; ++i)
      fprintf(stream, "%Lf ", ar[i]);
   putc('\n', stream);
}

