#include "sort.h"
#include <iostream>

using namespace std 

TreeNode* findMinAndRemove(TreeNode*& ptrRoot)
{
    if (ptrRoot == nullptr)
    {
        return nullptr; // Se a raiz for nula, não há nó mínimo para remover
    }
    else if (ptrRoot->ptrLeft == nullptr)
    {
        TreeNode* ptrMin = ptrRoot; // O nó mínimo é o nó atual (raiz)
        ptrRoot = ptrRoot->ptrRight; // A raiz é atualizada para o próximo nó
        ptrMin->ptrRight = nullptr; // Desconecta o nó mínimo da lista
        return ptrMin; // Retorna o nó mínimo removido
    }
    else
    {
        return findMinAndRemove(ptrRoot->ptrLeft); // Recursivamente encontra o nó mínimo na subárvore esquerda
    }
}

// Função auxiliar para inserir um nó em uma lista (ordenada por valor idata)
void insertNodeToList(TreeNode*& ptrList, TreeNode* ptrNode)
{
    if (ptrList == nullptr)
    {
        ptrList = ptrNode; // Se a lista estiver vazia, o nó se torna o primeiro nó da lista
    }
    else if (ptrNode->idata < ptrList->idata)
    {
        ptrNode->ptrRight = ptrList; // O nó atual é adicionado como o primeiro nó da lista
        ptrList = ptrNode; // O nó atual se torna o novo primeiro nó da lista
    }
    else
    {
        TreeNode* ptrCurrent = ptrList;
        while (ptrCurrent->ptrRight != nullptr && ptrCurrent->ptrRight->idata < ptrNode->idata)
        {
            ptrCurrent = ptrCurrent->ptrRight; // Percorre a lista até encontrar a posição correta para o nó atual
        }
        ptrNode->ptrRight = ptrCurrent->ptrRight; // O nó atual é inserido após o nó atual na posição correta
        ptrCurrent->ptrRight = ptrNode;
    }
}

// Função auxiliar para trocar os valores de dois nós
void swapNodeValues(TreeNode* node1, TreeNode* node2)
{
    int temp = node1->idata;
    node1->idata = node2->idata;
    node2->idata = temp;
}

void treeToList(TreeNode* ptrNode, TreeNode*& ptrList)
{
    if (ptrNode == nullptr)
    {
        return; // Se o nó for nulo, não há mais nada a ser feito
    }

    treeToList(ptrNode->ptrLeft, ptrList); // Converte a subárvore esquerda em uma lista

    insertNodeToList(ptrList, ptrNode); // Insere o nó atual na lista de forma ordenada

    treeToList(ptrNode->ptrRight, ptrList); // Converte a subárvore direita em uma lista
}


void bubbleSort(TreeNode*& ptrRoot)
{
    if (ptrRoot == nullptr || ptrRoot->ptrRight == nullptr)
    {
        return; // A árvore está vazia ou possui apenas um nó, não há necessidade de ordenação
    }

    TreeNode* ptrList = nullptr; // Ponteiro para a lista que será construída a partir da árvore
    treeToList(ptrRoot, ptrList); // Converte a árvore em uma lista

    TreeNode* ptrCurrent = ptrList; // Ponteiro para o nó atual da lista
    ptrRoot = ptrCurrent; // Atualiza o ponteiro da raiz para o início da lista

    while (ptrCurrent->ptrRight != nullptr)
    {
        ptrCurrent = ptrCurrent->ptrRight; // Percorre a lista até o último nó
    }

    ptrRoot->ptrLeft = nullptr; // Desconecta o nó inicial da lista da árvore
    ptrCurrent->ptrRight = nullptr; // Define o próximo do último nó como nulo, finalizando a lista
}

void selectionSort(TreeNode*& ptrRoot)
{
    TreeNode* ptrList = nullptr; // Ponteiro para a lista ordenada

    while (ptrRoot != nullptr)
    {
        TreeNode* ptrMin = findMinAndRemove(ptrRoot); // Encontra o nó mínimo na árvore e o remove
        ptrMin->ptrRight = nullptr; // Desconecta o nó mínimo da lista

        if (ptrList == nullptr)
        {
            // Caso especial: a lista ordenada está vazia, então o nó mínimo se torna a raiz da lista
            ptrList = ptrMin;
        }
        else
        {
            TreeNode* ptrCurrent = ptrList;
            while (ptrCurrent->ptrRight != nullptr)
            {
                ptrCurrent = ptrCurrent->ptrRight; // Encontra o último nó da lista ordenada
            }
            ptrCurrent->ptrRight = ptrMin; // Insere o nó mínimo no final da lista ordenada
        }
    }

    ptrRoot = ptrList; // Atualiza o ponteiro da raiz para a lista ordenada
}

void insertionSort(TreeNode*& ptrRoot) {
    if (ptrRoot == nullptr || ptrRoot->ptrRight == nullptr)
        return;

    TreeNode *sorted = nullptr; // Ponteiro para a lista ordenada
    TreeNode *current = ptrRoot; // Ponteiro para percorrer a lista não ordenada

    while (current != nullptr) {
        TreeNode* next = current->ptrRight; // Próximo nó na lista não ordenada

        if (sorted == nullptr || sorted->idata >= current->idata) {
            // Caso especial: insere o nó no início da lista ordenada
            current->ptrRight = sorted;
            sorted = current;
        } else {
            TreeNode *temp = sorted;
            while (temp->ptrRight != nullptr && temp->ptrRight->idata < current->idata)
                temp = temp->ptrRight;

            // Insere o nó em uma posição intermediária da lista ordenada
            current->ptrRight = temp->ptrRight;
            temp->ptrRight = current;
        }
        current = next; // Avança para o próximo nó na lista não ordenada
    }

    ptrRoot = sorted; // Atualiza o ponteiro da raiz para a lista ordenada
}

