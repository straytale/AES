#include "aes.h"
#include <stdio.h>

int main(void)
{
    char *input = "Its a test";
    char *key = "1234567890123456";
    char *output = aes128(input, key, ENCRYPT);
    printf("%s\n", output);
}