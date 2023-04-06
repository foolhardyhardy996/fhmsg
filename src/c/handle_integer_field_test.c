#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "handle_integer_field.h"

static void print_bytes_one_line(uint8_t *bytes, int len);
static void test_endian();
static void test_u8_case();
static void test_u16_case();

void print_bytes_one_line(uint8_t *bytes, int len) {
    int i = 0;
    for (i = 0; i < len; i++) {
        printf("%2X ", bytes[i]);
    }
    printf("\n");
}

void test_endian() {
    int zero_one_holder;
    
    zero_one_holder = is_be();
    if (zero_one_holder != 0 && zero_one_holder != 1) {
        printf("[ERROR]: is_be() return illegal value %d.\n", zero_one_holder);
        exit(0);
    } else {
        printf("[INFO]: is_be() return valid value.\n");
    }

    zero_one_holder = is_le();
    if (zero_one_holder != 0 && zero_one_holder != 1) {
        printf("[ERROR]: is_le() return illegal value %d.\n", zero_one_holder);
        exit(0);
    } else {
        printf("[INFO]: is_le() return valid value.\n");
    }

    if (is_be() == is_le()) {
        printf("[ERROR]: is_be() and is_le() return inconsistent result.\n");
        exit(0);
    } else {
        printf("[INFO]: is_be() and is_le() return consistent result.\n");
    }

    if (is_be() == 1) {
        printf("[INFO]: endianness - big endian machine\n");
    } else {
        printf("[INFO]: endianness - little endian machine\n");
    }
}

