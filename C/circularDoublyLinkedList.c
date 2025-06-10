#include <stdio.h>
#include <stdlib.h>

// Define node data type
typedef struct Node {
    int data; // 
    struct Node* next; // Pointer of next node
    struct Node* prev; // Pointer of previous node
} Node;

// Create new node
Node* createNode (int data) {
    // Allocate memory for a new node
    Node* newNode = (Node*) malloc(sizeof(Node));

    // If memory allocation failed
    if (!newNode) {
        printf("Memory allocation failure.");
        exit(1);
    }

    newNode->data = data;
    // Clear garbage data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

// Print list forward
void traverseForward (Node* node) {
    // If received an empty pointer
    if (!node) {
        printf("NULL\n");
        return;
    }

    Node* startNode = node;

    // Print next node until comes back to the initial one
    do {
        printf("%d -> ", node->data);
        node = node->next; 
    } while (node != startNode);
    
    printf("...\n");
}

// Print list backward
void traverseBackward (Node* node) {
    // If received an empty pointer
    if (!node) {
        printf("NULL\n");
        return;
    }

    Node* startNode = node;

    do {
        printf("%d -> ", node->data);
        node = node->prev;
    } while (node != startNode);
    
    printf("...\n");
}

// Testing
int main () {
    Node* node1 = createNode(20);
    Node* node2 = createNode(18);
    Node* node3 = createNode(6);
    Node* node4 = createNode(23);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node1;

    node4->prev = node3;
    node3->prev = node2;
    node2->prev = node1;
    node1->prev = node4;

    traverseForward(node2);
    traverseBackward(node3);

    // Free Memory
    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}