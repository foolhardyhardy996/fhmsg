#pragma once 

#include "bytes_struct.h"
#include <stdint.h>

int bytes_dec_binary_cpy(struct bytes_struct *bytes, const uint8_t *buffer, int bufsz, int *scanned);
int bytes_enc_binary_cpy(const struct bytes_struct *bytes, uint8_t *buffer, int bufsz, int *scanned);
int bytes_dec_binary_ref(struct bytes_struct *bytes, const uint8_t *buffer, int bufsz, int *scanned);
int bytes_enc_binary_ref(const struct bytes_struct *bytes, uint8_t *buffer, int bufsz, int *scanned);