void test_u8_case() {
    int ret = 0;
    int taken = 0, occupied = 0;
    uint8_t u8v = 0xff;
    uint8_t u8v_buffer[1] = {0};

    ret = serialize_uint8_be(u8v, u8v_buffer, 1, &occupied);
    if (ret != 0) {
        printf("[ERROR]: serialize_uint8_be() fail with correct arguments.\n");
        exit(0);
    } else {
        printf("[INFO]: serialize_uint8_be() proceed with correct arguments.\n");
    }
    if (occupied != 1) {
        printf("[ERROR]: serialize_uint8_be() return 'occupied' = %d.\n", occupied);
        exit(0);
    } else {
        printf("[INFO]: serialize_uint8_be() return correct 'occupied'.\n");
    }
    printf("[NOTICE]: u8v_buffer: ");
    print_bytes_one_line(u8v_buffer, 1);

    ret = serialize_uint8_be(u8v, NULL, 0, &occupied);
    if (ret != HIF_ERR_NULL) {
        printf("[ERROR]: serialize_uint8_be() return wrong error code when 'u8v_buffer' is NULL.\n");
        exit(0);
    } else {
        printf("[INFO]: serialize_uint8_be() return correct error code when 'u8v_buffer' is NULL.\n");
    }

    u8v = 0;
    ret = deserialize_uint8_be(u8v_buffer, 1, &u8v, &taken); 
    if (ret != 0) {
        printf("[ERROR]: deserialize_uint8_be() fail with correct arguments.\n");
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint8_be() proceed with correct arguments.\n");
    }
    if (u8v != 0xff) {
        printf("[ERROR]: deserialize_uint8_be() return 'u8v' = %d.\n", u8v);
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint8_be() return correct 'u8v'.\n");
    }
    if (taken != 1) {
        printf("[ERROR]: deserialize_uint8_be() return 'taken' = %d.\n", taken);
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint8_be() return correct 'taken'.\n");
    }

    ret = deserialize_uint8_be(NULL, 0, &u8v, &taken);
    if (ret != HIF_ERR_NULL) {
        printf("[ERROR]: deserialize_uint8_be() return wrong error code when 'u8v_buffer' is NULL.\n");
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint8_be() return correct error code when 'u8v_buffer' is NULL.\n");
    }
    
    ret = deserialize_uint8_be(u8v_buffer, 1, NULL, &taken);
    if (ret != HIF_ERR_NULL) {
        printf("[ERROR]: deserialize_uint8_be() return wrong error code when '&u8v' is NULL.\n");
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint8_be() return correct error code when '&u8v' is NULL.\n");
    }

    ret = serialize_uint8_le(u8v, u8v_buffer, 1, &occupied);
    if (ret != 0) {
        printf("[ERROR]: serialize_uint8_le() fail with correct arguments.\n");
        exit(0);
    } else {
        printf("[INFO]: serialize_uint8_le() proceed with correct arguments.\n");
    }
    if (occupied != 1) {
        printf("[ERROR]: serialize_uint8_le() return 'occupied' = %d.\n", occupied);
        exit(0);
    } else {
        printf("[INFO]: serialize_uint8_le() return correct 'occupied'.\n");
    }
    printf("[NOTICE]: u8v_buffer: ");
    print_bytes_one_line(u8v_buffer, 1);

    ret = serialize_uint8_le(u8v, NULL, 0, &occupied);
    if (ret != HIF_ERR_NULL) {
        printf("[ERROR]: serialize_uint8_le() return wrong error code when 'u8v_buffer' is NULL.\n");
        exit(0);
    } else {
        printf("[INFO]: serialize_uint8_le() return correct error code when 'u8v_buffer' is NULL.\n");
    }

    u8v = 0;
    ret = deserialize_uint8_le(u8v_buffer, 1, &u8v, &taken); 
    if (ret != 0) {
        printf("[ERROR]: deserialize_uint8_le() fail with correct arguments.\n");
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint8_le() proceed with correct arguments.\n");
    }
    if (u8v != 0xff) {
        printf("[ERROR]: deserialize_uint8_le() return 'u8v' = %d.\n", u8v);
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint8_le() return correct 'u8v'.\n");
    }
    if (taken != 1) {
        printf("[ERROR]: deserialize_uint8_le() return 'taken' = %d.\n", taken);
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint8_le() return correct 'taken'.\n");
    }

    ret = deserialize_uint8_le(NULL, 0, &u8v, &taken);
    if (ret != HIF_ERR_NULL) {
        printf("[ERROR]: deserialize_uint8_le() return wrong error code when 'u8v_buffer' is NULL.\n");
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint8_le() return correct error code when 'u8v_buffer' is NULL.\n");
    }
    
    ret = deserialize_uint8_le(u8v_buffer, 1, NULL, &taken);
    if (ret != HIF_ERR_NULL) {
        printf("[ERROR]: deserialize_uint8_le() return wrong error code when '&u8v' is NULL.\n");
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint8_le() return correct error code when '&u8v' is NULL.\n");
    }
}

