#pragma once


#define terminal_on_board_enum_VAL_fpga (0x00000001)

#define terminal_on_board_enum_VAL_asic (0x00000002)

#define terminal_on_board_enum_VAL_core1 (0x00000003)

#define terminal_on_board_enum_VAL_core2 (0x00000004)
struct terminal_on_board_enum {
	uint8_t val;
};
int validate_terminal_on_board_enum_value(struct terminal_on_board_enum in_enum);
int deserialize_terminal_on_board_enum(uint8_t *bytes, int len, struct terminal_on_board_enum *out_enum, int *taken);
int serialize_terminal_on_board_enum(struct terminal_on_board_enum in_enum, uint8_t *buffer, int len, int *occupied);
