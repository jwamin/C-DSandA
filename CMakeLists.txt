cmake_minimum_required(VERSION 3.17)
project(DSandA C)

set(CMAKE_C_STANDARD 99)

add_executable(DSandA main.c LinkedLists/sll.h LinkedLists/sll.c BinaryTree/bst.h BinaryTree/bst.c)