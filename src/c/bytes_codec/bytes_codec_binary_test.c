#include "bytes_codec_binary.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct test_case {
    uint8_t bytes[4096];
    int bytes_len;
    uint8_t buffer[4096];
    int bufsz;
};

static void run_test_case(struct test_case *test_case);

static void run_test_case(struct test_case *test_case) {
    int ret;
    int len = 0;
    uint8_t bytes[4096];
    uint8_t *bytes_ref = NULL;

    bytes_enc_binary_cpy(test_case->bytes, test_case->bytes_len, test_case->buffer, test_case->bufsz, &len);
    bytes_dec_binary_cpy(bytes, len, test_case->buffer, test_case->bufsz, &len);
    if (memcmp(test_case->bytes, bytes, len) != 0) {
        printf("[ERROR]: bytes_codec_binary_cpy returned inconsistent result.\n");
        exit(0);
    } else {
        printf("[INFO]: bytes_codec_binary_cpy passed basic test.\n");
    }
    bytes_enc_binary_ref(test_case->bytes, test_case->bytes_len, test_case->buffer, test_case->bufsz, &len);
    bytes_dec_binary_ref(&bytes_ref, len, test_case->buffer, test_case->bufsz, &len);
    if (memcmp(test_case->bytes, bytes, len) != 0) {
        printf("[ERROR]: bytes_codec_binary_ref returned inconsistent result.\n");
        exit(0);
    } else {
        printf("[INFO]: bytes_codec_binary_ref passed basic test.\n");
    }
}

struct test_case test_cases[] = {
    {
        .bytes = {0x11, 0x22, 0x33},
        .bytes_len = 3,
        .bufsz = 4096
    }, 
    {
        .bytes = {0xff, 0xee, 0xc3, 0x78},
        .bytes_len = 4,
        .bufsz = 4096
    }, 
    {
        .bytes = {0x11, 0x22, 0x33},
        .bytes_len = 1024,
        .bufsz = 4096
    }, 
};

int main(int argc, char *argv[]) {
    int n_cases = sizeof(test_cases) / sizeof(struct test_case);
    int i = 0;
    for (i = 0; i < n_cases; i++) {
        run_test_case(&(test_cases[i]));
    }
    return 0;
}