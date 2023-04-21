#include "uint_codec_text.h"
#include "fhmsg_err.h"
#include "fhmsg_debug.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

int uint8_dec_text_hex(uint8_t *output, char *buffer, int bufsz, int *len) {
    uint64_t output_holder;
    char *end_of_parse;

    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_dec_text_hex: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_dec_text_hex: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    output_holder = strtoull(buffer, &end_of_parse, 16);
    if (end_of_parse == buffer) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_dec_text_hex: fail to parse '%s'\n", buffer);
        return FHMSG_ERR_FORMAT;
    }
    if (output_holder > UCHAR_MAX) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_dec_text_hex: %d out of range\n", output_holder);
        return FHMSG_ERR_RANGE;
    }
    *output = (uint8_t) output_holder;
    return 0;
}

int uint8_enc_text_hex(const uint8_t *input, char *buffer, int bufsz, int *len) {
    char safe_buffer[8] = {0};
    int sbufsz = 8;
    int ret;

    if (input == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_enc_text_hex: input == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_enc_text_hex: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    ret = snprintf(safe_buffer, sbufsz, "0x%X", *input);
    if (ret < 0) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_enc_text_hex: fail to encode.\n");
        return FHMSG_ERR_FORMAT;
    }
    if (ret + 1 > bufsz) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_enc_text_hex: insufficient buffer.\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    strcpy(buffer, safe_buffer);
    if (len != NULL) {
        *len = ret + 1;
    }
    return 0;
}

int uint8_dec_text_decimal(uint8_t *output, char *buffer, int bufsz, int *len) {
    uint64_t output_holder;
    char *end_of_parse;

    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_dec_text_decimal: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_dec_text_decimal: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    output_holder = strtoull(buffer, &end_of_parse, 10);
    if (end_of_parse == buffer) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_dec_text_decimal: fail to parse '%s'\n", buffer);
        return FHMSG_ERR_FORMAT;
    }
    if (output_holder > UCHAR_MAX) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_dec_text_decimal: %d out of range\n", output_holder);
        return FHMSG_ERR_RANGE;
    }
    *output = (uint8_t) output_holder;
    return 0;
}

int uint8_enc_text_decimal(const uint8_t *input, char *buffer, int bufsz, int *len) {
    char safe_buffer[8] = {0};
    int sbufsz = 8;
    int ret;

    if (input == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_enc_text_decimal: input == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_enc_text_decimal: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    ret = snprintf(safe_buffer, sbufsz, "%u", *input);
    if (ret < 0) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_enc_text_decimal: fail to encode.\n");
        return FHMSG_ERR_FORMAT;
    }
    if (ret + 1 > bufsz) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_enc_text_decimal: insufficient buffer.\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    strcpy(buffer, safe_buffer);
    if (len != NULL) {
        *len = ret + 1;
    }
    return 0;
}

int uint16_dec_text_hex(uint16_t *output, char *buffer, int bufsz, int *len) {
    uint64_t output_holder;
    char *end_of_parse;

    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_dec_text_hex: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_dec_text_hex: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    output_holder = strtoull(buffer, &end_of_parse, 16);
    if (end_of_parse == buffer) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_dec_text_hex: fail to parse '%s'\n", buffer);
        return FHMSG_ERR_FORMAT;
    }
    if (output_holder > USHRT_MAX) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_dec_text_hex: %d out of range\n", output_holder);
        return FHMSG_ERR_RANGE;
    }
    *output = (uint16_t) output_holder;
    return 0;
}

int uint16_enc_text_hex(const uint16_t *input, char *buffer, int bufsz, int *len) {
    char safe_buffer[16] = {0};
    int sbufsz = 16;
    int ret;

    if (input == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_enc_text_hex: input == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_enc_text_hex: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    ret = snprintf(safe_buffer, sbufsz, "0x%X", *input);
    if (ret < 0) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_enc_text_hex: fail to encode.\n");
        return FHMSG_ERR_FORMAT;
    }
    if (ret + 1 > bufsz) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_enc_text_hex: insufficient buffer.\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    strcpy(buffer, safe_buffer);
    if (len != NULL) {
        *len = ret + 1;
    }
    return 0;
}

int uint16_dec_text_decimal(uint16_t *output, char *buffer, int bufsz, int *len) {
    uint64_t output_holder;
    char *end_of_parse;

    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_dec_text_decimal: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_dec_text_decimal: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    output_holder = strtoull(buffer, &end_of_parse, 10);
    if (end_of_parse == buffer) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_dec_text_decimal: fail to parse '%s'\n", buffer);
        return FHMSG_ERR_FORMAT;
    }
    if (output_holder > USHRT_MAX) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_dec_text_decimal: %d out of range\n", output_holder);
        return FHMSG_ERR_RANGE;
    }
    *output = (uint16_t) output_holder;
    return 0;
}

int uint16_enc_text_decimal(const uint16_t *input, char *buffer, int bufsz, int *len) {
    char safe_buffer[16] = {0};
    int sbufsz = 16;
    int ret;

    if (input == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_enc_text_decimal: input == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_enc_text_decimal: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    ret = snprintf(safe_buffer, sbufsz, "%u", *input);
    if (ret < 0) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_enc_text_decimal: fail to encode.\n");
        return FHMSG_ERR_FORMAT;
    }
    if (ret + 1 > bufsz) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_enc_text_decimal: insufficient buffer.\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    strcpy(buffer, safe_buffer);
    if (len != NULL) {
        *len = ret + 1;
    }
    return 0;
}

