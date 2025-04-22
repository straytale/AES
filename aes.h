#ifndef AES_H
#define AES_H

#include <stdint.h>
#include <string.h>

#define AES_BLOCKLEN 16 // Block length in bytes - AES is 128b block only

typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;

typedef struct
{
    U8 RoundKey[176]; // 11 rounds * 16 bytes each
} AES_ctx;

void AES_init_ctx(AES_ctx *ctx, const U8 *key);
void AES_ECB_encrypt(const AES_ctx *ctx, U8 *buf);
void AES_ECB_decrypt(const AES_ctx *ctx, U8 *buf);

#endif