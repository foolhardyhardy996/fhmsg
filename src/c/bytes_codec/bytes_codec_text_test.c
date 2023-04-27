#include "bytes_struct.h"
#include "bytes_codec_text.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct test_case {
    struct bytes_struct *bytes;
    char buffer[4096];
    int bufsz;
    int len;
};

static void run_test_case(struct test_case *test_case);

static void run_test_case(struct test_case *test_case) {
    int ret;
    int len = 0;
    char buf[4096];
    struct bytes_struct bytes;
    int i = 0;

    bytes_struct_init(&bytes, buf, 4096, test_case->bytes->len);
    bytes_enc_text_nosep(test_case->bytes, test_case->buffer, test_case->bufsz, &len);
    printf("[INFO]: text repr = %s, enc len = %d\n", test_case->buffer, len);
    bytes_dec_text_nosep(&bytes, test_case->buffer, test_case->bufsz, &len);
    printf("[INFO]: dec len = %d\n", len);
    for (i = 0; i < bytes.len; i++) {
        printf("%02x ", bytes.buf[i]);
    }
    printf("\n");
    if (memcmp(test_case->bytes->buf, bytes.buf, bytes.len) != 0) {
        printf("[ERROR]: bytes_codec_binary_cpy returned inconsistent result.\n");
        exit(0);
    } else {
        printf("[INFO]: bytes_codec_binary_cpy passed basic test.\n");
    }
}

uint8_t bytes1[] = {0xab};
uint8_t bytes2[] = {0xcd, 0xef};
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