/**
 * @file queueLinkedList.c
 * @author Thisal Kenula
 * @date 2025-06-28
 * @brief Queue Implementation using linked lists. 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data; // Value in Node
    struct Node* next; // Pointer to next Node
} Node;

typedef struct Queue {
    Node* startNode; // First node;
    size_t size; // Number of nodes in the queue
    // Add a last node property to make enqueue more performance efficient.
} Queue;

/// @brief Creates and initializes a new empty queue.
/// @return Pointer to created the Queue struct, or NULL if memory allocation failed. 
Queue* createQueue() {
    // Allocate memory
    Queue* newQueue = malloc(sizeof(Queue));

    // If memory allocation failed
    if (newQueue == NULL) {
        return NULL;
    }

    // Memory allocated
    newQueue->size = 0;
    newQueue->startNode = NULL;
    return newQueue;
}

/// @param queue Pointer of the queue.
/// @return Size of the queue.
size_t size(const Queue* queue) {
    return queue->size;
}

/// @brief Get first element of Queue.
/// @param queue Pointer to queue.
/// @param i Pointer to int variable to assign peeked value.
/// @return 0 if succeeded. -1 if failed.
int peek(const Queue* queue, int* i) {
    if (queue->size == 0) {
        return -1;
    }
    *i = queue->startNode->data;
    return 0;
}

/// @brief Add a new node with a value to the queue.
/// @param queue Pointer of the queue.
/// @param value Value to be added.
/// @return 0 if succeeded, -1 if memory allocation failed.
int enqueue(Queue* queue, int value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return -1;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (queue->size == 0) {
        queue->startNode = newNode;
    } else {
        Node* node = queue->startNode;
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = newNode;
    }
    ++queue->size; 
    
    return 0;
}

/// @brief Removes and returns the first value from queue.
/// @param queue Pointer to the queue.
/// @param i Pointer of the integer to assign the value of the
/// removed node
/// @return 0 if succeeded, -1 for an empty queue.
int dequeue(Queue* queue, int* i) {
    // Empty queue
    if (queue->startNode == NULL) return -1;

    Node* nodeToRemove = queue->startNode;
    *i = nodeToRemove->data;
    queue->startNode = (queue->startNode)->next;
    free(nodeToRemove);
    --queue->size;
    return 0;
}

/// @brief Print all values in queue.
/// @param queue Pointer to queue.
void printQueue(const Queue* queue) {
    Node* node = queue->startNode;
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void deleteQueue (Queue* queue) {
    while (queue->startNode) {
        Node* tmp = queue->startNode;
        queue->startNode = tmp->next;
        free(tmp);
    }
    free(queue);
}

int main() {
    // Testing
    // Create Queue
    Queue* myQueue = createQueue();
    if (myQueue == NULL) {
        printf("Memory allocation failed for queue.");
        exit(1);
    }

    printQueue(myQueue);

    // Peek on empty queue
    { // To prevent making x a global variable.
        int x;
        if (peek(myQueue, &x) == 0) {
            printf("Peek: %d\n", x);
        } else {
            printf("Peek: NULL\n");
        }
    }

    enqueue(myQueue, 20);
    enqueue(myQueue, 18);
    enqueue(myQueue, 6);
    enqueue(myQueue, 23);

    printf("Size: %zu\n", size(myQueue));
    
    { // To prevent making x a global variable.
        int x;
        if (peek(myQueue, &x) == 0) {
            printf("Peek: %d\n", x);
        } else {
            printf("Peek: NULL\n");
        }
    }

    printQueue(myQueue);

    for (int i = 0; i < 5; i++)
    {
        int dequeued;
        if (!dequeue(myQueue, &dequeued)) {
            printf("Removed: %d\n", dequeued);
        } else {
            printf("Can't remove from empty queue.\n");
        }
    }

    deleteQueue(myQueue);

    return 0;
}
