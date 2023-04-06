#pragma once 

/**
 * @file handle_integer_field.c
 * @brief This module provides functions to serialize/deserialze 8-bit, 16-bit, 32-bit, and 64-bit (unsigned) integer.
 */

#include <stdint.h>
#include <stddef.h>
#include "handle_integer_field_err.h"

int is_be(void);
int is_le(void);

int deserialize_uint8_be(uint8_t *bytes, int len, uint8_t *res, int *taken);
int serialize_uint8_be(uint8_t n, uint8_t *buffer, int len, int *occupied);
int deserialize_uint8_le(uint8_t *bytes, int len, uint8_t *res, int *taken);
int serialize_uint8_le(uint8_t n, uint8_t *buffer, int len, int *occupied);
int deserialize_uint16_be(uint8_t *bytes, int len, uint16_t *res, int *taken);
int serialize_uint16_be(uint16_t n, uint8_t *buffer, int len, int *occupied);
int deserialize_uint16_le(uint8_t *bytes, int len, uint16_t *res, int *taken);
int serialize_uint16_le(uint16_t n, uint8_t *buffer, int len, int *occupied);

#ifdef uint32_t
int deserialize_uint32_be(uint8_t *bytes, int len, uint32_t *res, int *taken);
int serialize_uint32_be(uint32_t n, uint8_t *buffer, int len, int *occupied);
int deserialize_uint32_le(uint8_t *bytes, int len, uint32_t *res, int *taken);
int serialize_uint32_le(uint32_t n, uint8_t *buffer, int len, int *occupied);
#endif

#ifdef uint64_t
int deserialize_uint64_be(uint8_t *bytes, int len, uint64_t *res, int *taken);
int serialize_uint64_be(uint64_t n, uint8_t *buffer, int len, int *occupied);
int deserialize_uint64_le(uint8_t *bytes, int len, uint64_t *res, int *taken);
int serialize_uint64_le(uint64_t n, uint8_t *buffer, int len, int *occupied);
#endif 