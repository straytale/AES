#include "aes.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *input = "XXXSSSXXX";
    char *temp;
    char *output;
    char *key = "1234567890123456";

    temp = (char *)aes128(input, strlen(input), key, 16, ENCRYPT);
    output = aes128(temp, 16, key, 16, DECRYPT);
    if (strncmp(input, output, BASE128) == 0)
    {
        printf("Compare PASS\n");
    }
    else
    {
        printf("Compare FAIL\n");
    }
}