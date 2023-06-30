#include "tree.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Função para criar um novo nó da árvore
TreeNode* createNode(int idata)
{
    TreeNode* ptrNewNode = (TreeNode*)malloc(sizeof(TreeNode));
    ptrNewNode->idata = idata;
    ptrNewNode->ptrLeft = nullptr;
    ptrNewNode->ptrRight = nullptr;
    return ptrNewNode;
}

// Função para inserir um nó na árvore
TreeNode* insertNode(TreeNode* ptrRoot, int idata)
{
    if (ptrRoot == nullptr)
    {
        return createNode(idata); // Se a árvore estiver vazia, cria um novo nó com o valor fornecido
    }
    
    if (idata < ptrRoot->idata) 
    {
        ptrRoot->ptrLeft = insertNode(ptrRoot->ptrLeft, idata); // Se o valor é menor que o valor do nó atual, insere na subárvore esquerda
    } 
    else if (idata > ptrRoot->idata) 
    {
        ptrRoot->ptrRight = insertNode(ptrRoot->ptrRight, idata); // Se o valor é maior que o valor do nó atual, insere na subárvore direita
    }

    return ptrRoot; // Retorna a raiz da árvore modificada
}

// Função para construir uma árvore a partir de entrada do usuário
TreeNode* buildTreeFromUserInput()
{
    int idata;
    TreeNode* ptrRoot = nullptr;

    cout << "Digite os números separados por espaço (ou -1 para finalizar): ";
    while (cin >> idata && idata != -1) 
    {
        ptrRoot = insertNode(ptrRoot, idata); // Insere cada número na árvore utilizando a função insertNode
    }

    return ptrRoot; // Retorna a raiz da árvore construída
}

// Função para obter a altura da árvore
int getHeight(TreeNode* ptrRoot) 
{
    if (ptrRoot == nullptr)
    {
        return 0; // Retorna 0 se a árvore estiver vazia (raiz nula)
    }

    int iLeftHeight = getHeight(ptrRoot->ptrLeft); // Obtém a altura da subárvore esquerda
    int iRightHeight = getHeight(ptrRoot->ptrRight); // Obtém a altura da subárvore direita
    
    int iTreeHeight = 1 + max(iLeftHeight, iRightHeight); // A altura da árvore é o máximo entre as alturas das subárvores esquerda e direita, mais 1
    
    return iTreeHeight; // Retorna a altura da árvore
}

// Função para obter o tamanho da árvore (número de nós)
int getSize(TreeNode* ptrRoot) 
{
    if (ptrRoot == nullptr) 
    {
        return 0; // Retorna 0 se a árvore estiver vazia
    }

    int iSize = 1; // Inicia o tamanho com 1 para contar o nó atual

    if (ptrRoot->ptrLeft != nullptr)
    {
        iSize += getSize(ptrRoot->ptrLeft); // Chama recursivamente a função para obter o tamanho da subárvore esquerda e adiciona ao tamanho total
    }

    if (ptrRoot->ptrRight != nullptr)
    {
        iSize += getSize(ptrRoot->ptrRight); // Chama recursivamente a função para obter o tamanho da subárvore direita e adiciona ao tamanho total
    }

    return iSize; // Retorna o tamanho da árvore
}


// Função para inserir um elemento na árvore
void insertElement(TreeNode*& ptrRoot, int idata) 
{
    // Verifica se a raiz atual é nula 
    if (ptrRoot == nullptr) 
    {
        ptrRoot = createNode(idata); // Cria um novo nó com o valor especificado e o torna a raiz da árvore
    } 
    else if (idata < ptrRoot->idata)
    {
        insertElement(ptrRoot->ptrLeft, idata); // Desce na subárvore esquerda e chama a função recursivamente para inserir o elemento
    } 
    else if (idata > ptrRoot->idata)
    {
        insertElement(ptrRoot->ptrRight, idata); // Desce na subárvore direita e chama a função recursivamente para inserir o elemento
    }
}

// Função para encontrar o nó com o valor mínimo em uma árvore binária de busca
TreeNode* findMin(TreeNode* ptrNode)
{
    while (ptrNode->ptrLeft != nullptr)
    {
        ptrNode = ptrNode->ptrLeft; // Continua descendo na subárvore esquerda até encontrar o nó com valor mínimo
    }
    
    return ptrNode; // Retorna o nó com valor mínimo
}

// Função para remover um elemento específico da árvore
TreeNode* removeNode(TreeNode* ptrRoot, int idata)
{
    if (ptrRoot == nullptr) 
    {
        return nullptr;
    }
    else if (idata < ptrRoot->idata)
    {
        ptrRoot->ptrLeft = removeNode(ptrRoot->ptrLeft, idata); // Se o valor a ser removido for menor, continua na subárvore esquerda
    }
    else if (idata > ptrRoot->idata)
    {
        ptrRoot->ptrRight = removeNode(ptrRoot->ptrRight, idata); // Se o valor a ser removido for maior, continua na subárvore direita
    } 
    else 
    {
        // Encontrou o nó a ser removido

        if (ptrRoot->ptrLeft == nullptr && ptrRoot->ptrRight == nullptr)
        {
            // Caso 1: O nó não tem filhos
            free(ptrRoot); // Libera memória
            ptrRoot = nullptr;
        } 
        else if (ptrRoot->ptrLeft == nullptr) 
        {
            // Caso 2: O nó tem apenas um filho à direita
            TreeNode* ptrTemp = ptrRoot;
            ptrRoot = ptrRoot->ptrRight; // Atualiza o ponteiro do pai para apontar para o filho à direita
            free(ptrTemp); // Libera memória
        } 
        else if (ptrRoot->ptrRight == nullptr)
        {
            // Caso 2: O nó tem apenas um filho à esquerda
            TreeNode* ptrTemp = ptrRoot;
            ptrRoot = ptrRoot->ptrLeft; // Atualiza o ponteiro do pai para apontar para o filho à esquerda
            free(ptrTemp); // Libera memória
        } 
        else 
        {
            // Caso 3: O nó tem dois filhos
            TreeNode* ptrTemp = findMin(ptrRoot->ptrRight); // Encontra o nó com o valor mínimo na subárvore direita
            ptrRoot->idata = ptrTemp->idata; // Copia o valor mínimo para o nó atual
            ptrRoot->ptrRight = removeNode(ptrRoot->ptrRight, ptrTemp->idata); // Remove o nó com o valor mínimo da subárvore direita
        }
    }
    
    return ptrRoot; // Retorna a raiz atualizada
}

// Função para liberar a memória ocupada pela árvore
void deleteTree(TreeNode*& ptrRoot)
{
    if (ptrRoot == nullptr)
    {
        return; // Se a árvore estiver vazia, não faz nada
    }

    deleteTree(ptrRoot->ptrLeft); // Libera a memória ocupada pela subárvore esquerda
    deleteTree(ptrRoot->ptrRight); // Libera a memória ocupada pela subárvore direita

    free(ptrRoot); // Libera a memória ocupada pelo nó atual
    ptrRoot = nullptr; // Define o ponteiro para a raiz como nulo
}
