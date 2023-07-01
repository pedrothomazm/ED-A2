#ifndef TREE_H
#define TREE_H

#include <string>

struct TreeNode
{
    int idata;
    TreeNode* ptrLeft;
    TreeNode* ptrRight;
};

TreeNode* createNode(int idata);
TreeNode* insertNode(TreeNode* ptrRoot, int idata);
TreeNode* buildTreeFromFile(const std::string& filename);
TreeNode* buildTreeFromUserInput();
int getHeight(TreeNode* ptrRoot);
int getSize(TreeNode* ptrRoot);
void insertElement(TreeNode*& ptrRoot, int idata);
void printInOrder(TreeNode* ptrRoot);
TreeNode* findMin(TreeNode* ptrNode);
TreeNode* removeNode(TreeNode* ptrRoot, int idata);
void deleteTree(TreeNode*& ptrRoot);

#endif