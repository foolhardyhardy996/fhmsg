#pragma once 

int bytes_dec_text_nosep(uint8_t *outbuf, int outbufsz, int *outlen, char *buffer, int bufsz, int *scanned);
int bytes_enc_text_nosep(const uint8_t *inbuf, int inlen, char *buffer, int bufsz, int *scanned);