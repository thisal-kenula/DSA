#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data; // value
    struct Node* next; // Pointer to next Node
} Node;

// Create a node and return pointer
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    // If memory allocation failed
    if (newNode == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL; // Remove garbage values

    return newNode;
}

// node: Pointer to starting node
void printList(Node* node)  {
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

typedef struct Stack {
    Node *head;
    int size; // Number of nodes
} Stack;

// Creates a new stack and returns its pointer
Stack* createStack() {
    // Allocate memory for new stack
    Stack* newStack = (Stack*) malloc(sizeof(Stack));

    if (newStack == NULL) {
        printf("Memory allocation for stack failed.");
        exit(1);
    }

    newStack->head = NULL;
    newStack->size = 0;

    return newStack;
}

/// @brief Checks if a stack is empty.
/// @param stack Pointer to the stack.
/// @return `1` if empty, `0` if not.
int isEmpty(const Stack* stack) {
    return stack->size == 0;
}

/// @brief Returns the pointer to top node of the stack.
/// @param stack Pointer to the stack.
/// @return Pointer to top node, or NULL if the stack is empty.
Node* peek(const Stack* stack) {
    return stack->head;
}

/// @brief Adds new node
/// Adds new node as the head node to the stack
/// @param stack  Pointer to the stack.
/// @param value value of the new node
void push(Stack* stack, int value) {
    Node* currentNode = createNode(value);
    currentNode->next = stack->head;
    stack->head = currentNode;
    ++stack->size;
}

/// @brief Removes and returns the top node of stack.  
/// Frees memory of the deleted node. Stack should be non-empty.
/// @param stack  Pointer to the stack.
/// @return Data of deleted node. Exits if stack is empty.
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Can't pop from an empty stack.");
        exit(1);
    } else {
        int headValue = stack->head->data;
        Node* newHead = stack->head->next;
        free(stack->head);
        stack->head = newHead;
        --stack->size;
        return headValue;
    }
}

/// @brief Free memory for the stack and nodes inside it.
/// @param stack Pointer to the stack.
void deleteStack(Stack* stack) {
    while (!isEmpty(stack)) pop(stack);
    free(stack);
}

// Testing
int main(){
    // Create stack
    Stack* myStack = createStack();
    
    // Push 
    push(myStack, 20);
    push(myStack, 18);
    push(myStack, 6);
    push(myStack, 23);
    
    // Pop
    int popped = pop(myStack);
    printf("Popped: %d\n", popped);

    // Peek
    if (peek(myStack)) { // If stack is not empty
        printf("%d\n", peek(myStack)->data);
    }

    // Free memory
    deleteStack(myStack);
}