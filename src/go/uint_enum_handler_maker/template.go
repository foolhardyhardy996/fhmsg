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
int validate_{{.EnumCommonName}}({{$UintEnumStruct}} in_enum);
int deserialize_{{.EnumCommonName}}(uint8_t *bytes, int len, {{$UintEnumStruct}} *out_enum, int *taken);
int serialize_{{.EnumCommonName}}({{$UintEnumStruct}} in_enum, uint8_t *buffer, int len, int *occupied);
`

var uint_enum_validate_definition_tmpl = `{{$UintEnumStruct := printf "struct %s" .EnumCommonName}}
{{$EnumCommonName := .EnumCommonName}}
int validate_{{.EnumCommonName}}({{$UintEnumStruct}} in_enum) {
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
	if (bytes == NULL || out_enum == NULL) {
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
	if (validate_{{.EnumCommonName}}(*out_enum) == 0) {
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
	if (validate_{{.EnumCommonName}}(in_enum) == 0) {
		return {{.EnumCommonName}}_ERR_INVALID;
	}
	ret = serialize_uint{{.UintBitSize}}_{{.EndiannessMarker}}(in_enum.val, buffer, len, occupied);
	if (ret != 0) {
		printf("[ERROR]: serialize_uint{{.UintBitSize}}_{{.EndiannessMarker}}() return 0x%08x\n", ret);
		return {{.EnumCommonName}}_ERR_DEP;
	}
	return 0;
}
`

var uint_enum_test_func_declaration_tmpl = `
void test_{{.EnumCommonName}}();
`

var uint_enum_test_func_definition_tmpl = `
{{$EnumCommonName := .EnumCommonName -}}
{{$UintEnumStruct := printf "struct %s" .EnumCommonName -}}
{{$SerializeFunc := printf "serialize_%s" .EnumCommonName -}}
{{$DeserializeFunc := printf "deserialize_%s" .EnumCommonName -}}
void test_{{.EnumCommonName}}() {
	int ret = 0;
	int taken = 0, occupied = 0;
	{{$UintEnumStruct}} uev_in, uev_out;
	uint8_t *uev_buffer = malloc(sizeof({{$UintEnumStruct}}));
	int buffer_len = sizeof({{$UintEnumStruct}});

	{{range .ValueRange -}}
	uev_in.val = {{$EnumCommonName}}_VAL_{{.ValueCommonName}};
	ret = {{$SerializeFunc}}(uev_in, uev_buffer, buffer_len, &occupied);
	if (ret != 0) {
		printf("[ERROR]: {{$SerializeFunc}}() fails with correct arguments.\n");
		goto free_mem;
	} else {
		printf("[INFO]: {{$SerializeFunc}}() succeeds with correct arguments.\n");
	}
	ret = {{$DeserializeFunc}}(uev_buffer, buffer_len, &uev_out, &taken);
	if (ret != 0) {
		printf("[ERROR]: {{$DeserializeFunc}}() fails with correct arguments.\n");
		goto free_mem;
	} else {
		printf("[INFO]: {{$DeserializeFunc}}() succeeds with correct arguments.\n");
	}
	if (uev_in.val != uev_out.val) {
		printf("[ERROR]: {{$SerializeFunc}}() and {{$DeserializeFunc}} are inconsistent.\n");
		goto free_mem;
	} else {
		printf("[INFO]: {{$SerializeFunc}}() and {{$DeserializeFunc}} are consistent.\n");
	}

	{{end -}}

free_mem:
	free(uev_buffer);
}

int main(int argc, char *argv[]) {
	test_{{.EnumCommonName}}();
	printf("[INFO]: all tests pass.\n");
	return 0;
}
`