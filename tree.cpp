#include "tree.h"
#include <iostream>

using namespace std;

TreeNode* createNode(int data)
{
    TreeNode* newNode = new TreeNode;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, int data)
{
    if (root == nullptr)
    {
        return createNode(data);
    }

    if (data < root->data) 
    {
        root->left = insertNode(root->left, data);
    } 
    else if (data > root->data) 
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

TreeNode* buildTreeFromUserInput()
{
    int data;
    TreeNode* root = nullptr;

    cout << "Digite os números separados por espaço (ou -1 para finalizar): ";
    while (cin >> data && data != -1) 
    {
        root = insertNode(root, data);
    }

    return root;
}

int getHeight(TreeNode* root) 
{
    if (root == nullptr)
    {
        return -1;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    int treeHeight = 1 + max(leftHeight, rightHeight);
    
    return treeHeight;
}

int getSize(TreeNode* root) 
{
    if (root == nullptr) 
    {
        return 0;
    }

    int size = 1;

    if (root->left != nullptr)
    {
        size += getSize(root->left);
    }

    if (root->right != nullptr)
    {
        size += getSize(root->right);
    }

    return size;
}

void insertElement(TreeNode*& root, int data) 
{
    if (root == nullptr) 
    {
        root = createNode(data);
    } 
    else if (data < root->data)
    {
        insertElement(root->left, data);
    } 
    else if (data > root->data)
    {
        insertElement(root->right, data);
    }
}

TreeNode* findMin(TreeNode* node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    
    return node;
}

TreeNode* removeNode(TreeNode* root, int data)
{
    if (root == nullptr) 
    {
        return nullptr;
    }
    else if (data < root->data)
    {
        root->left = removeNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = removeNode(root->right, data);
    } 
    else 
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        } 
        else if (root->left == nullptr) 
        {
            TreeNode* temp = root;
            root = root->right;
            delete temp;
        } 
        else if (root->right == nullptr)
        {
            TreeNode* temp = root;
            root = root->left;
            delete temp;
        } 
        else 
        {
            TreeNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = removeNode(root->right, temp->data);
        }
    }
    
    return root;
}
