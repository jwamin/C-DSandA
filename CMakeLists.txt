cmake_minimum_required(VERSION 3.17)
project(DSandA C)

set(CMAKE_C_STANDARD 99)

add_executable(DSandA main.c LinkedLists/sll.h LinkedLists/sll.c BinaryTree/bst.h BinaryTree/bst.c Arrays/MultiDimensionalArrays.c Arrays/MultiDimensionalArrays.h Arrays/arrays.c Arrays/arrays.h K&R/k&rmain.c K&R/k&rmain.h Arrays/binSearch.c Arrays/binSearch.h)