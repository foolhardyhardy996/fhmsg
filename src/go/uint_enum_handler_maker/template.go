package uint_enum_handler_maker

var uint_enum_value_define_tmpl = `{{$EnumCommonName := .EnumCommonName}}
{{range .ValueRange}}
#define {{$EnumCommonName}}_VAL_{{.ValueCommonName}} ({{printf "0x%08X"  .Value}})
{{end}}`

var uint_enum_struct_declaration_tmpl = `struct {{.EnumCommonName}} {
	uint{{.UintBitSize}}_t val;
};`

var uint_enum_err_define_tmpl = `
{{$FmtStr := "0x%08X"}}
#define {{.EnumCommonName}}_ERR_BASE     ({{printf $FmtStr .ErrCodeBase}})
#define {{.EnumCommonName}}_ERR_NULL     ({{.EnumCommonName}}_ERR_BASE + {{printf $FmtStr 1}})
#define {{.EnumCommonName}}_ERR_LEN      ({{.EnumCommonName}}_ERR_BASE + {{printf $FmtStr 2}})
#define {{.EnumCommonName}}_ERR_DEP      ({{.EnumCommonName}}_ERR_BASE + {{printf $FmtStr 3}})
#define {{.EnumCommonName}}_ERR_INVALID  ({{.EnumCommonName}}_ERR_BASE + {{printf $FmtStr 4}})
`

var uint_enum_func_declaration_tmpl = `{{$UintEnumStruct := printf "struct %s" .EnumCommonName}}
int validate_{{.EnumCommonName}}_value({{$UintEnumStruct}} in_enum);
int deserialize_{{.EnumCommonName}}(uint8_t *bytes, int len, {{$UintEnumStruct}} *out_enum, int *taken);
int serialize_{{.EnumCommonName}}({{$UintEnumStruct}} in_enum, uint8_t *buffer, int len, int *occupied);
`

var uint_enum_validate_definition_tmpl = `{{$UintEnumStruct := printf "struct %s" .EnumCommonName}}
{{$EnumCommonName := .EnumCommonName}}
int validate_{{.EnumCommonName}}_value({{$UintEnumStruct}} in_enum) {
	int match = 0;
	{{range .ValueRange}}
	if ({{$EnumCommonName}}_VAL_{{.ValueCommonName}} == in_enum.val) {
		match = 1;
		goto return_result;
	}
	{{end}}
return_result:
	return match;
}
`

var uint_enum_deserialize_definition_tmpl = `{{$UintEnumStruct := printf "struct %s" .EnumCommonName}}
int deserialize_{{.EnumCommonName}}(uint8_t *bytes, int len, {{$UintEnumStruct}} *out_enum, int *taken) {
	int ret;
	int taken_len = {{.UintByteSize}};
	if (bytes == NULL || res == NULL) {
		return {{.EnumCommonName}}_ERR_NULL;
	}
	if (len < taken_len) {
		return {{.EnumCommonName}}_ERR_LEN;
	}
	ret = deserialize_uint{{.UintBitSize}}_{{.EndiannessMarker}}(bytes, len, &(out_enum->val), taken);
	if (ret != 0) {
		printf("[ERROR]: deserialize_uint{{.UintBitSize}}_{{.EndiannessMarker}}() return 0x%08x\n", ret);
		return {{.EnumCommonName}}_ERR_DEP;
	}
	if (validate_{{.EnumCommonName}}_value(out_enum->val) == 0) {
		return {{.EnumCommonName}}_ERR_INVALID;
	}
	return 0;
}
`

var uint_enum_serialize_definition_tmpl = `{{$UintEnumStruct := printf "struct %s" .EnumCommonName}}
int serialize_{{.EnumCommonName}}({{$UintEnumStruct}} in_enum, uint8_t *buffer, int len, int *occupied) {
	int ret;
	int occupied_len = {{.UintByteSize}};
	if (buffer == NULL) {
		return {{.EnumCommonName}}_ERR_NULL;
	}
	if (len < occupied_len) {
		return {{.EnumCommonName}}_ERR_LEN;
	}
	if (validate_{{.EnumCommonName}}_value(in_enum.val) == 0) {
		return {{.EnumCommonName}}_ERR_INVALID;
	}
	ret = serialize_uint{{.UintBitSize}}_{{.EndiannessMarker}}(in_enum, buffer, len, occupied);
	if (ret != 0) {
		printf("[ERROR]: serialize_uint{{.UintBitSize}}_{{.EndiannessMarker}}() return 0x%08x\n", ret);
		return {{.EnumCommonName}}_ERR_DEP;
	}
	return 0;
}
`