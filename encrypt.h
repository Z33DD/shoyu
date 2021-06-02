#include <sodium.h>
#include <stdio.h>

#define BUFFER_SIZE 4096

static int
encrypt(const char *target_file, const char *source_file,
        const unsigned char key[crypto_secretstream_xchacha20poly1305_KEYBYTES])
{
    unsigned char bufferIn[BUFFER_SIZE];
    unsigned char bufferOut[BUFFER_SIZE + crypto_secretstream_xchacha20poly1305_ABYTES];
    unsigned char header[crypto_secretstream_xchacha20poly1305_HEADERBYTES];
    crypto_secretstream_xchacha20poly1305_state st;
    FILE *fpTarget, *fpSource;
    unsigned long long out_len;
    size_t rlen;
    int eof;
    unsigned char tag;

    fpSource = fopen(source_file, "rb");
    fpTarget = fopen(target_file, "wb");

    crypto_secretstream_xchacha20poly1305_init_push(&st, header, key);
    fwrite(header, 1, sizeof header, fpTarget);

    do
    {
        rlen = fread(bufferIn, 1, sizeof bufferIn, fpSource);
        eof = feof(fpSource);
        tag = eof ? crypto_secretstream_xchacha20poly1305_TAG_FINAL : 0;
        crypto_secretstream_xchacha20poly1305_push(&st, bufferOut, &out_len, bufferIn, rlen,
                                                   NULL, 0, tag);
        fwrite(bufferOut, 1, (size_t)out_len, fpTarget);
    } while (!eof);

    fclose(fpTarget);
    fclose(fpSource);

    if (remove(source_file) != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}