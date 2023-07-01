#include "sort.h"
#include <iostream>

using namespace std;

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

    struct TreeNode* ptrLeft = ptrNode->ptrLeft; // Ponteiro para a subárvore esquerda
    struct TreeNode* ptrRight = ptrNode->ptrRight; // Ponteiro para a subárvore direita

    // Desconecta o nó atual da árvore
    ptrNode->ptrLeft = nullptr;
    ptrNode->ptrRight = nullptr;

    if (ptrList == nullptr)
    {
        ptrList = ptrNode; // Se a lista estiver vazia, o nó atual se torna o primeiro nó da lista
    }
    else
    {
        struct TreeNode* ptrCurrent = ptrList;
        while (ptrCurrent->ptrRight != nullptr)
        {
            ptrCurrent = ptrCurrent->ptrRight; // Percorre a lista até encontrar o último nó
        }
        ptrCurrent->ptrRight = ptrNode; // O nó atual é inserido no final da lista
    }
    
    treeToList(ptrLeft, ptrList); // Converte a subárvore esquerda em uma lista
    treeToList(ptrRight, ptrList); // Converte a subárvore direita em uma lista
}


void bubbleSort(struct TreeNode*& ptrHead)
{
    struct TreeNode* ptrList = nullptr;
    treeToList(ptrHead, ptrList);

    // Casos especiais: lista vazia ou único elemento
    if (ptrList == nullptr || ptrList->ptrRight == nullptr)
        return;
    
    // Booleano para indicar se a lista está ordenada
    bool bSorted = true;

    // Ponteiro para auxiliar na iteração da lista
    struct TreeNode* ptrPrev = ptrList;
    // Ponteiro que indica o começo da parte ordenada da lista
    struct TreeNode* ptrOuter = ptrPrev->ptrRight;
    
    // Caso especial: primeiro iteração da lista toda
    // Caso especial: primeiro elemento
    if (ptrOuter->idata < ptrPrev->idata)
    {
        // Troca o primeiro elemento com o segundo
        ptrPrev->ptrRight = ptrOuter->ptrRight;
        ptrOuter->ptrRight = ptrPrev;
        ptrPrev = ptrOuter;
        ptrList = ptrOuter;
        bSorted = false;
    }

    ptrOuter = ptrPrev->ptrRight;
    
    // O primeiro loop vai até o último elemento da lista
    while (ptrOuter->ptrRight != nullptr)
    {
        if (ptrOuter->ptrRight->idata < ptrOuter->idata)
        {
            // Troca o elemento atual com o próximo
            struct TreeNode* ptrTemp = ptrOuter->ptrRight;
            ptrOuter->ptrRight = ptrTemp->ptrRight;
            ptrTemp->ptrRight = ptrOuter;
            ptrPrev->ptrRight = ptrTemp;
            bSorted = false;
        }
        
        ptrPrev = ptrPrev->ptrRight;
        ptrOuter = ptrPrev->ptrRight;
    }

    // Se a lista estiver ordenada, retorna
    if (bSorted) {
        ptrHead = ptrList;
        return;
    }

    // O loop exterior vai do final da lista até o segundo elemento,
    // pois quando chegar no segundo, todo resto já estará ordenado
    while (ptrList->ptrRight != ptrOuter)
    {
        ptrPrev = ptrList;
        struct TreeNode* ptrInner = ptrPrev->ptrRight;
        bSorted = true;

        // Caso especial: primeiro elemento
        if (ptrInner->idata < ptrPrev->idata)
        {
            // Troca o primeiro elemento com o segundo
            ptrPrev->ptrRight = ptrInner->ptrRight;
            ptrInner->ptrRight = ptrPrev;
            ptrPrev = ptrInner;
            ptrList = ptrInner;
            bSorted = false;
        }

        ptrInner = ptrPrev->ptrRight;

        // O loop interior vai do começo até o elemento do loop exterior,
        // pois os elementos depois dele já estão ordenados
        while (ptrInner->ptrRight != ptrOuter)
        {
            if (ptrInner->ptrRight->idata < ptrInner->idata)
            {
                // Troca o elemento atual com o próximo
                struct TreeNode* ptrTemp = ptrInner->ptrRight;
                ptrInner->ptrRight = ptrTemp->ptrRight;
                ptrTemp->ptrRight = ptrInner;
                ptrPrev->ptrRight = ptrTemp;
                bSorted = false;
            }
            
            ptrPrev = ptrPrev->ptrRight;
            ptrInner = ptrPrev->ptrRight;
        }

        // Se a lista estiver ordenada, retorna
        if (bSorted) {
            ptrHead = ptrList;
            return;
        }

        ptrOuter = ptrInner;
    }

    ptrHead = ptrList;
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

void insertionSort(struct TreeNode*& ptrHead) {
    if (ptrHead == nullptr) {
        return;
    }

    // Ponteiros do nó a ser inserido na parte ordenada da lista
    struct TreeNode* ptrCurrentPrev = ptrHead;
    struct TreeNode* ptrCurrent = ptrCurrentPrev->ptrRight;

    while (ptrCurrent != nullptr) {
        // Ponteiro para o nó a ser comparado com o nó a ser inserido
        struct TreeNode* ptrIterate = ptrHead;

        // Caso especial para a primeira posição
        if (ptrIterate->idata > ptrCurrent->idata) {
            // Remove o nó da lista
            ptrCurrentPrev->ptrRight = ptrCurrent->ptrRight;

            // Insere o nó na posição correta
            ptrCurrent->ptrRight = ptrIterate;
            ptrHead = ptrCurrent;

            // Itera para o próximo nó
            ptrCurrent = ptrCurrentPrev->ptrRight;
            continue;
        }

        // Ponteiro para o nó anterior ao ponto de inserção
        struct TreeNode* ptrIteratePrev = ptrIterate;
        ptrIterate = ptrIteratePrev->ptrRight;

        // Itera a parte ordenada até encontrar o ponto de inserção
        while (ptrIterate != ptrCurrent) {
            // Se achar o ponto de inserção, insere o nó na posição correta
            if (ptrIterate->idata > ptrCurrent->idata) {
                // Remove o nó da lista
                ptrCurrentPrev->ptrRight = ptrCurrent->ptrRight;

                // Insere o nó na posição correta
                ptrIteratePrev->ptrRight = ptrCurrent;
                ptrCurrent->ptrRight = ptrIterate;
                break;
            }

            // Itera para o próximo nó
            ptrIteratePrev = ptrIterate;
            ptrIterate = ptrIteratePrev->ptrRight;
        }

        // Se o nó não foi inserido, ele já está na posição correta
        if (ptrIterate == ptrCurrent) {
            ptrCurrentPrev = ptrCurrent;
            ptrCurrent = ptrCurrentPrev->ptrRight;
        }
        else {
            ptrCurrent = ptrCurrentPrev->ptrRight;
        }
    }
}

void insertionGapSort(struct TreeNode*& ptrHead, int iSize, int iGap) {
    if (iSize <= iGap) {
        return;
    }

    if (iGap == 1) {
        insertionSort(ptrHead);
        return;
    }
    
    // Ponteiros para criar uma lista temporária com o primeiro nó
    struct TreeNode* ptrTempHead = ptrHead;
    struct TreeNode* ptrTempTail = ptrHead;

    // Remove o primeiro nó da lista original
    ptrHead = ptrHead->ptrRight;
    iSize--;

    // Ponteiros para iterar pela lista original
    struct TreeNode* ptrCurrentPrev = ptrHead;
    struct TreeNode* ptrCurrent = ptrCurrentPrev->ptrRight;
    int iCount = 2;

    while (ptrCurrent != nullptr) {
        // Encontra os nós de um segmento da lista a ser ordenado
        if (iCount % iGap == 0) {
            // Remove o nó da lista original
            ptrCurrentPrev->ptrRight = ptrCurrent->ptrRight;
            iSize--;

            // Insere o nó na lista temporária
            ptrTempTail->ptrRight = ptrCurrent;
            ptrTempTail = ptrCurrent;
        }
        else {
            ptrCurrentPrev = ptrCurrent;
        }

        ptrCurrent = ptrCurrentPrev->ptrRight;
        iCount++;
    }

    ptrTempTail->ptrRight = nullptr;
    // Ordena o segmento da lista
    insertionSort(ptrTempHead);
    // Ordena o resto da lista, mas como alguns elementos foram removidos,
    // a distância entre os nós é menor, então iGap é decrementado
    insertionGapSort(ptrHead, iSize, iGap - 1);

    // Remove o primeiro nó da lista temporária
    ptrCurrentPrev = ptrTempHead;
    ptrTempHead = ptrTempHead->ptrRight;
    // Insere o nó na lista original
    ptrCurrentPrev->ptrRight = ptrHead;
    ptrHead = ptrCurrentPrev;

    // Variáveis para iterar pela lista original
    ptrCurrent = ptrCurrentPrev->ptrRight;
    iCount = 1;

    // Itera pelas listas para inserir os nós ordenados nos lugares certos
    while (ptrTempHead != nullptr) {
        if (iCount % iGap == 0) {
            // Remove o nó da lista temporária
            ptrCurrentPrev->ptrRight = ptrTempHead;
            ptrTempHead = ptrTempHead->ptrRight;

            // Insere o nó na lista original
            ptrCurrentPrev = ptrCurrentPrev->ptrRight;
            ptrCurrentPrev->ptrRight = ptrCurrent;
        }
        else {
            ptrCurrentPrev = ptrCurrent;
            ptrCurrent = ptrCurrentPrev->ptrRight;
        }

        iCount++;
    }
}

void shellSort(struct TreeNode*& ptrHead) {
    if (ptrHead == nullptr) {
        return;
    }

    struct TreeNode* ptrList = nullptr;
    treeToList(ptrHead, ptrList);

    int iSize = 0;
    struct TreeNode* ptrCurrent = ptrList;
    while (ptrCurrent != nullptr) {
        iSize++;
        ptrCurrent = ptrCurrent->ptrRight;
    }

    // Hibbard's increments
    int iGap = 1;
    while (iGap < iSize) {
        iGap = 2*iGap + 1;
    }
    iGap /= 2;

    // Ordena a lista com os incrementos de Hibbard
    while (iGap > 0) {
        insertionGapSort(ptrList, iSize, iGap);
        iGap /= 2;
    }

    ptrHead = ptrList;
}