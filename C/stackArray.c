#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Number of integers to allocate for stack

typedef struct Stack {
    int data[MAX];
    int top; // last index
} Stack;

// Create a stack and return its Pointer
Stack* createStack() {
    // Allocate memory for the stack
    Stack* newStack = (Stack*) malloc(sizeof(Stack));

    // If memory allocation failed
    if (newStack == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }

    newStack->top = -1;
    return newStack;
}

// Add a new value to a stack
void push(Stack* stack, int value) {
    // If the stack size is at maximum
    if (stack->top >= MAX - 1) {
        printf("Can't add more elements to stack");
        exit(1);
    }

    // Increment the top index and add the new value to it
    stack->data[++stack->top] = value;
}

// Return the top value in stack
int peek(Stack* stack) {
    if (stack->top < 0) {
        printf("Stack is empty.");
        exit(1);
    }
    return stack->data[stack->top];
}

// Returns `1` if empty; 0 if not.
int isEmpty(Stack* stack) {
    return stack->top < 0;
}

// Returns the number of elements in the stack
int stackSize(Stack* stack) {
    return stack->top+1;
}

// Print the stack
// Prints `\n` if empty
void printStack(Stack* stack) {
    for (int i = 0; i < stack->top + 1; ++i){
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    // Create stack
    Stack* myStack = createStack();

    // Print whole stack
    printf("Stack: ");
    printStack(myStack);

    // IsEmpty
    printf("Is empty: %d\n", isEmpty(myStack));

    // Push
    push(myStack, 2);
    push(myStack, 10);
    push(myStack, 4);

    // Peek
    printf("Peek: %d\n", peek(myStack));

    // IsEmpty
    printf("Is empty: %d\n", isEmpty(myStack));

    // Size
    printf("Number of elements: %d\n", stackSize(myStack));

    // Print whole stack
    printf("Stack: ");
    printStack(myStack);
    
    // Free memory
    free(myStack);
    return 0;
}