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
        printf("0x%.2X ", data[i]);
    }
    printf("\n");
}

void encrypt(U8 *data[], U8 *key)
{
#if DEBUGING
    printf("[      key     ] ");
    print_data(key, BASE128);
#endif
}

void decrypt(U8 *data[], U8 *key)
{
#if DEBUGING
    printf("[      key     ] ");
    print_data(key, BASE128);
#endif
}

void PKCS7(U8 *data[])
{
    U8 len = strlen(*data);
    U8 exp = BASE128 - len;
    for (U8 i = len; i < BASE128; i++)
    {
        (*data)[i] = exp;
    }
}

void dePKCS7(U8 *data[])
{
    U8 exp = (*data)[BASE128 - 1];
    for (int i = 0; i < exp; i++)
    {
        if ((*data)[BASE128 - i - 1] == exp)
        {
            continue;
        }
        return;
    }
    for (int i = 0; i < exp; i++)
    {
        (*data)[BASE128 - i - 1] = 0;
    }
}

U8 *aes128(U8 *data, U8 data_len, U8 *key, U8 key_len, U8 operation)
{
    if (data == NULL || key == NULL || data_len > BASE128 || key_len != BASE128)
    {
        assert("Parameter is invalid");
    }

    U8 *_data = (U8 *)malloc(BASE128);
    U8 *_key = (U8 *)malloc(BASE128);

    memset(_data, 0, BASE128);
    memset(_key, 0, BASE128);
    memcpy(_data, data, data_len);
    memcpy(_key, key, key_len);

    switch (operation)
    {
    case ENCRYPT:
#if DEBUGING
        printf("[Before encrypt] ");
        print_data(_data, BASE128);
#endif
        PKCS7(&_data);
        encrypt(&_data, (U8 *)key);
#if DEBUGING
        printf("[After encrypt ] ");
        print_data(_data, BASE128);
#endif
        break;
    case DECRYPT:
#if DEBUGING
        printf("[Before decrypt] ");
        print_data(_data, BASE128);
#endif
        decrypt(&_data, (U8 *)key);
        dePKCS7(&_data);
#if DEBUGING
        printf("[After decrypt ] ");
        print_data(_data, BASE128);
#endif
        break;
    default:
        break;
    }
    free(_key);
    return _data;
}
