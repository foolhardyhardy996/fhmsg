/**
 * @file handle_integer_field.c
 * @brief This module provides functions to serialize/deserialze 8-bit, 16-bit, 32-bit, and 64-bit (unsigned) integer.
 */

#include <stdint.h>
#include <stddef.h>
#include "handle_integer_field.h"
#include "handle_integer_field_err.h"

int is_be(void) {
    static int is_big_endian = -1;
    static uint16_t foo = 0xff00;
    if (is_big_endian == -1) {
        if (((uint8_t *) &foo)[0] == 0xff) {
            is_big_endian = 1;
        } else {
            is_big_endian = 0;
        }
    }
    return is_big_endian;
}

int is_le(void) {
    static int is_little_endian = -1;
    static uint16_t foo = 0xff00;
    if (is_little_endian == -1) {
        if (((uint8_t *) &foo)[0] == 0x00) {
            is_little_endian = 1;
        } else {
            is_little_endian = 0;
        }
    }
    return is_little_endian;
}

int deserialize_uint8_be(uint8_t *bytes, int len, uint8_t *res, int *taken) {
    int taken_len = 1;
    if (bytes == NULL || res == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < taken_len) {
        return HIF_ERR_LEN;
    }
    *res = *bytes;
    if (taken != NULL) {
        *taken = taken_len;
    }
    return 0;
} 

int serialize_uint8_be(uint8_t n, uint8_t *buffer, int len, int *occupied) {
    int occupied_len = 1;
    if (buffer == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < occupied_len) {
        return HIF_ERR_LEN;
    }
    *buffer = n;
    if (occupied != NULL) {
        *occupied = occupied_len;
    }
    return 0;
}

int deserialize_uint8_le(uint8_t *bytes, int len, uint8_t *res, int *taken) {
    int taken_len = 1;
    if (bytes == NULL || res == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < taken_len) {
        return HIF_ERR_LEN;
    }
    *res = *bytes;
    if (taken != NULL) {
        *taken = taken_len;
    }
    return 0;
} 

int serialize_uint8_le(uint8_t n, uint8_t *buffer, int len, int *occupied) {
    int occupied_len = 1;
    if (buffer == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < occupied_len) {
        return HIF_ERR_LEN;
    }
    *buffer = n;
    if (occupied != NULL) {
        *occupied = occupied_len;
    }
    return 0;
}

int deserialize_uint16_be(uint8_t *bytes, int len, uint16_t *res, int *taken) {
    int taken_len = 2;
    uint8_t *ptr2res;
    int i = 0;
    if (bytes == NULL || res == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < taken_len) {
        return HIF_ERR_LEN;
    }
    if (is_be()) {
        *res = *((uint16_t *) bytes);
    } else {
        ptr2res = (uint8_t *) res;
        for (i = 0; i < taken_len; i++) {
            ptr2res[i] = bytes[taken_len-1-i];
        }
    }
    if (taken != NULL) {
        *taken = taken_len;
    }
    return 0;
} 

int serialize_uint16_be(uint16_t n, uint8_t *buffer, int len, int *occupied) {
    int occupied_len = 2;
    uint8_t *ptr2n;
    int i;
    if (buffer == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < occupied_len) {
        return HIF_ERR_LEN;
    }
    if (is_be()) {
        *((uint16_t *) buffer) = n;
    } else {
        ptr2n = (uint8_t *) &n;
        for (i = 0; i < occupied_len; i++) {
            buffer[i] = ptr2n[occupied_len-1-i];
        }
    }
    if (occupied != NULL) {
        *occupied = occupied_len;
    }
    return 0;
}

int deserialize_uint16_le(uint8_t *bytes, int len, uint16_t *res, int *taken) {
    int taken_len = 2;
    uint8_t *ptr2res;
    int i = 0;
    if (bytes == NULL || res == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < taken_len) {
        return HIF_ERR_LEN;
    }
    if (is_le()) {
        *res = *((uint16_t *) bytes);
    } else {
        ptr2res = (uint8_t *) res;
        for (i = 0; i < taken_len; i++) {
            ptr2res[i] = bytes[taken_len-1-i];
        }
    }
    if (taken != NULL) {
        *taken = taken_len;
    }
    return 0;
} 

int serialize_uint16_le(uint16_t n, uint8_t *buffer, int len, int *occupied) {
    int occupied_len = 2;
    uint8_t *ptr2n;
    int i;
    if (buffer == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < occupied_len) {
        return HIF_ERR_LEN;
    }
    if (is_le()) {
        *((uint16_t *) buffer) = n;
    } else {
        ptr2n = (uint8_t *) &n;
        for (i = 0; i < occupied_len; i++) {
            buffer[i] = ptr2n[occupied_len-1-i];
        }
    }
    if (occupied != NULL) {
        *occupied = occupied_len;
    }
    return 0;
}

#ifdef uint32_t

