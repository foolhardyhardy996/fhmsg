#pragma once 

#include <stdint.h>
/* function naming convention: 
 * ["type"]_[enc/dec]_[binary/text]_["format"]()
 */

// for dec functions, bufsz is not required, but I reserved them for interface consistency
int uint8_dec_text_hex(uint8_t *output, char *buffer, int bufsz, int *scanned);
int uint8_enc_text_hex(const uint8_t *input, char *buffer, int bufsz, int *scanned);
int uint8_dec_text_decimal(uint8_t *output, char *buffer, int bufsz, int *scanned);
int uint8_enc_text_decimal(const uint8_t *input, char *buffer, int bufsz, int *scanned);

int uint16_dec_text_hex(uint16_t *output, char *buffer, int bufsz, int *scanned);
int uint16_enc_text_hex(const uint16_t *input, char *buffer, int bufsz, int *scanned);
int uint16_dec_text_decimal(uint16_t *output, char *buffer, int bufsz, int *scanned);
int uint16_enc_text_decimal(const uint16_t *input, char *buffer, int bufsz, int *scanned);

int uint32_dec_text_hex(uint32_t *output, char *buffer, int bufsz, int *scanned);
int uint32_enc_text_hex(const uint32_t *input, char *buffer, int bufsz, int *scanned);
int uint32_dec_text_decimal(uint32_t *output, char *buffer, int bufsz, int *scanned);
int uint32_enc_text_decimal(const uint32_t *input, char *buffer, int bufsz, int *scanned);

int uint64_dec_text_hex(uint64_t *output, char *buffer, int bufsz, int *scanned);
int uint64_enc_text_hex(const uint64_t *input, char *buffer, int bufsz, int *scanned);
int uint64_dec_text_decimal(uint64_t *output, char *buffer, int bufsz, int *scanned);
int uint64_enc_text_decimal(const uint64_t *input, char *buffer, int bufsz, int *scanned);