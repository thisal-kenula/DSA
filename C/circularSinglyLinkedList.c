#include <stdio.h>
#include <stdlib.h>

// Define node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create new node
Node* createNode (int data) {
    // Allocate memory for new node
    Node* newNode = (Node*) malloc(sizeof(Node));

    // If memory allocation failed
    if (!newNode) {
        printf("Memory allocation failed.");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL; // To avoid garbage values

    return newNode;
}

// Print values
void printList (Node* node) {
    // Remember first node to stop when comes back
    if (!node) return;
    Node* startNode = node;
    do {
        printf("%d ->", node->data);
        node = node->next;
    } while(node != startNode);
    printf("...");
}

int main() {
    Node* node1 = createNode(20);
    Node* node2 = createNode(18);
    Node* node3 = createNode(6);
    Node* node4 = createNode(23);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node1; // Go back to first node

    printList(node3);

    // Free memory
    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}