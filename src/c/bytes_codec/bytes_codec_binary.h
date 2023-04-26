#pragma once 

#include <stdint.h>

int bytes_dec_binary_cpy(uint8_t *outbuf, int outlen, const uint8_t *buffer, int bufsz, int *len);
int bytes_enc_binary_cpy(const uint8_t *inbuf, int inlen, uint8_t *buffer, int bufsz, int *len);
int bytes_dec_binary_ref(uint8_t **outref, int outlen, const uint8_t *buffer, int bufsz, int *len);
int bytes_enc_binary_ref(const uint8_t *inref, int inlen, uint8_t *buffer, int bufsz, int *len);