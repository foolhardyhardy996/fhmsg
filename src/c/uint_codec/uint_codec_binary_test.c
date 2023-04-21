#include "uint_codec_binary.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct test_case {
    int bitsize;
    uint8_t uint8_val;
    uint16_t uint16_val;
    uint32_t uint32_val;
    uint64_t uint64_val;
    uint8_t buffer[8];
    int bufsz;
};

static void run_test_case(struct test_case *test_case) {
    uint8_t uint8_val;
    uint16_t uint16_val;
    uint32_t uint32_val;
    uint64_t uint64_val;
    switch (test_case->bitsize) {
    case 8:
        uint8_enc_binary_be(&(test_case->uint8_val), test_case->buffer, test_case->bufsz, NULL);
        uint8_dec_binary_be(&uint8_val, test_case->buffer, test_case->bufsz, NULL);
        if (test_case->uint8_val != uint8_val) {
            printf("[ERROR]: uint8_codec_binary_be returned inconsistent result\n");
            exit(0);
        } else {
            printf("[INFO]: uint8_codec_binary_be passed basic test.\n");
        }
        uint8_enc_binary_le(&(test_case->uint8_val), test_case->buffer, test_case->bufsz, NULL);
        uint8_dec_binary_le(&uint8_val, test_case->buffer, test_case->bufsz, NULL);
        if (test_case->uint8_val != uint8_val) {
            printf("[ERROR]: uint8_codec_binary_le returned inconsistent result\n");
            exit(0);
        } else {
            printf("[INFO]: uint8_codec_binary_le passed basic test.\n");
        }
        break;
    case 16:
        uint16_enc_binary_be(&(test_case->uint16_val), test_case->buffer, test_case->bufsz, NULL);
        uint16_dec_binary_be(&uint16_val, test_case->buffer, test_case->bufsz, NULL);
        if (test_case->uint16_val != uint16_val) {
            printf("[ERROR]: uint16_codec_binary_be returned inconsistent result\n");
            exit(0);
        } else {
            printf("[INFO]: uint16_codec_binary_be passed basic test.\n");
        } 
        uint16_enc_binary_le(&(test_case->uint16_val), test_case->buffer, test_case->bufsz, NULL);
        uint16_dec_binary_le(&uint16_val, test_case->buffer, test_case->bufsz, NULL);
        if (test_case->uint16_val != uint16_val) {
            printf("[ERROR]: uint16_codec_binary_le returned inconsistent result\n");
            exit(0);
        } else {
            printf("[INFO]: uint16_codec_binary_le passed basic test.\n");
        }
        break;
    case 32:
        uint32_enc_binary_be(&(test_case->uint32_val), test_case->buffer, test_case->bufsz, NULL);
        uint32_dec_binary_be(&uint32_val, test_case->buffer, test_case->bufsz, NULL);
        if (test_case->uint32_val != uint32_val) {
            printf("[ERROR]: uint32_codec_binary_be returned inconsistent result\n");
            exit(0);
        } else {
            printf("[INFO]: uint32_codec_binary_be passed basic test.\n");
        }
        uint32_enc_binary_le(&(test_case->uint32_val), test_case->buffer, test_case->bufsz, NULL);
        uint32_dec_binary_le(&uint32_val, test_case->buffer, test_case->bufsz, NULL);
        if (test_case->uint32_val != uint32_val) {
            printf("[ERROR]: uint32_codec_binary_le returned inconsistent result\n");
            exit(0);
        } else {
            printf("[INFO]: uint32_codec_binary_le passed basic test.\n");
        }
        break;
    case 64:
        uint64_enc_binary_be(&(test_case->uint64_val), test_case->buffer, test_case->bufsz, NULL);
        uint64_dec_binary_be(&uint64_val, test_case->buffer, test_case->bufsz, NULL);
        if (test_case->uint64_val != uint64_val) {
            printf("[ERROR]: uint64_codec_binary_be returned inconsistent result\n");
            exit(0);
        } else {
            printf("[INFO]: uint64_codec_binary_be passed basic test.\n");
        }
        uint64_enc_binary_le(&(test_case->uint64_val), test_case->buffer, test_case->bufsz, NULL);
        uint64_dec_binary_le(&uint64_val, test_case->buffer, test_case->bufsz, NULL);
        if (test_case->uint64_val != uint64_val) {
            printf("[ERROR]: uint64_codec_binary_le return inconsistent result\n");
            exit(0);
        } else {
            printf("[INFO]: uint64_codec_binary_le passed basic test.\n");
        }
        break;
    default:
        printf("[ERROR]: illegal 'bitsize' setting in test case\n");
        exit(0);
    }
}

struct test_case test_cases[] = {
    {
        .bitsize = 8,
        .uint8_val = 0xff, 
        .bufsz = 8
    }, 
    {
        .bitsize = 8,
        .uint8_val = 0xac, 
        .bufsz = 8
    }, 
    {
        .bitsize = 16,
        .uint16_val = 0xff00, 
        .bufsz = 8
    }, 
    {
        .bitsize = 16,
        .uint16_val = 0xabcd, 
        .bufsz = 8
    },
    {
        .bitsize = 32,
        .uint32_val = 0xfe01023f, 
        .bufsz = 8
    },
    {
        .bitsize = 32,
        .uint32_val = 0x00ff1122, 
        .bufsz = 8
    },
    {
        .bitsize = 64,
        .uint64_val = 0xff00000000000000LL, 
        .bufsz = 8
    },
    {
        .bitsize = 64,
        .uint64_val = 0x1122334455667788LL, 
        .bufsz = 8
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