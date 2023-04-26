#include "bytes_codec_binary.h"
#include "fhmsg_debug.h"
#include "fhmsg_err.h"
#include <stdio.h>
#include <string.h>

int bytes_dec_binary_cpy(uint8_t *outbuf, int outlen, const uint8_t *buffer, int bufsz, int *len) {
    if (outbuf == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_binary_cpy: outbuf == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_binary_cpy: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < outlen) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_binary_cpy: bufsz < outlen\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    memcpy(outbuf, buffer, outlen);
    if (len != NULL) {
        *len = outlen;
    }
    return 0;
}

int bytes_enc_binary_cpy(const uint8_t *inbuf, int inlen, uint8_t *buffer, int bufsz, int *len) {
    if (inbuf == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_enc_binary_cpy: inbuf == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_enc_binary_cpy: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < inlen) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_enc_binary_cpy: bufsz < inlen\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    memcpy(buffer, inbuf, inlen);
    if (len != NULL) {
        *len = inlen;
    }
    return 0;
}

int bytes_dec_binary_ref(uint8_t **outref, int outlen, const uint8_t *buffer, int bufsz, int *len) {
    if (outref == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_binary_ref: outref == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_binary_ref: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < outlen) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_binary_ref: bufsz < outlen\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    *outref = (uint8_t *) buffer;
    if (len != NULL) {
        *len = outlen;
    }
    return 0;
}

int bytes_enc_binary_ref(const uint8_t *inref, int inlen, uint8_t *buffer, int bufsz, int *len) {
    if (inref == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_enc_binary_ref: inref == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_enc_binary_ref: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bufsz < inlen) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_enc_binary_ref: bufsz < inlen\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    memcpy(buffer, inref, inlen);
    if (len != NULL) {
        *len = inlen;
    }
    return 0;
}