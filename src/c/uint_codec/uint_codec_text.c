#include "uint_codec_text.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
    *output = output_holder;
    return 0;
}

int uint8_enc_text_hex(const uint8_t *input, char *buffer, int bufsz, int *len) {
    
}
