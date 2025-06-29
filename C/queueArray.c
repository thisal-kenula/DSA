#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Number of elements a queue can hold

typedef struct Queue {
    int data[MAX];
    int top; // last index;
} Queue;

/// @brief Create a new empty queue.
/// @return Pointer to created queue (NULL if failed to allocate memory).
Queue* createQueue() {
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));

    // Memory allocation failed
    if (newQueue == NULL) {
        return NULL;
    }

    newQueue->top = -1;
    return newQueue;
}

/// @brief Add an integer to queue
/// @param queue Pointer to queue
/// @param data Integer value
/// @return 0 if succeed, -1 if queue is full.
int enqueue(Queue* queue, int data) {
    if (queue->top >= MAX - 1) {
        return -1;
    }
    queue->data[++queue->top] = data;
    return 0;
}

/// @brief Remove and get first element of the queue. .
/// @param queue Pointer to the queue.
/// @param i Pointer to the integer variable to assign the first value.
/// @return 0 if succeed. -1 if failed.
int dequeue(Queue* queue, int* i) {
    // Empty queue
    if (queue->top < 0) {
        return -1;
    }

    int firstElement = queue->data[0];
    --queue->top;
    // Shift elements
    for (int i = 0; i <= queue->top; ++i) {
        queue->data[i] = queue->data[i+1];
    }

    *i = firstElement;
    return 0;
}

/// @brief Check if a queue is empty.
/// @param queue Pointer to the queue.
/// @return 1 if empty, 0 if not.
int isEmpty(const Queue* queue) {
    return queue->top < 0;
}

/// @brief Get first element of the queue. 
/// Will cause an error if the queue is empty (Check if empty before calling).
/// @param queue Pointer to queue.
/// @param i Pointer to variable to assign peeked value.
/// @return 0 if succeed, -1 if failed.
int peek(const Queue* queue, int* i) {
    if (queue->top < 0) {
        return -1;
    }
    *i = queue->data[0];
    return 0;
}

/// @brief Returns the number of elements in the queue. 
/// @param queue  POinter to the queue.
/// @return The number of elements in the queue. 
int size(const Queue* queue) {
    return queue->top+1;
}

/// @brief Print all the values of the queue;
/// @param queue 
void printQueue(const Queue* queue) {
    for (int i = 0; i <= queue->top; ++i) {
        printf("%d <- ", queue->data[i]);
    }
    printf("NULL\n");
}

// Testing
int main() {
    // Create queue
    Queue* myqueue = createQueue();
    if (myqueue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printQueue(myqueue); // Print empty queue

    printf("Size: %d\n", size(myqueue)); // Queue size

    // IsEmpty (1 for Empty)
    printf("Is empty: %d\n", isEmpty(myqueue));

    // Peek (For empty queue)
    int peekVal;
    if (peek(myqueue, &peekVal) == 0) {
        printf("Peek: %d\n", peekVal);
    } else {
        printf("Empty queue.\n");
    }

    // Enqueue
    enqueue(myqueue, 20);
    enqueue(myqueue, 18);
    enqueue(myqueue, 6);
    enqueue(myqueue, 23);

    // Test enqueue for a full queue
    // for (int i = 0; i < 105; ++i) {
    //     if (enqueue(myqueue, i) == 0) {
    //         printf("Added %d to queue.\n", i);
    //     } else {
    //         printf("Queue full.\n");
    //     }
    // }

    printQueue(myqueue); // Print non-empty queue

    // Peek
    int peekVal2;
    if (peek(myqueue, &peekVal2) == 0) {
        printf("Peek: %d\n", peekVal2);
    } else {
        printf("Empty queue.\n");
    }

    // Dequeue
    int removed1;
    if (dequeue(myqueue, &removed1) == 0) {
        printf("Successfully removed %d\n", removed1);
    } else {
        printf("Empty queue. Can't remove.\n");
    }

    printQueue(myqueue);

    free(myqueue);
    return 0;
}