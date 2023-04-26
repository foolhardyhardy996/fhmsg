#include "bytes_struct.h"

void bytes_struct_init(struct bytes_struct *bytes, uint8_t *buf, int bufsz, int len) {
    bytes->buf = buf;
    bytes->bufsz = bufsz;
    bytes->len = len;
}