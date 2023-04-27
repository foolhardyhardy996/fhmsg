#include "bytes_codec_text.h"
#include "bytes_struct.h"
#include "fhmsg_debug.h"
#include "fhmsg_err.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

static int get_xdigitseq_len(const char *buf, int bufsz);
static uint8_t char2hexval(char c);
static uint8_t hexrepr2byte(char c1, char c2);

static int get_xdigitseq_len(const char *buf, int bufsz) {
    int i;
    for (i = 0; i < bufsz; i++) {
        if (isxdigit(buf[i]) == 0) {
            break;
        }
    }
    return i;
}

static uint8_t char2hexval(char c) {
    char buf[2] = {c, 0};
    if (isxdigit(c) == 0) {
        //printf("[DEBUG]: %c is not xdigit\n", c);
        return 0;
    } else {
        //printf("[DEBUG]: % is converted to %d\n", c, atoi(buf));
        return strtol(buf, NULL, 16);
    }
}

static uint8_t hexrepr2byte(char c1, char c2) {
    unsigned v1 = char2hexval(c1), v2 = char2hexval(c2);
    //printf("[DEBUG]: c1 = %c, v1 = %u, c2 = %c, v2 = %u\n", c1, v1, c2, v2);
    return v1 << 4 | v2;
}

int bytes_dec_text_nosep(struct bytes_struct *bytes, const char *buffer, int bufsz, int *scanned) {
    int strl = get_xdigitseq_len(buffer, bufsz);
    int least_bufsz = strl / 2;
    int i, j;
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_text_nosep: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bytes == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_text_nosep: bytes == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (strl % 2 != 0) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_text_nosep: illegal format\n");
        return FHMSG_ERR_FORMAT;
    }
    if (bytes->buf == NULL) {
        bytes->len = least_bufsz;
        return 0;
    }
    if (bytes->bufsz < least_bufsz) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_text_nosep: insuffient buffer\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    if (bytes->bufsz < least_bufsz) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_text_nosep: outbufsz is insufficient\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    for (i = 0, j = 0; i < least_bufsz; i++, j += 2) {
        bytes->buf[i] = hexrepr2byte(buffer[j], buffer[j+1]);
    }
    if (scanned != NULL) {
        *scanned = j; 
    }
    return 0;
}

int bytes_enc_text_nosep(const struct bytes_struct *bytes, char *buffer, int bufsz, int *scanned) {
    int least_bufsz;
    int i, j;
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_text_nosep: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bytes == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_text_nosep: bytes == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (bytes->buf == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_text_nosep: bytes->buf == NULL\n");
        return FHMSG_ERR_NULL;
    }
    least_bufsz = bytes->len * 2 + 1;
    if (bufsz < least_bufsz) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_text_nosep: insuffient buffer\n");
        return FHMSG_ERR_NULL;
    }
    for (i = 0, j = 0; i < bytes->len; i++, j += 2) {
        sprintf(buffer+j, "%02x", bytes->buf[i]);
    }
    if (scanned != NULL) {
        *scanned = j;
    }
    return 0;
}