int uint32_dec_text_hex(uint32_t *output, char *buffer, int bufsz, int *len) {
    uint64_t output_holder;
    char *end_of_parse;

    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_dec_text_hex: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_dec_text_hex: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    output_holder = strtoull(buffer, &end_of_parse, 16);
    if (end_of_parse == buffer) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_dec_text_hex: fail to parse '%s'\n", buffer);
        return FHMSG_ERR_FORMAT;
    }
    if (output_holder > UINT_MAX) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_dec_text_hex: %d out of range\n", output_holder);
        return FHMSG_ERR_RANGE;
    }
    *output = (uint32_t) output_holder;
    return 0;
}

int uint32_enc_text_hex(const uint32_t *input, char *buffer, int bufsz, int *len) {
    char safe_buffer[32] = {0};
    int sbufsz = 32;
    int ret;

    if (input == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_enc_text_hex: input == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_enc_text_hex: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    ret = snprintf(safe_buffer, sbufsz, "0x%X", *input);
    if (ret < 0) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_enc_text_hex: fail to encode.\n");
        return FHMSG_ERR_FORMAT;
    }
    if (ret + 1 > bufsz) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_enc_text_hex: insufficient buffer.\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    strcpy(buffer, safe_buffer);
    if (len != NULL) {
        *len = ret + 1;
    }
    return 0;
}

int uint32_dec_text_decimal(uint32_t *output, char *buffer, int bufsz, int *len) {
    uint64_t output_holder;
    char *end_of_parse;

    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_dec_text_decimal: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_dec_text_decimal: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    output_holder = strtoull(buffer, &end_of_parse, 10);
    if (end_of_parse == buffer) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_dec_text_decimal: fail to parse '%s'\n", buffer);
        return FHMSG_ERR_FORMAT;
    }
    if (output_holder > UINT_MAX) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_dec_text_decimal: %d out of range\n", output_holder);
        return FHMSG_ERR_RANGE;
    }
    *output = (uint32_t) output_holder;
    return 0;
}

int uint32_enc_text_decimal(const uint32_t *input, char *buffer, int bufsz, int *len) {
    char safe_buffer[32] = {0};
    int sbufsz = 32;
    int ret;

    if (input == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_enc_text_decimal: input == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_enc_text_decimal: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    ret = snprintf(safe_buffer, sbufsz, "%u", *input);
    if (ret < 0) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_enc_text_decimal: fail to encode.\n");
        return FHMSG_ERR_FORMAT;
    }
    if (ret + 1 > bufsz) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_enc_text_decimal: insufficient buffer.\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    strcpy(buffer, safe_buffer);
    if (len != NULL) {
        *len = ret + 1;
    }
    return 0;
}

int uint64_dec_text_hex(uint64_t *output, char *buffer, int bufsz, int *len) {
    uint64_t output_holder;
    char *end_of_parse;

    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_dec_text_hex: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_dec_text_hex: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    output_holder = strtoull(buffer, &end_of_parse, 16);
    if (end_of_parse == buffer) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_dec_text_hex: fail to parse '%s'\n", buffer);
        return FHMSG_ERR_FORMAT;
    }
    if (output_holder > ULLONG_MAX) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_dec_text_hex: %llu out of range\n", output_holder);
        return FHMSG_ERR_RANGE;
    }
    *output = output_holder;
    return 0;
}

int uint64_enc_text_hex(const uint64_t *input, char *buffer, int bufsz, int *len) {
    char safe_buffer[32] = {0};
    int sbufsz = 32;
    int ret;

    if (input == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_enc_text_hex: input == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_enc_text_hex: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    ret = snprintf(safe_buffer, sbufsz, "0x%llX", *input);
    if (ret < 0) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_enc_text_hex: fail to encode.\n");
        return FHMSG_ERR_FORMAT;
    }
    if (ret + 1 > bufsz) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_enc_text_hex: insufficient buffer.\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    strcpy(buffer, safe_buffer);
    if (len != NULL) {
        *len = ret + 1;
    }
    return 0;
}

int uint64_dec_text_decimal(uint64_t *output, char *buffer, int bufsz, int *len) {
    uint64_t output_holder;
    char *end_of_parse;

    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_dec_text_decimal: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_dec_text_decimal: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    output_holder = strtoull(buffer, &end_of_parse, 10);
    if (end_of_parse == buffer) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_dec_text_decimal: fail to parse '%s'\n", buffer);
        return FHMSG_ERR_FORMAT;
    }
    if (output_holder > ULLONG_MAX) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_dec_text_decimal: %llu out of range\n", output_holder);
        return FHMSG_ERR_RANGE;
    }
    *output = output_holder;
    return 0;
}

int uint64_enc_text_decimal(const uint64_t *input, char *buffer, int bufsz, int *len) {
    char safe_buffer[32] = {0};
    int sbufsz = 32;
    int ret;

    if (input == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_enc_text_decimal: input == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_enc_text_decimal: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    ret = snprintf(safe_buffer, sbufsz, "%llu", *input);
    if (ret < 0) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_enc_text_decimal: fail to encode.\n");
        return FHMSG_ERR_FORMAT;
    }
    if (ret + 1 > bufsz) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_enc_text_decimal: insufficient buffer.\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    strcpy(buffer, safe_buffer);
    if (len != NULL) {
        *len = ret + 1;
    }
    return 0;
}