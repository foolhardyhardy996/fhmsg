#pragma once 

#include <stdint.h>

struct bytes_struct {
    uint8_t *buf;
    int bufsz;
    int len;
};

void bytes_struct_init(struct bytes_struct *bytes, uint8_t *buf, int bufsz, int len);