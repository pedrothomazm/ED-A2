#ifndef SORT_H
#define SORT_H

#include "tree.h"

TreeNode* findMinAndRemove(TreeNode*& ptrRoot);
void insertNodeToList(TreeNode*& ptrList, TreeNode* ptrNode);
void swapNodeValues(TreeNode* node1, TreeNode* node2);
void treeToList(TreeNode* ptrNode, TreeNode*& ptrList);
void bubbleSort(TreeNode*& ptrRoot);
void selectionSort(TreeNode*& ptrRoot);
void insertionSort(TreeNode*& ptrRoot);

#endif