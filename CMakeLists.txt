cmake_minimum_required(VERSION 3.20)

project(dynamic-programming)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main)
target_sources(main PRIVATE src/main.c
                            src/binomial.c
                            src/trinomial.c)