void test_u16_case() {
    int ret = 0;
    int taken = 0, occupied = 0;
    uint16_t u16v = 0xff00;
    uint8_t u16v_buffer[2] = {0};

    ret = serialize_uint16_be(u16v, u16v_buffer, 2, &occupied);
    if (ret != 0) {
        printf("[ERROR]: serialize_uint16_be() fail with correct arguments.\n");
        exit(0);
    } else {
        printf("[INFO]: serialize_uint16_be() proceed with correct arguments.\n");
    }
    if (occupied != 2) {
        printf("[ERROR]: serialize_uint16_be() return 'occupied' = %d.\n", occupied);
        exit(0);
    } else {
        printf("[INFO]: serialize_uint16_be() return correct 'occupied'.\n");
    }
    printf("[NOTICE]: u16v_buffer: ");
    print_bytes_one_line(u16v_buffer, 2);

    ret = serialize_uint16_be(u16v, NULL, 0, &occupied);
    if (ret != HIF_ERR_NULL) {
        printf("[ERROR]: serialize_uint16_be() return wrong error code when 'u16v_buffer' is NULL.\n");
        exit(0);
    } else {
        printf("[INFO]: serialize_uint16_be() return correct error code when 'u16v_buffer' is NULL.\n");
    }

    u16v = 0;
    ret = deserialize_uint16_be(u16v_buffer, 2, &u16v, &taken); 
    if (ret != 0) {
        printf("[ERROR]: deserialize_uint16_be() fail with correct arguments.\n");
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint16_be() proceed with correct arguments.\n");
    }
    if (u16v != 0xff00) {
        printf("[ERROR]: deserialize_uint16_be() return 'u16v' = %d.\n", u16v);
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint16_be() return correct 'u16v'.\n");
    }
    if (taken != 2) {
        printf("[ERROR]: deserialize_uint16_be() return 'taken' = %d.\n", taken);
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint16_be() return correct 'taken'.\n");
    }

    ret = deserialize_uint16_be(NULL, 0, &u16v, &taken);
    if (ret != HIF_ERR_NULL) {
        printf("[ERROR]: deserialize_uint16_be() return wrong error code when 'u16v_buffer' is NULL.\n");
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint16_be() return correct error code when 'u16v_buffer' is NULL.\n");
    }
    
    ret = deserialize_uint16_be(u16v_buffer, 2, NULL, &taken);
    if (ret != HIF_ERR_NULL) {
        printf("[ERROR]: deserialize_uint16_be() return wrong error code when '&u16v' is NULL.\n");
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint16_be() return correct error code when '&u16v' is NULL.\n");
    }

    ret = serialize_uint16_le(u16v, u16v_buffer, 2, &occupied);
    if (ret != 0) {
        printf("[ERROR]: serialize_uint16_le() fail with correct arguments.\n");
        exit(0);
    } else {
        printf("[INFO]: serialize_uint16_le() proceed with correct arguments.\n");
    }
    if (occupied != 2) {
        printf("[ERROR]: serialize_uint16_le() return 'occupied' = %d.\n", occupied);
        exit(0);
    } else {
        printf("[INFO]: serialize_uint16_le() return correct 'occupied'.\n");
    }
    printf("[NOTICE]: u16v_buffer: ");
    print_bytes_one_line(u16v_buffer, 2);

    ret = serialize_uint16_le(u16v, NULL, 0, &occupied);
    if (ret != HIF_ERR_NULL) {
        printf("[ERROR]: serialize_uint16_le() return wrong error code when 'u16v_buffer' is NULL.\n");
        exit(0);
    } else {
        printf("[INFO]: serialize_uint16_le() return correct error code when 'u16v_buffer' is NULL.\n");
    }

    u16v = 0;
    ret = deserialize_uint16_le(u16v_buffer, 2, &u16v, &taken); 
    if (ret != 0) {
        printf("[ERROR]: deserialize_uint16_le() fail with correct arguments.\n");
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint16_le() proceed with correct arguments.\n");
    }
    if (u16v != 0xff00) {
        printf("[ERROR]: deserialize_uint16_le() return 'u16v' = %d.\n", u16v);
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint16_le() return correct 'u16v'.\n");
    }
    if (taken != 2) {
        printf("[ERROR]: deserialize_uint16_le() return 'taken' = %d.\n", taken);
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint16_le() return correct 'taken'.\n");
    }

    ret = deserialize_uint16_le(NULL, 0, &u16v, &taken);
    if (ret != HIF_ERR_NULL) {
        printf("[ERROR]: deserialize_uint16_le() return wrong error code when 'u16v_buffer' is NULL.\n");
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint16_le() return correct error code when 'u16v_buffer' is NULL.\n");
    }
    
    ret = deserialize_uint16_le(u16v_buffer, 2, NULL, &taken);
    if (ret != HIF_ERR_NULL) {
        printf("[ERROR]: deserialize_uint16_le() return wrong error code when '&u16v' is NULL.\n");
        exit(0);
    } else {
        printf("[INFO]: deserialize_uint16_le() return correct error code when '&u16v' is NULL.\n");
    }
}

int main(int argc, char *argv[]) {
    test_endian();
    test_u8_case();
    test_u16_case();

    return 0;
}