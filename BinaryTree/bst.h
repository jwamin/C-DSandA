//
// Created by Joss Manger on 1/25/21.
//

#ifndef DSANDA_BST_H
#define DSANDA_BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode{
    void* value;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

struct BinaryTreeNode* initWithSize(size_t size);

int comparison(struct BinaryTreeNode* compareNode,struct BinaryTreeNode* currentNode);

void addValueNode(struct BinaryTreeNode *treeRoot,void* value);

void treeDemo();

#endif //DSANDA_BST_H
