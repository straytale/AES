#define DEBUGING (1)

#define ENCRYPT (0)
#define DECRYPT (1)

#define BASE128 (16)

#define U8 unsigned char
#define U16 unsigned short
#define U32 unsigned int

/**
 * @brief Encrypt/Decrypt the data by the key (ECB)¡Aplease remember to free the return
 * @param data
 * @param data_len
 * @param key
 * @param key_len
 * @param operation: ENCRYPT or DECRYPT
 * @return allocated buffer with entrypted/decrypted data
 */
U8 *aes128(U8 *data, U8 data_len, U8 *key, U8 key_len, U8 operation);