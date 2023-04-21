#include "uint_codec_binary.h"
#include "fhmsg_debug.h"
#include "fhmsg_err.h"
#include <stdio.h>

int is_be(void) {
    static int is_big_endian = -1;
    static uint16_t foo = 0xff00;
    if (is_big_endian == -1) {
        if (((uint8_t *) &foo)[0] == 0xff) {
            is_big_endian = 1;
        } else {
            is_big_endian = 0;
        }
    }
    return is_big_endian;
}

int is_le(void) {
    static int is_little_endian = -1;
    static uint16_t foo = 0xff00;
    if (is_little_endian == -1) {
        if (((uint8_t *) &foo)[0] == 0x00) {
            is_little_endian = 1;
        } else {
            is_little_endian = 0;
        }
    }
    return is_little_endian;
}

int uint8_dec_binary_be(uint8_t *output, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 1;
    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_dec_binary_be: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_dec_binary_be: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_dec_binary_be: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    *output = buffer[0];
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}

int uint8_enc_binary_be(const uint8_t *input, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 1;
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_enc_binary_be: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_enc_binary_be: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    buffer[0] = *input;
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}

int uint8_dec_binary_le(uint8_t *output, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 1;
    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_dec_binary_le: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_dec_binary_le: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_dec_binary_le: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    *output = buffer[0];
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}

int uint8_enc_binary_le(const uint8_t *input, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 1;
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_enc_binary_le: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint8_enc_binary_le: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    buffer[0] = *input;
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}

int uint16_dec_binary_be(uint16_t *output, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 2;
    uint8_t *cast_output;
    int i = 0;
    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_dec_binary_be: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_dec_binary_be: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_dec_binary_be: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    if (is_be()) {
        *output = *((uint16_t *) buffer);
    } else {
        cast_output = (uint8_t *) output;
        for (i = 0; i < expected_len; i++) {
            cast_output[i] = buffer[expected_len-1-i];
        }
    }
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}

int uint16_enc_binary_be(const uint16_t *input, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 2;
    const uint8_t *cast_input;
    int i;
    if (input == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_enc_binary_be: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_enc_binary_be: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_enc_binary_be: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    if (is_be()) {
        *((uint16_t *) buffer) = *input;
    } else {
        cast_input = (const uint8_t *) input;
        for (i = 0; i < expected_len; i++) {
            buffer[i] = cast_input[expected_len-1-i];
        }
    }
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}

int uint16_dec_binary_le(uint16_t *output, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 2;
    uint8_t *cast_output;
    int i = 0;
    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_dec_binary_le: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_dec_binary_le: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_dec_binary_le: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    if (is_le()) {
        *output = *((uint16_t *) buffer);
    } else {
        cast_output = (uint8_t *) output;
        for (i = 0; i < expected_len; i++) {
            cast_output[i] = buffer[expected_len-1-i];
        }
    }
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}

int uint16_enc_binary_le(const uint16_t *input, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 2;
    const uint8_t *cast_input;
    int i;
    if (input == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_enc_binary_le: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_enc_binary_le: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint16_enc_binary_le: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    if (is_le()) {
        *((uint16_t *) buffer) = *input;
    } else {
        cast_input = (const uint8_t *) input;
        for (i = 0; i < expected_len; i++) {
            buffer[i] = cast_input[expected_len-1-i];
        }
    }
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}

int uint32_dec_binary_be(uint32_t *output, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 4;
    uint8_t *cast_output;
    int i = 0;
    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_dec_binary_be: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_dec_binary_be: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_dec_binary_be: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    if (is_be()) {
        *output = *((uint32_t *) buffer);
    } else {
        cast_output = (uint8_t *) output;
        for (i = 0; i < expected_len; i++) {
            cast_output[i] = buffer[expected_len-1-i];
        }
    }
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}

int uint32_enc_binary_be(const uint32_t *input, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 4;
    const uint8_t *cast_input;
    int i;
    if (input == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_enc_binary_be: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_enc_binary_be: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_enc_binary_be: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    if (is_be()) {
        *((uint32_t *) buffer) = *input;
    } else {
        cast_input = (const uint8_t *) input;
        for (i = 0; i < expected_len; i++) {
            buffer[i] = cast_input[expected_len-1-i];
        }
    }
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}

int uint32_dec_binary_le(uint32_t *output, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 4;
    uint8_t *cast_output;
    int i = 0;
    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_dec_binary_le: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_dec_binary_le: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_dec_binary_le: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    if (is_le()) {
        *output = *((uint32_t *) buffer);
    } else {
        cast_output = (uint8_t *) output;
        for (i = 0; i < expected_len; i++) {
            cast_output[i] = buffer[expected_len-1-i];
        }
    }
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}

int uint32_enc_binary_le(const uint32_t *input, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 4;
    const uint8_t *cast_input;
    int i;
    if (input == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_enc_binary_le: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_enc_binary_le: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint32_enc_binary_le: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    if (is_le()) {
        *((uint32_t *) buffer) = *input;
    } else {
        cast_input = (const uint8_t *) input;
        for (i = 0; i < expected_len; i++) {
            buffer[i] = cast_input[expected_len-1-i];
        }
    }
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}

int uint64_dec_binary_be(uint64_t *output, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 8;
    uint8_t *cast_output;
    int i = 0;
    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_dec_binary_be: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_dec_binary_be: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_dec_binary_be: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    if (is_be()) {
        *output = *((uint64_t *) buffer);
    } else {
        cast_output = (uint8_t *) output;
        for (i = 0; i < expected_len; i++) {
            cast_output[i] = buffer[expected_len-1-i];
        }
    }
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}

int uint64_enc_binary_be(const uint64_t *input, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 8;
    const uint8_t *cast_input;
    int i;
    if (input == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_enc_binary_be: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_enc_binary_be: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_enc_binary_be: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    if (is_be()) {
        *((uint64_t *) buffer) = *input;
    } else {
        cast_input = (const uint8_t *) input;
        for (i = 0; i < expected_len; i++) {
            buffer[i] = cast_input[expected_len-1-i];
        }
    }
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}

int uint64_dec_binary_le(uint64_t *output, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 8;
    uint8_t *cast_output;
    int i = 0;
    if (output == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_dec_binary_le: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_dec_binary_le: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_dec_binary_le: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    if (is_le()) {
        *output = *((uint64_t *) buffer);
    } else {
        cast_output = (uint8_t *) output;
        for (i = 0; i < expected_len; i++) {
            cast_output[i] = buffer[expected_len-1-i];
        }
    }
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}

int uint64_enc_binary_le(const uint64_t *input, uint8_t *buffer, int bufsz, int *len) {
    int expected_len = 8;
    const uint8_t *cast_input;
    int i;
    if (input == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_enc_binary_le: output == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_enc_binary_le: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < expected_len) {
        FHMSG_DEBUG_printf("[ERROR]: uint64_enc_binary_le: bufsz < expected_len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    if (is_le()) {
        *((uint64_t *) buffer) = *input;
    } else {
        cast_input = (const uint8_t *) input;
        for (i = 0; i < expected_len; i++) {
            buffer[i] = cast_input[expected_len-1-i];
        }
    }
    if (len != NULL) {
        *len = expected_len;
    }
    return 0;
}
