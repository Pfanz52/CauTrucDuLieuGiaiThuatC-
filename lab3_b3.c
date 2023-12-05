//DOI SO THAP PHAN SANG SO NHI PHAN
#include <stdio.h>

// Define a structure for the stack
struct Stack {
    int arr[100];
    int top;
};

// Initialize the stack
void init(struct Stack *s) {
    s->top = -1;
}

// Push an element onto the stack
void push(struct Stack *s, int value) {
    s->top++;
    s->arr[s->top] = value;
}

// Pop an element from the stack
int pop(struct Stack *s) {
    int value = s->arr[s->top];
    s->top--;
    return value;
}

// Function to convert decimal to binary using a stack
void decimalToBinary(int n) {
    struct Stack s;
    init(&s);

    while (n > 0) {
        int remainder = n % 2;
        push(&s, remainder);
        n /= 2;
    }

    // Pop elements from the stack to get the binary representation
    printf("Binary representation: ");
    while (s.top >= 0) {
        printf("%d", pop(&s));
    }
}

int main() {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);

    decimalToBinary(n);

    return 0;
}
