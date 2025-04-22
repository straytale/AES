#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "aes.h"

// 測試用 key 和資料
const U8 test_key[16] = {
    0x2b, 0x7e, 0x15, 0x16,
    0x28, 0xae, 0xd2, 0xa6,
    0xab, 0xf7, 0x15, 0x88,
    0x09, 0xcf, 0x4f, 0x3c};

const U8 plain_text[16] = {
    0x32, 0x43, 0xf6, 0xa8,
    0x88, 0x5a, 0x30, 0x8d,
    0x31, 0x31, 0x98, 0xa2,
    0xe0, 0x37, 0x07, 0x34};

const U8 expected_cipher[16] = {
    0x39, 0x25, 0x84, 0x1d,
    0x02, 0xdc, 0x09, 0xfb,
    0xdc, 0x11, 0x85, 0x97,
    0x19, 0x6a, 0x0b, 0x32};

void test_encrypt()
{
    U8 buffer[16];
    memcpy(buffer, plain_text, 16);

    AES_ctx ctx;
    AES_init_ctx(&ctx, test_key);
    AES_ECB_encrypt(&ctx, buffer);

    printf("Encryption test: ");
    assert(memcmp(buffer, expected_cipher, 16) == 0);
    printf("PASSED\n");
}

void test_decrypt()
{
    U8 buffer[16];
    memcpy(buffer, expected_cipher, 16);

    AES_ctx ctx;
    AES_init_ctx(&ctx, test_key);
    AES_ECB_decrypt(&ctx, buffer);

    printf("Decryption test: ");
    assert(memcmp(buffer, plain_text, 16) == 0);
    printf("PASSED\n");
}

void test_encrypt_decrypt_roundtrip()
{
    U8 buffer[16];
    memcpy(buffer, plain_text, 16);

    AES_ctx ctx;
    AES_init_ctx(&ctx, test_key);
    AES_ECB_encrypt(&ctx, buffer);
    AES_ECB_decrypt(&ctx, buffer);

    printf("Roundtrip test: ");
    assert(memcmp(buffer, plain_text, 16) == 0);
    printf("PASSED\n");
}

int main()
{
    test_encrypt();
    test_decrypt();
    test_encrypt_decrypt_roundtrip();

    printf("All AES-128 ECB tests passed.\n");
    return 0;
}
