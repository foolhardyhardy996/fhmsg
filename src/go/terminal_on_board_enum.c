#include <terminal_on_board_enum.h>
#include <terminal_on_board_enum_err.h>


int validate_terminal_on_board_enum_value(struct terminal_on_board_enum in_enum) {
	int match = 0;
	
	if (terminal_on_board_enum_VAL_fpga == in_enum.val) {
		match = 1;
		goto return_result;
	}
	
	if (terminal_on_board_enum_VAL_asic == in_enum.val) {
		match = 1;
		goto return_result;
	}
	
	if (terminal_on_board_enum_VAL_core1 == in_enum.val) {
		match = 1;
		goto return_result;
	}
	
	if (terminal_on_board_enum_VAL_core2 == in_enum.val) {
		match = 1;
		goto return_result;
	}
	
return_result:
	return match;
}

int deserialize_terminal_on_board_enum(uint8_t *bytes, int len, struct terminal_on_board_enum *out_enum, int *taken) {
	int ret;
	int taken_len = 1;
	if (bytes == NULL || res == NULL) {
		return terminal_on_board_enum_ERR_NULL;
	}
	if (len < taken_len) {
		return terminal_on_board_enum_ERR_LEN;
	}
	ret = deserialize_uint8_be(bytes, len, &(out_enum->val), taken);
	if (ret != 0) {
		printf("[ERROR]: deserialize_uint8_be() return 0x%08x\n", ret);
		return terminal_on_board_enum_ERR_DEP;
	}
	if (validate_terminal_on_board_enum_value(out_enum->val) == 0) {
		return terminal_on_board_enum_ERR_INVALID;
	}
	return 0;
}

int serialize_terminal_on_board_enum(struct terminal_on_board_enum in_enum, uint8_t *buffer, int len, int *occupied) {
	int ret;
	int occupied_len = 1;
	if (buffer == NULL) {
		return terminal_on_board_enum_ERR_NULL;
	}
	if (len < occupied_len) {
		return terminal_on_board_enum_ERR_LEN;
	}
	if (validate_terminal_on_board_enum_value(in_enum.val) == 0) {
		return terminal_on_board_enum_ERR_INVALID;
	}
	ret = serialize_uint8_be(in_enum, buffer, len, occupied);
	if (ret != 0) {
		printf("[ERROR]: serialize_uint8_be() return 0x%08x\n", ret);
		return terminal_on_board_enum_ERR_DEP;
	}
	return 0;
}