int deserialize_uint32_be(uint8_t *bytes, int len, uint32_t *res, int *taken) {
    int taken_len = 4;
    uint8_t *ptr2res;
    int i = 0;
    if (bytes == NULL || res == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < taken_len) {
        return HIF_ERR_LEN;
    }
    if (is_be()) {
        *res = *((uint32_t *) bytes);
    } else {
        ptr2res = (uint8_t *) res;
        for (i = 0; i < taken_len; i++) {
            ptr2res[i] = bytes[taken_len-1-i];
        }
    }
    if (taken != NULL) {
        *taken = taken_len;
    }
    return 0;
} 

int serialize_uint32_be(uint32_t n, uint8_t *buffer, int len, int *occupied) {
    int occupied_len = 4;
    uint8_t *ptr2n;
    int i;
    if (buffer == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < occupied_len) {
        return HIF_ERR_LEN;
    }
    if (is_be()) {
        *((uint32_t *) buffer) = n;
    } else {
        ptr2n = (uint8_t *) &n;
        for (i = 0; i < occupied_len; i++) {
            buffer[i] = ptr2n[occupied_len-1-i];
        }
    }
    if (occupied != NULL) {
        *occupied = occupied_len;
    }
    return 0;
}

int deserialize_uint32_le(uint8_t *bytes, int len, uint32_t *res, int *taken) {
    int taken_len = 4;
    uint8_t *ptr2res;
    int i = 0;
    if (bytes == NULL || res == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < taken_len) {
        return HIF_ERR_LEN;
    }
    if (is_le()) {
        *res = *((uint32_t *) bytes);
    } else {
        ptr2res = (uint8_t *) res;
        for (i = 0; i < taken_len; i++) {
            ptr2res[i] = bytes[taken_len-1-i];
        }
    }
    if (occupied != NULL) {
        *taken = taken_len;
    }
    return 0;
} 

int serialize_uint32_le(uint32_t n, uint8_t *buffer, int len, int *occupied) {
    int occupied_len = 4;
    uint8_t *ptr2n;
    int i;
    if (buffer == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < occupied_len) {
        return HIF_ERR_LEN;
    }
    if (is_le()) {
        *((uint32_t *) buffer) = n;
    } else {
        ptr2n = (uint8_t *) &n;
        for (i = 0; i < occupied_len; i++) {
            buffer[i] = ptr2n[occupied_len-1-i];
        }
    }
    if (occupied != NULL) {
        *occupied = occupied_len;
    }
    return 0;
}

#endif

#ifdef uint64_t

int deserialize_uint64_be(uint8_t *bytes, int len, uint64_t *res, int *taken) {
    int taken_len = 8;
    uint8_t *ptr2res;
    int i = 0;
    if (bytes == NULL || res == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < taken_len) {
        return HIF_ERR_LEN;
    }
    if (is_be()) {
        *res = *((uint64_t *) bytes);
    } else {
        ptr2res = (uint8_t *) res;
        for (i = 0; i < taken_len; i++) {
            ptr2res[i] = bytes[taken_len-1-i];
        }
    }
    if (taken != NULL) {
        *taken = taken_len;
    }
    return 0;
} 

int serialize_uint64_be(uint64_t n, uint8_t *buffer, int len, int *occupied) {
    int occupied_len = 8;
    uint8_t *ptr2n;
    int i;
    if (buffer == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < occupied_len) {
        return HIF_ERR_LEN;
    }
    if (is_be()) {
        *((uint64_t *) buffer) = n;
    } else {
        ptr2n = (uint8_t *) &n;
        for (i = 0; i < occupied_len; i++) {
            buffer[i] = ptr2n[occupied_len-1-i];
        }
    }
    if (occupied != NULL) {
        *occupied = occupied_len;
    }
    return 0;
}

int deserialize_uint64_le(uint8_t *bytes, int len, uint64_t *res, int *taken) {
    int taken_len = 8;
    uint8_t *ptr2res;
    int i = 0;
    if (bytes == NULL || res == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < taken_len) {
        return HIF_ERR_LEN;
    }
    if (is_le()) {
        *res = *((uint64_t *) bytes);
    } else {
        ptr2res = (uint8_t *) res;
        for (i = 0; i < taken_len; i++) {
            ptr2res[i] = bytes[taken_len-1-i];
        }
    }
    if (occupied != NULL) {
        *taken = taken_len;
    }
    return 0;
} 

int serialize_uint64_le(uint64_t n, uint8_t *buffer, int len, int *occupied) {
    int occupied_len = 4;
    uint8_t *ptr2n;
    int i;
    if (buffer == NULL) {
        return HIF_ERR_NULL;
    }
    if (len < occupied_len) {
        return HIF_ERR_LEN;
    }
    if (is_le()) {
        *((uint64_t *) buffer) = n;
    } else {
        ptr2n = (uint8_t *) &n;
        for (i = 0; i < occupied_len; i++) {
            buffer[i] = ptr2n[occupied_len-1-i];
        }
    }
    if (occupied != NULL) {
        *occupied = occupied_len;
    }
    return 0;
}

#endif