package uint_enum_handler_maker

import (
	"text/template"
	"os"
	"log"
	"fmt"
)

func GenTest(descriptor *UintEnumDescriptor) {
	headerFile, err := os.Create(fmt.Sprintf("%s_test.h", descriptor.EnumCommonName))
	if (err != nil) {
		log.Fatalf("[ERROR]: GenTest: %v", err)
	}
	templateStrs := []string{
		"#pragma once\n",
		fmt.Sprintf("#include \"%s.h\"\n", descriptor.EnumCommonName),
		"#include <stdlib.h>\n",
		"#include <stdio.h>\n",
		uint_enum_test_func_declaration_tmpl}
	for i, tmplStr := range templateStrs {
		tmpl, err := template.New(fmt.Sprintf("test_header_part_%d", i)).Parse(tmplStr)
		if (err != nil) {
			log.Fatalf("[ERROR]: GenTest: %v", err)
		}
		err = tmpl.Execute(headerFile, descriptor)
		if (err != nil) {
			log.Fatalf("[ERROR]: GenTest: %v", err)
		}
	}

	codeFile, err := os.Create(fmt.Sprintf("%s_test.c", descriptor.EnumCommonName))
	if (err != nil) {
		log.Fatalf("[ERROR]: GenTest: %v", err)
	}
	templateStrs = []string{
		fmt.Sprintf("#include \"%s_test.h\"\n", descriptor.EnumCommonName),
		uint_enum_test_func_definition_tmpl}
	for i, tmplStr := range templateStrs {
		tmpl, err := template.New(fmt.Sprintf("test_part_%d", i)).Parse(tmplStr)
		if (err != nil) {
			log.Fatalf("[ERROR]: GenTest: %v", err)
		}
		err = tmpl.Execute(codeFile, descriptor)
		if (err != nil) {
			log.Fatalf("[ERROR]: GenTest: %v", err)
		}
	}

}
