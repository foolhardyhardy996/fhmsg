cmake_minimum_required(VERSION 3.5)
project(fhmsg_uint_codec)

add_executable(uint_codec_binary_test uint_codec_binary_test.c uint_codec_binary.c)
add_executable(uint_codec_text_test uint_codec_text_test.c uint_codec_text.c)

target_include_directories(uint_codec_binary_test PRIVATE "..")
target_include_directories(uint_codec_text_test PRIVATE "..")