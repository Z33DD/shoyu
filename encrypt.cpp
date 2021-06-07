#include <stdio.h>
#include <sodium.h>
#include <cstring>

#include "encrypt.h"
#include "decrypt.h"

#define BUFFER_SIZE 4096



int main(void)
{
    // https://doc.libsodium.org/secret-key_cryptography/secretstream#example-stream-encryption
    char *password;

    unsigned char key[crypto_secretstream_xchacha20poly1305_KEYBYTES];
    unsigned char salt[crypto_pwhash_SALTBYTES];

    randombytes_buf(salt, sizeof salt);

    if (crypto_pwhash(key, sizeof key, password, strlen(password), salt,
                      crypto_pwhash_OPSLIMIT_INTERACTIVE, crypto_pwhash_MEMLIMIT_INTERACTIVE,
                      crypto_pwhash_ALG_DEFAULT) != 0)
    {
        /* out of memory */
    }

    if (sodium_init() != 0)
    {
        return 1;
    }

    crypto_secretstream_xchacha20poly1305_keygen(key);
    if (encrypt("encrypted.bin", "file.txt", key) != 0)
    {
        return 1;
    }
    if (decrypt("decrypted.txt", "encrypted.bin", key) != 0)
    {
        return 1;
    }
    return 0;

}