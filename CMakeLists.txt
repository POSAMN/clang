cmake_minimum_required(VERSION 3.14)
project(clang C)

set(CMAKE_C_STANDARD 11)

include_directories(l5)

add_executable(clang
        l1/2d_arrays-example.c
        l1/2d_arrays.c
        l1/dyn_mem.c
        l1/pass_argument_by_pointer.c
        l1/structs.c
        l2/passing_arguments.c
        l2/scanf.c
        l2/some_logic.c
        l2/some_struct.c
        l2/some_struct.h
        l3/basicIO.c
        l3/basicIO2.c
        l4/err.c
        l4/triangle.c
        l5/dynam_array.c
        l5/dynam_array.h
        l5/dynam_array_test.c
        complex_num.c
        double_array.c
        prog.c)
