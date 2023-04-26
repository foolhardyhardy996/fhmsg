`fh_msg`: A Low-code Framework For Structured Message Construction/Parsing
=====

## Overview 
This project provides a framework for automatically generating construction/parsing function in C for structured message format. The initial intention is to facilitate the testing of PCIe card by providing a effortless mechanism for the communication between the host and the card.

## Features

- Support formal message format specification using JSON
- Support custom enumeration types
- Generate code in plain C

## Concepts
For the ease of design and using, we define the following terms:

- **Structured Message Format**: a definite collection of message field.
- **Structured Message Block**: 
- **Primitive Field**:
- **uint**: 
- **bytes**: 
- **reserved**: 
- **uint_enum**:
- **bytes_enum**: 
- **flags**: 

## Definition
```
{
    "type": "uint",
    "name": "foo",
    "bit_size": 8,
    "endianness": "big",
}

{
    "type": "bytes",
    "name": "bar",
    "length": 13,
}

{
    "type": "reserved", 
    "name": "baz",
    "length": 2,
}

{
    "type": "dynamic",
    "file": "fuu.py"
    "func": "func_name",
}

{
    "type": "block"
    "name": "stupid_block",
    "fields": [
        "name", 
        {
            ???
        }, 
        {

        }
    ], 

}
```

## Interfaces
For certain structured message format and certain message field type, there are four interfaces provided:
- enc_binary
- dec_binary
- enc_text
- dec_text

## Acknowledgements

- Li Weida, initiater