cmake_minimum_required(VERSION 3.7)

project(AESImplPrj)

add_library(AESImpl STATIC ./lib/aes.c ./lib/key_expansion.c)
target_include_directories(AESImpl INTERFACE include)

add_executable(test01 ./test/test01.c)
target_link_libraries(test01 PRIVATE AESImpl)

add_executable(rcon ./tool/round_constant.c)
