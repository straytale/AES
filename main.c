#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "aes.h"

void print_hex(const char *label, const U8 *data, size_t len)
{
    printf("%s", label);
    for (size_t i = 0; i < len; i++)
    {
        printf("%02X ", data[i]);
    }
    printf("\n");
}

void test_null_input()
{
    U8 key[BASE128] = {0};
    assert(aes128(NULL, 0, key, BASE128, ENCRYPT) == NULL);
    assert(aes128((U8 *)"test", 4, NULL, BASE128, ENCRYPT) == NULL);
    assert(aes128((U8 *)"test", 4, key, 10, ENCRYPT) == NULL);
    printf("NULL input test: PASSED\n");
}

void test_exact_5_bytes()
{
    U8 key[BASE128] = {0};
    U8 input[5] = "HELLO";
    U8 *enc = aes128(input, 5, key, BASE128, ENCRYPT);
    U8 *dec = aes128(enc, BASE128, key, BASE128, DECRYPT);
    assert(memcmp(dec, input, 5) == 0);
    printf("5-byte input test: PASSED\n");
    free(enc);
    free(dec);
}

void test_exact_16_bytes()
{
    U8 key[BASE128] = {0};
    U8 input[16] = "1234567890ABCDEF";
    U8 *enc = aes128(input, 16, key, BASE128, ENCRYPT);
    U8 *dec = aes128(enc, BASE128, key, BASE128, DECRYPT);
    assert(memcmp(dec, input, 16) == 0);
    printf("16-byte input test: PASSED\n");
    free(enc);
    free(dec);
}

void test_18_bytes()
{
    U8 key[BASE128] = {0};
    U8 input[18] = "1234567890ABCDEFGH"; // 18 bytes
    U8 *enc = aes128(input, 18, key, BASE128, ENCRYPT);
    U8 *dec = aes128(enc, 32, key, BASE128, DECRYPT); // padded to 32 bytes (2 blocks)
    assert(memcmp(dec, input, 18) == 0);
    printf("18-byte input test: PASSED\n");
    free(enc);
    free(dec);
}

void test_32_bytes()
{
    U8 key[BASE128] = {0};
    U8 input[32] = "ABCDEFGHIJKLMNOPQRSTUVWX12345678"; // exactly 32 bytes
    U8 *enc = aes128(input, 32, key, BASE128, ENCRYPT);
    U8 *dec = aes128(enc, 32, key, BASE128, DECRYPT);
    assert(memcmp(dec, input, 32) == 0);
    printf("32-byte input test: PASSED\n");
    free(enc);
    free(dec);
}

void test_34_bytes()
{
    U8 key[BASE128] = {0};
    U8 input[34] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ12345678"; // 34 bytes
    U8 *enc = aes128(input, 34, key, BASE128, ENCRYPT);
    U8 *dec = aes128(enc, 48, key, BASE128, DECRYPT); // padded to 48 bytes (3 blocks)
    assert(memcmp(dec, input, 34) == 0);
    printf("34-byte input test: PASSED\n");
    free(enc);
    free(dec);
}

int main()
{
    test_null_input();
    test_exact_5_bytes();
    test_exact_16_bytes();
    test_18_bytes();
    test_32_bytes();
    test_34_bytes();

    printf("All AES-128 ECB tests passed.\n");
    return 0;
}