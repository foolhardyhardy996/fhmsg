#include "bytes_codec_binary.h"
#include "fhmsg_debug.h"
#include "fhmsg_err.h"
#include <stdio.h>
#include <string.h>

int bytes_dec_binary_cpy(struct bytes_struct *bytes, const uint8_t *buffer, int bufsz, int *scanned) {
    if (bytes == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_binary_cpy: bytes == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_binary_cpy: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < bytes->len) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_binary_cpy: bufsz < bytes->len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    memcpy(bytes->buf, buffer, bytes->len);
    if (scanned != NULL) {
        *scanned = bytes->len;
    }
    return 0;
}

int bytes_enc_binary_cpy(const struct bytes_struct *bytes, uint8_t *buffer, int bufsz, int *scanned) {
    if (bytes == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_enc_binary_cpy: bytes == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_enc_binary_cpy: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < bytes->len) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_enc_binary_cpy: bufsz < bytes->len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    memcpy(buffer, bytes->buf, bytes->len);
    if (scanned != NULL) {
        *scanned = bytes->len;
    }
    return 0;
}

int bytes_dec_binary_ref(struct bytes_struct *bytes, const uint8_t *buffer, int bufsz, int *scanned) {
    if (bytes == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_binary_ref: bytes == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_binary_ref: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < bytes->len) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_binary_ref: bufsz < bytes->len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    bytes->buf = (uint8_t *) buffer;
    if (scanned != NULL) {
        *scanned = bytes->len;
    }
    return 0;
}

int bytes_enc_binary_ref(const struct bytes_struct *bytes, uint8_t *buffer, int bufsz, int *scanned) {
    if (bytes == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_enc_binary_ref: bytes == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_enc_binary_ref: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < bytes->len) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_enc_binary_ref: bufsz < bytes->len\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    memcpy(buffer, bytes->buf, bytes->len);
    if (scanned != NULL) {
        *scanned = bytes->len;
    }
    return 0;
}
