cmake_minimum_required(VERSION 3.5)
project(fhmsg_bytes_codec)

add_executable(bytes_codec_binary_test bytes_codec_binary_test.c bytes_codec_binary.c)

target_include_directories(bytes_codec_binary_test PRIVATE "..")