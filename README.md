# 🔐 AES-128 ECB Encryption

A simple AES-128 encryption/decryption implementation in **ECB mode**, written in C. This project demonstrates block cipher encryption with PKCS#7 padding and is suitable for educational use or integration in embedded systems that need basic symmetric encryption.

---

## 📁 Project Structure

```
AES/
├── aes.c           # Core AES-128 ECB encryption/decryption logic
├── aes.h           # AES context structure and function declarations
├── main.c          # Test cases for various input sizes
├── test_vectors.c  # Optional: known input-output test vectors
```

---

## ⚙️ How It Works

1. **Key Handling**: AES uses a fixed 128-bit (16-byte) key.
2. **Padding**: Implements PKCS#7 padding to make input data a multiple of 16 bytes.
3. **ECB Mode**: Each 16-byte block is encrypted independently.
4. **Block Processing**:
   - Encryption: Applies padding, then encrypts each block using the AES context.
   - Decryption: Decrypts each block, then removes padding.
5. **Validation**: Includes test cases for NULL input, exact block size, and over-block inputs (e.g., 18, 32, 34 bytes).

---

## 🔧 AES API Overview

```c
U8 *aes128(const U8 *data, U8 data_len, const U8 *key, U8 key_len, U8 operation);
void AES_init_ctx(AES_ctx *ctx, const U8 *key);
void AES_ECB_encrypt(const AES_ctx *ctx, U8 *buf);
void AES_ECB_decrypt(const AES_ctx *ctx, U8 *buf);
```

- `aes128(...)`: Main entry point for encrypting/decrypting data using AES-128.
- `AES_init_ctx(...)`: Initializes encryption context with the provided key.
- `AES_ECB_encrypt(...)` / `AES_ECB_decrypt(...)`: Encrypts or decrypts one 16-byte block.

---

## ✅ Test Coverage

Includes unit tests for:

- NULL inputs
- Exact block (16 bytes)
- Short (5 bytes), medium (18 bytes), and large (32/34 bytes) inputs
- Memory safety and padding validation

---

## 🛠️ Build Instructions

```bash
gcc -o aes_test main.c aes.c -I.
```

> Add `-Wall -Wextra` to enable more compiler warnings.

---

## 📌 Notes

- **ECB mode is not secure** for encrypting large or patterned data — for real applications, prefer CBC, CTR, or GCM.
- This implementation is for **educational/demo** purposes.
- Easily embeddable in microcontroller projects (no dynamic memory required if adapted).

---

## 📚 Suggested Extensions

- Add AES-192 and AES-256 support
- Implement CBC/CTR modes
- Add hex/base64 input/output utilities
- Use hardware acceleration (e.g., AES-NI on x86 or crypto engines on ARM)
