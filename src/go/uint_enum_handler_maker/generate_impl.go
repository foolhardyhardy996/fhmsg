package uint_enum_handler_maker

import (
	"text/template"
	"os"
	"log"
	"fmt"
)

func GenImpl(descriptor *UintEnumDescriptor) {
	file, err := os.Create(fmt.Sprintf("%s.c", descriptor.EnumCommonName))
	if (err != nil) {
		log.Fatalf("[ERROR]: GenImpl: %v", err)
	}
	templateStrs := []string{
		fmt.Sprintf("#include \"%s.h\"\n#include \"%s_err.h\"\n", descriptor.EnumCommonName, descriptor.EnumCommonName),
		uint_enum_validate_definition_tmpl, 
		uint_enum_deserialize_definition_tmpl,
		uint_enum_serialize_definition_tmpl}
	for i, tmplStr := range templateStrs {
		tmpl, err := template.New(fmt.Sprintf("func_part_%d", i)).Parse(tmplStr)
		if (err != nil) {
			log.Fatalf("[ERROR]: GenImpl: %v", err)
		}
		err = tmpl.Execute(file, descriptor)
		if (err != nil) {
			log.Fatalf("[ERROR]: GenImpl: %v", err)
		}
	}
}