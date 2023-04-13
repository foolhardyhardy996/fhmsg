package main

import (
	maker "fh_msg/uint_enum_handler_maker" 
	"flag"
	"log"
)

func main() {
	configFilePathFlag := flag.String("f", "", "path to the config JSON file")
	flag.Parse()
	if (configFilePathFlag == nil) {
		log.Fatalf("[ERROR]: gen_uint_enum: '-f' is required")
	}
	descriptor := maker.CreateUintEnumDescriptorFromJSON(*configFilePathFlag)
	maker.GenCode(descriptor)
}
