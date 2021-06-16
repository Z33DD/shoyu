#include <sodium.h>

#define BUFFER_SIZE 4096

static int
decrypt(const char *target_file, const char *source_file,
        const unsigned char key[crypto_secretstream_xchacha20poly1305_KEYBYTES])
{
    unsigned char bufferIn[BUFFER_SIZE + crypto_secretstream_xchacha20poly1305_ABYTES];
    unsigned char bufferOut[BUFFER_SIZE];

    unsigned char header[crypto_secretstream_xchacha20poly1305_HEADERBYTES];

    crypto_secretstream_xchacha20poly1305_state st;

    FILE *fpTarget, *fpSource;

    unsigned long long outLen;

    size_t rlen;

    int eof;
    int ret = -1;
    unsigned char tag;

    fpSource = fopen(source_file, "rb");
    fpTarget = fopen(target_file, "wb");
    fread(header, 1, sizeof(header), fpSource);
    if (crypto_secretstream_xchacha20poly1305_init_pull(&st, header, key) != 0)
    {
        goto ret; /* incomplete header */
    }
    do
    {
        rlen = fread(bufferIn, 1, sizeof bufferIn, fpSource);
        eof = feof(fpSource);
        if (crypto_secretstream_xchacha20poly1305_pull(&st, bufferOut, &outLen, &tag,
                                                       bufferIn, rlen, NULL, 0) != 0)
        {
            goto ret; /* corrupted chunk */
        }
        if (tag == crypto_secretstream_xchacha20poly1305_TAG_FINAL && !eof)
        {
            goto ret; /* premature end (end of file reached before the end of the stream) */
        }
        fwrite(bufferOut, 1, (size_t)outLen, fpTarget);
    } while (!eof);

    ret = 0;
ret:
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
    return ret;
}
