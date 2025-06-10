#include <stdio.h>
#include <stdlib.h>

// Define node data type
typedef struct Node {
    int data;
    struct Node* next; // Pointer to next node
    struct Node* prev; // Pointer of previous node
} Node;

Node* createNode (int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    if (!newNode) {
        printf("Memory allocation error");
        exit(1);
    }

    newNode->data = data;
    // To ensure that new node does not point for garbage value
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void traverseForward (Node* node) {
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }

    printf("null\n");
}

void traverseBackward (Node* node) {
    while (node) {
        printf("%d -> ", node->data);
        node = node->prev;
    }

    printf("null\n");
}

int main() {
    Node* node1 = createNode(20);
    Node* node2 = createNode(18);
    Node* node3 = createNode(6);
    Node* node4 = createNode(23);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    node4->prev = node3;
    node3->prev = node2;
    node2->prev = node1;

    traverseForward(node1);
    traverseBackward(node4);

    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}