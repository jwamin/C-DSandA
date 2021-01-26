//
// Created by Joss Manger on 1/25/21.
//

#include "bst.h"

struct BinaryTreeNode* initWithSize(size_t size){
    BinaryTreeNode* newNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    newNode->value = malloc(size);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addValueNode(struct BinaryTreeNode *treeRoot,void* value){

}

void printValueOfNode(struct BinaryTreeNode *node, int* level){
    //assuming int for now
    int* intValue;
    intValue = node->value;
    int currentLevel = level ? *level : -1;
    printf("value of treeNode %d, at level %d\n",*intValue, currentLevel);
}

void inOrderPrint(struct BinaryTreeNode *treeRoot, int* currentLevel){

    int safetyInt = 0;
    int* intptr = malloc(sizeof(int));

    if (currentLevel == NULL){
        *intptr = safetyInt;
    } else {
        *intptr = *currentLevel + 1;
    }

    if (treeRoot->left){
        inOrderPrint(treeRoot->left,intptr);
    }

    printValueOfNode(treeRoot,intptr);

    if (treeRoot->right){
        inOrderPrint(treeRoot->right,intptr);
    }
}

void treeDemo(){
    int* loaderInt;
    BinaryTreeNode *node = initWithSize(sizeof(int));
    loaderInt = node->value;
    *loaderInt = 50;

    BinaryTreeNode *left = initWithSize(sizeof(int));
    loaderInt = left->value;
    *loaderInt = 20;
    node->left = left;

    BinaryTreeNode *right = initWithSize(sizeof(int));
    loaderInt = right->value;
    *loaderInt = 100;
    node->right = right;

    BinaryTreeNode *rightleft = initWithSize(sizeof(int));
    loaderInt = rightleft->value;
    *loaderInt = 70;
    right->right = rightleft;

    BinaryTreeNode *rightleftleft = initWithSize(sizeof(int));
    loaderInt = rightleftleft->value;
    *loaderInt = 55;
    rightleft->left = rightleftleft;

    inOrderPrint(node,NULL);

}