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

char* boolToString(bool boolean);

void printValueOfNode(struct BinaryTreeNode *node, const int* level){

    //assuming int for now
    int* intValue;
    int currentLevel = level ? *level : -1;
    char *isLeaf = boolToString(nodeIsLeaf(node));

    intValue = node->value;
    printf("value of treeNode %d, at level %d isLeaf: %s\n",*intValue, currentLevel, isLeaf);
}

void traverseInOrder(struct BinaryTreeNode *treeRoot, const int* currentLevel){

    int safetyInt = 0;
    int* intptr = malloc(sizeof(int));

    if (currentLevel == NULL){
        *intptr = safetyInt;
    } else {
        *intptr = *currentLevel + 1;
    }

    if (treeRoot->left){
        traverseInOrder(treeRoot->left, intptr);
    }

    printValueOfNode(treeRoot,intptr);

    if (treeRoot->right){
        traverseInOrder(treeRoot->right, intptr);
    }
}

bool nodeIsLeaf(struct BinaryTreeNode *node){
    bool isLeaf = false;
    if (!node->left && !node->right){
        isLeaf = true;
    }
    return isLeaf;
}

char* boolToString(bool boolean){
    return boolean ? "true" : "false";
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

    traverseInOrder(node, NULL);
}

//not current implemented
void addValueForNode(struct BinaryTreeNode *treeRoot, void* value){

}

int compareTreeNodes(struct BinaryTreeNode* compareNode, struct BinaryTreeNode* currentNode) {
    // compare... pointers?
}