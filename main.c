#include "aes.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *input = "NULL";
    int input_len = strlen(input);
    char *output;
    int output_len;
    char *temp;
    char *key = "1234567890156";

    temp = (char *)aes128(input, 16, key, 16, ENCRYPT);
    output = aes128(temp, 16, key, 16, DECRYPT);
    output_len = strlen(output);
    if (strncmp(input, output, BASE128) == 0 && input_len == output_len)
    {
        printf("Compare PASS\n");
    }
    else
    {
        printf("Compare FAIL\n");
    }
}