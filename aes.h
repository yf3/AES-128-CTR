#ifndef AES_H
#define AES_H

#include <stdint.h>

void encrypt_by_AES(const uint8_t* plaintext, const uint8_t* key, uint8_t* ciphertext);
void decrypt_by_AES(uint8_t* plaintext, const uint8_t* key, const uint8_t* ciphertext);

#endif // AES_H
