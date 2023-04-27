#pragma once 

#include "bytes_struct.h"

/* Usage note:
 * if bytes->buf == NULL, bytes->len is set to expected bufcap.
 */
int bytes_dec_text_nosep(struct bytes_struct *bytes, const char *buffer, int bufsz, int *scanned);
int bytes_enc_text_nosep(const struct bytes_struct *bytes, char *buffer, int bufsz, int *scanned);