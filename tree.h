#ifndef TREE_H
#define TREE_H

#include <string>

struct TreeNode
{
    int iData;
    TreeNode* ptrLeft;
    TreeNode* ptrRight;
};

TreeNode* createNode(int iData);
TreeNode* insertNode(TreeNode* ptrRoot, int iData);
TreeNode* buildTreeFromFile(const std::string& filename);
TreeNode* buildTreeFromUserInput();
int getHeight(TreeNode* ptrRoot);
int getSize(TreeNode* ptrRoot);
void insertElement(TreeNode*& ptrRoot, int iData);
void printInOrder(TreeNode* ptrRoot);
TreeNode* findMin(TreeNode* ptrNode);
TreeNode* removeNode(TreeNode* ptrRoot, int iData);
void deleteTree(TreeNode*& ptrRoot);
bool perfectTree(TreeNode* ptrRoot, int iHeight, int iLevel);
bool completeTree(TreeNode* ptrRoot, int iIndex, int iSize);
TreeNode* findAddress(TreeNode*& ptrRoot, int iData);
void printTree(TreeNode* ptrRoot);

#endif
