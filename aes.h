#define DEBUGING (1)

#define ENCRYPT (0)
#define DECRYPT (1)

#define BASE256 (8)
#define BASE128 (16)
#define BASE512 (32)

#define U8 unsigned char
#define U16 unsigned short
#define U32 unsigned int

/**
 * @brief Encrypt/Decrypt the data by the key (ECB)
 * @param data
 * @param key
 * @param operation: ENCRYPT or DECRYPT
 *
 */
char *aes128(char *data, char *key, unsigned short operation);