#ifndef TREE_H
#define TREE_H

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int data);
TreeNode* insertNode(TreeNode* root, int data);
TreeNode* buildTreeFromUserInput();
int getHeight(TreeNode* root);
int getSize(TreeNode* root);
void insertElement(TreeNode*& root, int data);
TreeNode* findMin(TreeNode* node);
TreeNode* removeNode(TreeNode* root, int data);
void deleteTree(TreeNode*& root);

#endif
