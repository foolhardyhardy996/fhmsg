#include "bytes_codec_binary.h"
#include "bytes_struct.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct test_case {
    struct bytes_struct *bytes;
    uint8_t buffer[4096];
    int bufsz;
    int len;
};

static void run_test_case(struct test_case *test_case);

static void run_test_case(struct test_case *test_case) {
    int ret;
    int len = 0;
    uint8_t buf[4096];
    struct bytes_struct bytes;

    bytes_struct_init(&bytes, buf, 4096, test_case->bytes->len);
    bytes_enc_binary_cpy(test_case->bytes, test_case->buffer, test_case->bufsz, &len);
    bytes_dec_binary_cpy(&bytes, test_case->buffer, test_case->bufsz, &len);
    if (memcmp(test_case->bytes->buf, bytes.buf, len) != 0) {
        printf("[ERROR]: bytes_codec_binary_cpy returned inconsistent result.\n");
        exit(0);
    } else {
        printf("[INFO]: bytes_codec_binary_cpy passed basic test.\n");
    }
    bytes_enc_binary_ref(test_case->bytes, test_case->buffer, test_case->bufsz, &len);
    bytes_dec_binary_ref(&bytes, test_case->buffer, test_case->bufsz, &len);
    if (bytes.buf != test_case->buffer || memcmp(bytes.buf, test_case->bytes->buf, len) != 0) {
        printf("[ERROR]: bytes_codec_binary_ref returned inconsistent result.\n");
        exit(0);
    } else {
        printf("[INFO]: bytes_codec_binary_ref passed basic test.\n");
    }
}

uint8_t bytes1[] = {0x11};
uint8_t bytes2[] = {0x55, 0x35};
uint8_t bytes3[] = {0xff, 0x67, 0x98};

struct bytes_struct bytes_examples[] = {
    {
        .buf = bytes1,
        .bufsz = 1,
        .len = 1
    }, 
    {
        .buf = bytes2,
        .bufsz = 2,
        .len = 2
    }, 
    {
        .buf = bytes3,
        .bufsz = 3,
        .len = 3
    }
};

struct test_case test_cases[] = {
    {
        .bytes = &bytes_examples[0],
        .bufsz = 4096,
        .len = 0
    }, 
    {
        .bytes = &bytes_examples[1],
        .bufsz = 4096,
        .len = 0
    },
    {
        .bytes = &bytes_examples[2],
        .bufsz = 4096,
        .len = 0
    }
};

int main(int argc, char *argv[]) {
    int n_cases = sizeof(test_cases) / sizeof(struct test_case);
    int i = 0;
    for (i = 0; i < n_cases; i++) {
        run_test_case(&(test_cases[i]));
    }
    return 0;
}