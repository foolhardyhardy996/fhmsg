#pragma once 

#include <stdint.h>

int is_be(void);
int is_le(void);

/* function naming convention: 
 * ["type"]_[enc/dec]_[binary/text]_["format"]()
 */

int uint8_dec_binary_be(uint8_t *output, const uint8_t *buffer, int bufsz, int *scanned);
int uint8_enc_binary_be(const uint8_t *input, uint8_t *buffer, int bufsz, int *scanned);
int uint8_dec_binary_le(uint8_t *output, const uint8_t *buffer, int bufsz, int *scanned);
int uint8_enc_binary_le(const uint8_t *input, uint8_t *buffer, int bufsz, int *scanned);

int uint16_dec_binary_be(uint16_t *output, const uint8_t *buffer, int bufsz, int *scanned);
int uint16_enc_binary_be(const uint16_t *input, uint8_t *buffer, int bufsz, int *scanned);
int uint16_dec_binary_le(uint16_t *output, const uint8_t *buffer, int bufsz, int *scanned);
int uint16_enc_binary_le(const uint16_t *input, uint8_t *buffer, int bufsz, int *scanned);

int uint32_dec_binary_be(uint32_t *output, const uint8_t *buffer, int bufsz, int *scanned);
int uint32_enc_binary_be(const uint32_t *input, uint8_t *buffer, int bufsz, int *scanned);
int uint32_dec_binary_le(uint32_t *output, const uint8_t *buffer, int bufsz, int *scanned);
int uint32_enc_binary_le(const uint32_t *input, uint8_t *buffer, int bufsz, int *scanned);

int uint64_dec_binary_be(uint64_t *output, const uint8_t *buffer, int bufsz, int *scanned);
int uint64_enc_binary_be(const uint64_t *input, uint8_t *buffer, int bufsz, int *scanned);
int uint64_dec_binary_le(uint64_t *output, const uint8_t *buffer, int bufsz, int *scanned);
int uint64_enc_binary_le(const uint64_t *input, uint8_t *buffer, int bufsz, int *scanned);