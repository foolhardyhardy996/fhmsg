package uint_enum_handler_maker

func GenCode(descriptor *UintEnumDescriptor) {
	GenHeader(descriptor)
	GenImpl(descriptor)
	GenTest(descriptor)
}
