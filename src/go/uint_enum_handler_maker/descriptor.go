package uint_enum_handler_maker

import (
	"log"
	"os"
	"encoding/json"
	"unicode"
	"strconv"
)

type UintEnumValueDescriptor struct {
	ValueCommonName string 
	Value uint64	
}

type UintEnumDescriptor struct {
	EnumCommonName string
	UintBitSize int
	UintByteSize int
	BigEndian bool
	EndiannessMarker string
	ErrCodeBase uint32
	ValueRange []UintEnumValueDescriptor
}

func validateCommonName(cn string) bool {
	for _, r := range cn {
		if unicode.IsSpace(r) {
			return false
		}
	}
	return true 
}

func CreateUintEnumDescriptor(
	commonName string, 
	uintBitSize int, 
	bigEndian bool, 
	errCodeBase uint32, 
	valRange []UintEnumValueDescriptor) *UintEnumDescriptor {
	var descriptor UintEnumDescriptor
	if (!validateCommonName(commonName)) {
		log.Fatalf("[ERROR]: CreateUintEnumDescriptor: illegal enum common name '%s'", commonName)
	}
	descriptor.EnumCommonName = commonName
	if (uintBitSize != 8 && uintBitSize != 16 && uintBitSize != 32 && uintBitSize != 64) {
		log.Fatalf("[ERROR]: CreateUintEnumDescriptor: UintBitSize = %d", uintBitSize);
	}
	descriptor.UintBitSize = uintBitSize
	descriptor.UintByteSize = uintBitSize / 8
	descriptor.BigEndian = bigEndian
	if (bigEndian) {
		descriptor.EndiannessMarker = "be"
	} else {
		descriptor.EndiannessMarker = "le"
	}
	descriptor.ErrCodeBase = errCodeBase
	for _, v := range valRange {
		if (!validateCommonName(v.ValueCommonName)) {
			log.Fatalf("[ERROR]: CreateUintEnumDescriptor: illegal value common name '%s'", v.ValueCommonName)
		}
	}
	descriptor.ValueRange = make([]UintEnumValueDescriptor, len(valRange))
	copy(descriptor.ValueRange, valRange)
	return &descriptor
}

func CreateUintEnumValueRange(
	cnList []string, 
	vList []uint64) []UintEnumValueDescriptor {
	if (len(cnList) != len(vList)) {
		log.Fatalf("[ERROR]: CreateUintEnumValueRange: len(cnList) != len(vList")
	}
	valueRange := make([]UintEnumValueDescriptor, len(cnList))
	for i, _ := range valueRange {
		valueRange[i].ValueCommonName = cnList[i];
		valueRange[i].Value = vList[i];
	}
	return valueRange
}

func CreateUintEnumDescriptorFromJSON(jsonFilePath string) *UintEnumDescriptor {
	jsonBytes, err := os.ReadFile(jsonFilePath)
	if (err != nil) {
		log.Fatalf("[ERROR]: CreateUintEnumDescriptorFromJSON: %v", err)
	}
	var descriptor UintEnumDescriptor
	var jsonMap map[string]interface{}
	err = json.Unmarshal(jsonBytes, &jsonMap)
	if (err != nil) {
		log.Fatalf("[ERROR]: CreateUintEnumDescriptorFromJSON: %v", err)
	}
	requiredFields := []string{
		"EnumCommonName", "UintBitSize", 
		"BigEndian", "ErrCodeBase",
		"ValueRange"}
	for _, field := range requiredFields {
		if _, ok := jsonMap[field]; !ok {
			log.Fatalf("[ERROR]: CreateUintEnumDescriptorFromJSON: '%s' is required", field)
		}
	}
	descriptor.EnumCommonName = jsonMap["EnumCommonName"].(string)
	if (!validateCommonName(descriptor.EnumCommonName)) {
		log.Fatalf("[ERROR]: CreateUintEnumDescriptorFromJSON: illegal enum common name '%s'", descriptor.EnumCommonName)
	}
	descriptor.UintBitSize = int(jsonMap["UintBitSize"].(float64))
	if (descriptor.UintBitSize != 8 && descriptor.UintBitSize != 16 && descriptor.UintBitSize != 32 && descriptor.UintBitSize != 64) {
		log.Fatalf("[ERROR]: CreateUintEnumDescriptorFromJSON: UintBitSize = %d", descriptor.UintBitSize);
	}
	descriptor.UintByteSize = descriptor.UintBitSize / 8
	descriptor.BigEndian = jsonMap["BigEndian"].(bool)
	if (descriptor.BigEndian) {
		descriptor.EndiannessMarker = "be"
	} else {
		descriptor.EndiannessMarker = "le"
	}
	switch v := jsonMap["ErrCodeBase"].(type) {
	case float64:
		descriptor.ErrCodeBase = uint32(v)
	case string:
		converted, err := strconv.ParseUint(v, 0, 32)
		if err != nil {
			log.Fatalf("[ERROR]: CreateUintEnumDescriptorFromJSON: fail to parse 'ErrCodeBase': %v", err)
		}
		descriptor.ErrCodeBase = uint32(converted)
	default:
		log.Fatalf("[ERROR]: CreateUintEnumDescriptorFromJSON: can't recognize 'ErrCodeBase'")
	}
	descriptor.ValueRange = make([]UintEnumValueDescriptor, len(jsonMap["ValueRange"].([]interface{})))
	for i, vHolder := range jsonMap["ValueRange"].([]interface{}) {
		v := vHolder.(map[string]interface{})
		switch val := v["Value"].(type) {
		case float64:
			descriptor.ValueRange[i].Value = uint64(val)
		case string:
			converted, err := strconv.ParseUint(val, 0, descriptor.UintBitSize)
			if err != nil {
				log.Fatalf("[ERROR]: CreateUintEnumDescriptorFromJSON: fail to parse 'Value': %v", err)
			}
			descriptor.ValueRange[i].Value = converted
		default:
			log.Fatalf("[ERROR]: CreateUintEnumDescriptorFromJSON: can't recognize 'Value'")
		}
		descriptor.ValueRange[i].ValueCommonName = v["ValueCommonName"].(string)
		if (!validateCommonName(descriptor.ValueRange[i].ValueCommonName)) {
			log.Fatalf("[ERROR]: CreateUintEnumDescriptorFromJSON: illegal value common name '%s'", descriptor.ValueRange[i].ValueCommonName)
		}
	}
	return &descriptor
}

