// Linked list implementation in C

#include <stdio.h>
#include <stdlib.h>

// Define Node data type
typedef struct Node {
    int data; // Store the value
    struct Node* next; // Pointer to next node
} Node;

// Function for creating a new node
// Allocates memory for a node and returns the pointer.
Node* createNode (int data) {
    
    // `malloc(sizeof(Node))`: allocate memory for a size of Node
    Node* newNode = (Node*) malloc(sizeof(Node));

    // if newNode == Null (`malloc` returns Null if failed.)
    if (!newNode) { 
        printf("Memory allocation failed!");
        exit(1); // To exit the program with an error
    }

    newNode->data = data; // Sytactic sugar for (*newNode).data = data
    newNode->next = NULL;

    return newNode;
}

// Print the values of Nodes
void printList (Node* node) {
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

//Test
int main() {
    Node* node1 = createNode(20);
    Node* node2 = createNode(18);
    Node* node3 = createNode(06);
    Node* node4 = createNode(23);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    printList(node1);

    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}