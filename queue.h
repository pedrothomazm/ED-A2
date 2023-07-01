#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode {
    struct TreeNode* ptrTreeNode;
    struct QueueNode* ptrNext;
};

struct Queue {
    struct QueueNode* ptrFront;
    struct QueueNode* ptrRear;
};

struct Queue* createQueue();
void enqueue(struct Queue* ptrQueue, struct TreeNode* ptrTreeNode);
struct TreeNode* dequeue(struct Queue* ptrQueue);
void deleteQueue(struct Queue*& ptrQueue);

#endif