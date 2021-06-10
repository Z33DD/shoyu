#include <sodium.h>

#include <string.h>

unsigned char *generateKeyFromString(char *plainPassword){
        unsigned char key[crypto_secretstream_xchacha20poly1305_KEYBYTES];
        unsigned char salt[crypto_pwhash_SALTBYTES];

        randombytes_buf(salt, sizeof salt);

        if (crypto_pwhash(key, sizeof key, plainPassword, strlen(plainPassword), salt,
                          crypto_pwhash_OPSLIMIT_INTERACTIVE, crypto_pwhash_MEMLIMIT_INTERACTIVE,
                          crypto_pwhash_ALG_DEFAULT) != 0)
        {
            /* out of memory */
        }
        return key;
}
