/*
@author - Jatin Rohilla
*/
/*
@ref - http://en.cppreference.com/w/cpp/types/integer
Fixed width type integers

@requirement - c++11 support enabled
*/

#include <cstdio>   // for printf
#include <cinttypes>    // for fixed width type integers

int main()
{
    printf("\n>>>> Integer of exactly 8 bits \n");
    printf("      Size in bytes : %zu\n", sizeof(int8_t));
    printf("  printf identifier : %s\n", PRId8);
    printf("           Range is : %+" PRId8 "  to  %+" PRId8 "\n", INT8_MIN,INT8_MAX);
    printf("\n");

    printf("\n>>>> Integer of exactly 16 bits \n");
    printf("      Size in bytes : %zu\n", sizeof(int16_t));
    printf("  printf identifier : %s\n", PRId16);
    printf("           Range is : %+" PRId16 "  to  %+" PRId16 "\n", INT16_MIN,INT16_MAX);
    printf("\n");

    printf("\n>>>> Integer of exactly 32 bits \n");
    printf("      Size in bytes : %zu\n", sizeof(int32_t));
    printf("  printf identifier : %s\n", PRId32);
    printf("           Range is : %+" PRId32 "  to  %+" PRId32 "\n", INT32_MIN,INT32_MAX);
    printf("\n");

    printf("\n>>>> Integer of exactly 64 bits \n");
    printf("      Size in bytes : %zu\n", sizeof(int64_t));
    printf("  printf identifier : %s\n", PRId64);
    printf("           Range is : %+" PRId64 "  to  %+" PRId64 "\n", INT64_MIN,INT64_MAX);
    printf("\n");

    // usage :
    /**
    int64_t n = 7;
    printf("%+" PRId64 "\n", n);
    */
}
