#include "tree.h"
#include <iostream>

using namespace std;

// Função para criar um novo nó da árvore
TreeNode* CreateNode(int pData)
{
    TreeNode* pNewNode = new TreeNode;
    pNewNode->data = pData;
    pNewNode->left = nullptr;
    pNewNode->right = nullptr;
    return pNewNode;
}

// Função para inserir um nó na árvore
TreeNode* InsertNode(TreeNode* pRoot, int pData)
{
    if (pRoot == nullptr)
    {
        return CreateNode(pData); // Se a árvore estiver vazia, cria um novo nó com o valor fornecido
    }
    
    if (pData < pRoot->data) 
    {
        pRoot->left = InsertNode(pRoot->left, pData); // Se o valor é menor que o valor do nó atual, insere na subárvore esquerda
    } 
    else if (pData > pRoot->data) 
    {
        pRoot->right = InsertNode(pRoot->right, pData); // Se o valor é maior que o valor do nó atual, insere na subárvore direita
    }

    return pRoot; // Retorna a raiz da árvore modificada
}

// Função para construir uma árvore a partir de entrada do usuário
TreeNode* BuildTreeFromUserInput()
{
    int data;
    TreeNode* pRoot = nullptr;

    cout << "Digite os números separados por espaço (ou -1 para finalizar): ";
    while (cin >> data && data != -1) 
    {
        pRoot = InsertNode(pRoot, data); // Insere cada número na árvore utilizando a função InsertNode
    }

    return pRoot; // Retorna a raiz da árvore construída
}

// Função para obter a altura da árvore
int GetHeight(TreeNode* pRoot) 
{
    if (pRoot == nullptr)
    {
        return 0; // Retorna 0 se a árvore estiver vazia (raiz nula)
    }

    int leftHeight = GetHeight(pRoot->left); // Obtém a altura da subárvore esquerda
    int rightHeight = GetHeight(pRoot->right); // Obtém a altura da subárvore direita
    
    int treeHeight = 1 + max(leftHeight, rightHeight); // A altura da árvore é o máximo entre as alturas das subárvores esquerda e direita, mais 1
    
    return treeHeight; // Retorna a altura da árvore
}

// Função para obter o tamanho da árvore (número de nós)
int GetSize(TreeNode* pRoot) 
{
    if (pRoot == nullptr) 
    {
        return 0; // Retorna 0 se a árvore estiver vazia
    }

    int size = 1; // Inicia o tamanho com 1 para contar o nó atual

    if (pRoot->left != nullptr)
    {
        size += GetSize(pRoot->left); // Chama recursivamente a função para obter o tamanho da subárvore esquerda e adiciona ao tamanho total
    }

    if (pRoot->right != nullptr)
    {
        size += GetSize(pRoot->right); // Chama recursivamente a função para obter o tamanho da subárvore direita e adiciona ao tamanho total
    }

    return size; // Retorna o tamanho total da árvore
}

// Função para inserir um elemento na árvore
void InsertElement(TreeNode*& pRoot, int data) 
{
    // Verifica de a raiz atual é nula 
    if (pRoot == nullptr) 
    {
        pRoot = CreateNode(data); // Cria um novo nó com o valor especificado e o torna a raiz da árvore
    } 
    else if (data < pRoot->data)
    {
        InsertElement(pRoot->left, data); // Desce na subárvore esquerda e chama a função recursivamente para inserir o elemento
    } 
    else if (data > pRoot->data)
    {
        InsertElement(pRoot->right, data); // Desce na subárvore direita e chama a função recursivamente para inserir o elemento
    }
}

// Função para encontrar o nó com o valor mínimo em uma árvore binária de busca
TreeNode* FindMin(TreeNode* pNode)
{
    while (pNode->left != nullptr)
    {
        pNode = pNode->left; // Continua descendo na subárvore esquerda até encontrar o nó com valor mínimo
    }
    
    return pNode; // Retorna o nó com valor mínimo
}

// Função para remover um elemento específico da árvore
TreeNode* RemoveNode(TreeNode* pRoot, int data)
{
    if (pRoot == nullptr) 
    {
        return nullptr;
    }
    else if (data < pRoot->data)
    {
        pRoot->left = RemoveNode(pRoot->left, data); // Se o valor a ser removido for menor, continua na subárvore esquerda
    }
    else if (data > pRoot->data)
    {
        pRoot->right = RemoveNode(pRoot->right, data); // Se o valor a ser removido for maior, continua na subárvore direita
    } 
    else 
    {
        // Encontrou o nó a ser removido

        if (pRoot->left == nullptr && pRoot->right == nullptr)
        {
            // Caso 1: O nó não tem filhos
            delete pRoot; // Libera memória
            pRoot = nullptr;
        } 
        else if (pRoot->left == nullptr) 
        {
            // Caso 2: O nó tem apenas um filho à direita
            TreeNode* pTemp = pRoot;
            pRoot = pRoot->right; // Atualiza o ponteiro do pai para apontar para o filho à direita
            delete pTemp; // Libera memória
        } 
        else if (pRoot->right == nullptr)
        {
            // Caso 2: O nó tem apenas um filho à esquerda
            TreeNode* pTemp = pRoot;
            pRoot = pRoot->left; // Atualiza o ponteiro do pai para apontar para o filho à esquerda
            delete pTemp; // Libera memória
        } 
        else 
        {
            // Caso 3: O nó tem dois filhos
            TreeNode* pTemp = FindMin(pRoot->right); // Encontra o nó com o valor mínimo na subárvore direita
            pRoot->data = pTemp->data; // Copia o valor mínimo para o nó atual
            pRoot->right = RemoveNode(pRoot->right, pTemp->data); // Remove o nó com o valor mínimo da subárvore direita
        }
    }
    
    return pRoot; // Retorna a raiz atualizada
}

void DeleteTree(TreeNode*& ptrRoot)
{
    // Se a árvore estiver vazia, não faz nada
    if (ptrRoot == nullptr)
    {
        return;
    }

    // Deleta os filhos
    DeleteTree(ptrRoot->left);
    DeleteTree(ptrRoot->right);

    // Deleta o nó atual
    free(ptrRoot);
    ptrRoot = nullptr;
}

void deleteTree(TreeNode*& ptrRoot)
{
    // Se a árvore estiver vazia, não faz nada
    if (ptrRoot == nullptr)
    {
        return;
    }

    // Deleta os filhos
    deleteTree(ptrRoot->left);
    deleteTree(ptrRoot->right);

    // Deleta o nó atual
    free(ptrRoot);
    ptrRoot = nullptr;
}