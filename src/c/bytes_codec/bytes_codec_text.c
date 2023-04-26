#include <ctype.h>

static uint8_t char2hexval(char c) {
    uint8_t v = 0;
    if (isalnum(c)) {
        if (isdigit(c)) {
            v = c - '0';
        } else if (islower(c)) {
            v = (c - 'a') + 10;
        } else if (isupper(c)) {
            v = (c - 'A') + 10;
        }
    }
    return v;
}

static uint8_t hexrepr2byte(char c1, char c2) {
    unsigned v1 = char2hexval(c1), v2 = char2hexval(c2);
    return v1 << 4 | v2;
}

int bytes_dec_text_nosep(uint8_t *outbuf, int outbufsz, char *buffer, int bufsz, int *len) {
    int strl = strlen(buffer);
    int least_outbufsz = strl / 2;
    int i = 0, j = 0;
    if (buffer == NULL) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_text_nosep: buffer == NULL\n");
        return FHMSG_ERR_NULL;
    }
    if (strl % 2 != 0) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_text_nosep: illegal format\n");
        return FHMSG_ERR_FORMAT;
    }
    if (outbuf == NULL) {
        if (len == NULL) {
            FHMSG_DEBUG_printf("[ERROR]: bytes_dec_text_nosep: outbuf == NULL && len == NULL\n");
            return FHMSG_ERR_NULL;
        } else {
            *len = ;
            return 0;
        }
    } 
    if (outbufsz < least_outbufsz) {
        FHMSG_DEBUG_printf("[ERROR]: bytes_dec_text_nosep: outbufsz is insufficient\n");
        return FHMSG_ERR_BUFFSIZE;
    }
    for (; i < least_outbufsz; i++, j += 2) {
        outbuf[i] = hexrepr2byte(buffer[j], buffer[j+1]);
    }
    if (len != NULL) {
        *len = 
    }
}

int bytes_enc_text_nosep(const uint8_t *input, int inlen, char *buffer, int bufsz, int *len);