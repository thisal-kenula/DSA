/*
* Linked list operations on a singly linked list
* Not tested to handle edge cases
* Includes:
*   - Traversal
*   - Find lowest value
*   - Delete a node
    - Insert a node
*/
#include <stdio.h>
#include <stdlib.h>

// Define data type Node
typedef struct Node {
    int data;
    struct Node* next; // Pointer to next node
} Node;

/**
 * Create new node
 * 
 * @param data Value of the node
 * @return Pointer of the created node
 */
Node* createNode(int data) {
    // Allocate memory for new node
    Node* newNode = (Node*) malloc(sizeof(Node));

    // If memory allocation failed
    if (!newNode) {
        printf("Memory allocation failed!");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL; // To avoid garbage values

    return newNode;
}

/**
 * Traverse linked list
 * 
 * @param node Starting node of the Linked List
 */
void traverse(Node* node) {
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

/**
 * Find lowest value in linked list
 * 
 * @param node Starting node
 * @returns Lowest value in the linked list
 */
int findLowestVal(Node* node) {
    int lowestValue = node->data;
    node = node->next;
    
    while (node) {
        if (node->data < lowestValue) {
            lowestValue = node->data;
        }
        node = node->next;
    }

    return lowestValue;
}

/**
 * Delete a node
 * 
 * @param head Pointer of the head node of the linked list
 * @param nodeToDelete Pointer of the node to be deleted
 * @returns Pointer to new head of the linked list
 */
Node* deleteNode(Node* head, Node* nodeToDelete) {
    // If the node to delete is a head
    if (head == nodeToDelete) {
        Node* newHead = head->next;
        free(head);
        return newHead;
    }

    // Traverse to the previous node of the nodeToDelete
    Node* currentNode = head;
    while (currentNode->next && currentNode->next != nodeToDelete) {
        currentNode = currentNode->next;
    }

    // If the while loop ended without finding the nodeToDelete
    if (currentNode->next == NULL) {
        return head;
    }

    // Point previous node's 'next' to the node after the one being deleted.
    currentNode->next = (currentNode->next)->next;
    free(nodeToDelete);

    return head;

    
}

/**
 * Insert new node
 * 
 * Will raise an error if `at` is larger than the available nodes - 1
 * 
 * @param head Pointer to head of the linked list
 * @param node Pointer to new node
 * @param at Position to insert (first = 0)
 * 
 * @returns Updated head (pointer)
 */
Node* insertNode(Node* head, Node* nodeToInsert, int at) {
    // Insert at the beginning
    if (at == 0) {
        nodeToInsert->next = head;
        return nodeToInsert;
    }
    
    Node* currentNode = head;
    for (int i = 0; i < at - 1; ++i) {
        // If `at` is larger than available nodes - 1
        currentNode = currentNode->next;
        if (!currentNode) {
            printf("Linked list has no such position\n");
            exit(1);
        }
    }

    nodeToInsert->next = currentNode->next;
    currentNode->next = nodeToInsert;

    return head;
}

// Testing
int main() {
    Node* node1 = createNode(20);
    Node* node2 = createNode(18);
    Node* node3 = createNode(6);
    Node* node4 = createNode(23);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Test Traverse
    printf("Linked list: ");
    traverse(node1);

    // Test Find lowest value
    printf("Lowest value: ");
    int i = findLowestVal(node1);
    printf("%d\n", i);

    // Test deleting node
    Node* newHeadNode = deleteNode(node1, node3);
    printf("Linked list after deleting node3: ");
    traverse(newHeadNode);

    // Test inserting a node
    Node* newNode = createNode(14);
    Node* newHeadNode2 = insertNode(newHeadNode, newNode, 3);
    printf("Linked list after inserting node(14): ");
    traverse(newHeadNode2);

    // This works for this specific case. But it's recommended.
    // Use a dedicated function to free the list.
    free(node1);
    free(node2);
    // free(node3); // This is already freed when deleting the node
    free(node4);
    free(newNode);

    return 0;
}
