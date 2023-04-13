package uint_enum_handler_maker

import (
	"text/template"
	"os"
	"log"
	"fmt"
)

func GenHeader(descriptor *UintEnumDescriptor) {
	genDeclHeader(descriptor)
	genErrHeader(descriptor)
}

func genDeclHeader(descriptor *UintEnumDescriptor) {
	file, err := os.Create(fmt.Sprintf("%s.h", descriptor.EnumCommonName))
	if (err != nil) {
		log.Fatalf("[ERROR]: GenHeader: %v", err)
	}
	templateStrs := []string{
		"#pragma once\n",
		"#include <stdint.h>\n#include <stdlib.h>\n#include <stdio.h>\n",
		"#include \"handle_integer_field.h\"\n",
		uint_enum_value_define_tmpl, 
		uint_enum_struct_declaration_tmpl,
		uint_enum_func_declaration_tmpl}
	for i, tmplStr := range templateStrs {
		tmpl, err := template.New(fmt.Sprintf("decl_header_part_%d", i)).Parse(tmplStr)
		if (err != nil) {
			log.Fatalf("[ERROR]: GenHeader: %v", err)
		}
		err = tmpl.Execute(file, descriptor)
		if (err != nil) {
			log.Fatalf("[ERROR]: GenHeader: %v", err)
		}
	}
}

func genErrHeader(descriptor *UintEnumDescriptor) {
	file, err := os.Create(fmt.Sprintf("%s_err.h", descriptor.EnumCommonName))
	if (err != nil) {
		log.Fatalf("[ERROR]: GenHeader: %v", err)
	}
	templateStrs := []string{
		"#pragma once\n",
		uint_enum_err_define_tmpl}
	for i, tmplStr := range templateStrs {
		tmpl, err := template.New(fmt.Sprintf("err_header_part_%d", i)).Parse(tmplStr)
		if (err != nil) {
			log.Fatalf("[ERROR]: GenHeader: %v", err)
		}
		err = tmpl.Execute(file, descriptor)
		if (err != nil) {
			log.Fatalf("[ERROR]: GenHeader: %v", err)
		}
	}
}