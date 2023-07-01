#include "queue.h"
#include <iostream>

// Função para criar uma fila
struct Queue* createQueue() {
    // Cria uma fila vazia
    struct Queue* ptrQueue = (struct Queue*) malloc(sizeof(struct Queue));
    ptrQueue->ptrFront = nullptr;
    ptrQueue->ptrRear = nullptr;

    return ptrQueue;
}

// Função para inserir um nó na fila
void enqueue(struct Queue* ptrQueue, struct TreeNode* ptrTreeNode) {
    // Cria um novo nó
    struct QueueNode* ptrNewNode = (struct QueueNode*) malloc(sizeof(struct QueueNode));
    ptrNewNode->ptrTreeNode = ptrTreeNode;
    ptrNewNode->ptrNext = nullptr;

    // Se a fila estiver vazia, o novo nó será o primeiro e o último
    if (ptrQueue->ptrRear == nullptr) {
        ptrQueue->ptrFront = ptrNewNode;
        ptrQueue->ptrRear = ptrNewNode;
        return;
    }

    // Adiciona o novo nó ao final da fila e muda o ponteiro de trás
    ptrQueue->ptrRear->ptrNext = ptrNewNode;
    ptrQueue->ptrRear = ptrNewNode;
}

// Função para remover o primeiro nó da fila e retornar o seu valor
struct TreeNode* dequeue(struct Queue* ptrQueue) {
    // Se a fila estiver vazia, retorna nullptr
    if (ptrQueue->ptrFront == nullptr) {
        return nullptr;
    }

    // Guarda o nó da frente e muda o ponteiro da frente
    struct TreeNode* ptrTreeNode = ptrQueue->ptrFront->ptrTreeNode;
    struct QueueNode* ptrTemp = ptrQueue->ptrFront;
    ptrQueue->ptrFront = ptrQueue->ptrFront->ptrNext;

    // Se a frente ficar vazia, muda o ponteiro de trás para nullptr
    if (ptrQueue->ptrFront == nullptr) {
        ptrQueue->ptrRear = nullptr;
    }

    // Libera a memória do nó removido
    free(ptrTemp);

    return ptrTreeNode;
}

// Função para deletar uma fila
void deleteQueue(struct Queue*& ptrQueue) {
    // Enquanto a fila não estiver vazia, remove o primeiro nó
    while (ptrQueue->ptrFront != nullptr) {
        dequeue(ptrQueue);
    }

    // Libera a memória da fila
    free(ptrQueue);
    ptrQueue = nullptr;
}