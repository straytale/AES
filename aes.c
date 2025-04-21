#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aes.h"

void assert(char *msg)
{
    printf("[ASSERT] %s\n", msg);
    exit(0);
}

void print_data(U8 *data, U8 len)
{
    for (U8 i = 0; i < len; i++)
    {
        printf("0x%x ", data[i]);
    }
    printf("\n");
}

void encrypt(U8 *data[], U8 *key)
{
#if DEBUGING
    printf("Key: ");
    print_data(key, strlen(key));
#endif
}

void decrypt(U8 *data[], U8 *key)
{
#if DEBUGING
    printf("Key: ");
    print_data(key, strlen(key));
#endif
}

void PKCS7(U8 *data[], U8 len)
{
    U8 exp = BASE128 - len;
    for (U8 i = len; i < BASE128; i++)
    {
        (*data)[i] = exp;
    }
}

char *aes128(char *data, char *key, unsigned short operation)
{
    U8 *buffer = (U8 *)malloc(sizeof(U8) * BASE128);
    memset(buffer, 0, BASE128);

    U8 data_len = strlen(data);
    U8 key_len = strlen(key);
    memcpy(buffer, data, data_len);

    // checking
    if (data_len == 0)
    {
        return NULL;
    }
    else if (data_len > BASE128)
    {
        assert("The Data size is exceeds 128 bits");
    }
    else if (key_len != BASE128)
    {
        assert("The Key size must be 128 bits");
    }

#if DEBUGING
    printf("Input data: ");
    print_data(buffer, BASE128);
#endif

    if (data_len < BASE128)
    {
        PKCS7(&buffer, data_len);
    }

#if DEBUGING
    printf("After expand: ");
    print_data(buffer, BASE128);
#endif

    switch (operation)
    {
    case ENCRYPT:
        encrypt(&buffer, (U8 *)key);
        break;
    case DECRYPT:
        decrypt(&buffer, (U8 *)key);
        break;
    default:
        break;
    }

    return buffer;
}