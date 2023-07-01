#include "tree.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

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

// Função para construir uma árvore a partir de um arquivo de texto 
TreeNode* buildTreeFromFile(const string& filename) 
{
    // Abre o arquivo para leitura
    ifstream inputFile(filename);
    // Verifica se o arquivo foi aberto corretamente
    if (!inputFile) 
    {
        cout << "Erro ao abrir o arquivo." << endl;
        return nullptr;
    }

    // Inicializa a raiz da árvore como nulo
    TreeNode* ptrRoot = nullptr;
    int idata;
    string line;

    // Lê cada linha do arquivo
    while (getline(inputFile, line)) {
        // Cria um objeto istringstream para analisar cada número na linha
        istringstream iss(line);
        // Lê cada número e insere na árvore
        while (iss >> idata) {
            ptrRoot = insertNode(ptrRoot, idata);  // Chama a função insertNode para inserir o número na árvore
        }
    }

    // Fecha o arquivo após a leitura
    inputFile.close();
    // Retorna o ponteiro para a raiz da árvore
    return ptrRoot;
}


// Função para imprimir os nós de uma árvore binária em ordem crescente
void printInOrder(TreeNode* ptrRoot)
{
    // Verifica se o ponteiro para a raiz não é nulo
    if (ptrRoot != nullptr) {
        // Imprime os nós na ordem correta: esquerda, raiz, direita
        printInOrder(ptrRoot->ptrLeft);  // Imprime os nós da subárvore esquerda
        cout << ptrRoot->idata << " ";  // Imprime o valor do nó atual
        printInOrder(ptrRoot->ptrRight);  // Imprime os nós da subárvore direita
    }
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

// Função para verificar se a árvore é perfeita ou não
bool PerfectTree(TreeNode* ptrRoot, int iHeight = -1, int iLevel = 0)
{
    // Caso a árvore não nós
    if (ptrRoot == nullptr)
    {
        return true; // Retorna que a árvore é perfeita
    }
    // Caso a altura da árvore não tenha sido calculado
    else if (iHeight == -1)
    {
        iHeight = getHeight(ptrRoot); // Função getHeight é chamada para calcular a altura da árvore
    }
    // Caso o nó atual não tenha filhos
    else if (ptrRoot->ptrLeft == nullptr and ptrRoot->ptrRight == nullptr)
    {
        return (iHeight == iLevel + 1); // Se a altura da árvore for igual ao nível da recursão mais 1, retorna verdadeiro
    }
    // Caso o nó atual tenha somente um filho
    else if (ptrRoot->ptrLeft == nullptr or ptrRoot->ptrRight == nullptr)
    {
        return false; // Retorna que a árvore não é perfeita
    }
    // Se tanto o lado esquerdo quanto o lado direito são perfeitos, a árvore é perfeita
    return PerfectTree(ptrRoot->ptrLeft, iHeight, iLevel + 1) and 
        PerfectTree(ptrRoot->ptrRight, iHeight, iLevel + 1);
}

// Função para verificar se a árvore é completa ou não
bool CompleteTree(TreeNode* ptrRoot, int iIndex, int iSize)
{
    
    // Caso a árvore não tenha nós
    if (ptrRoot == nullptr)
    {
        return true; // Retorna que a árvore é completa
    }
    
    // Se o índice for maior ou igual ao número de nós
    else if (iIndex >= iSize)
    {
        return false; // Retorna que a árvore não é completa
    }
    
    // Verifica se as subárvores da esquerda e da direita são completas
    return (CompleteTree(ptrRoot->ptrLeft, 2 * iIndex + 1, iSize) and CompleteTree(ptrRoot->ptrRight, 2 * iIndex + 2, iSize));
}

// Função para buscar o endereço de um elemento da árvore
TreeNode* findAddress(TreeNode*& ptrRoot, int idata)
{
    if (ptrRoot == nullptr or ptrRoot->idata == idata)
    {
        return ptrRoot; // Retorna nullptr se não encontrar o ponteiro ou o ponteiro do nó
    }
    else if (idata < ptrRoot->idata)
    {
        return findAddress(ptrRoot->ptrLeft, idata); // Verifica na subárvore esquerda
    }
    else
    {
        return findAddress(ptrRoot->ptrRight, idata); // Verifica na subárvore direita
    }
}
