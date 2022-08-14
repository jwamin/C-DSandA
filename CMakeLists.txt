cmake_minimum_required(VERSION 3.17)
project(DSandA C)

set(CMAKE_C_STANDARD 99)

add_executable(DSandA main.c DataStructures/LinkedLists/sll.h DataStructures/LinkedLists/sll.c DataStructures/BinaryTree/bst.h DataStructures/BinaryTree/bst.c fPointer/fpointer.c fPointer/fpointer.h cake-thief/cake-thief.c cake-thief/cake-thief.h)