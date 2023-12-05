#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    int data[50];
    int max;
    int top;
};

typedef struct Stack Stack;

void createEmptyStack(Stack *s)
{
    s->top = -1;
}

bool push(Stack *stack, int value)
{
    if (stack->top == stack->max)
    {
        return false;
    }
    stack->top += 1;
    stack->data[stack->top] = value;
    return true;
}

bool pop(Stack *stack, int *topValue)
{
    if (stack->top < 0)
    {
        return false;
    }
    *topValue = stack->data[stack->top];
    stack->top -= 1;
    return true;
}

bool peek(Stack stack, int *topValue)
{
    if (stack.top < 0)
    {
        return false;
    }
    *topValue = stack.data[stack.top];
    return true;
}

bool isFull(Stack stack)
{
    return stack.top == stack.max;
}

bool isEmpty(Stack stack)
{
    return stack.top < 0;
}

struct Queue
{
    int *data;
    int maxSize;
    int front;
    int rear;
};

bool enqueue(struct Queue *queue, int rearValue)
{
    if (queue->rear == queue->maxSize - 1)
    {
        if (queue->front == 0)
        {
            return false;
        }
        else if (queue->front > 0)
        {
            for (int i = 0, j = queue->front; j <= queue->rear; i++, j++)
            {
                queue->data[i] = queue->data[j];
            }
            queue->rear -= queue->front;
            queue->front = 0;
        }
    }
    queue->rear += 1;
    queue->data[queue->rear] = rearValue;
    return true;
}

bool dequeue(struct Queue *queue, int *frontValue)
{
    if (queue->rear < queue->front)
    {
        return false;
    }
    *frontValue = queue->data[queue->front];
    queue->front += 1;
    return true;
}

bool initQueue(struct Queue *queue, int maxSize)
{
    queue->maxSize = maxSize;
    queue->data = (int *)malloc(maxSize * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    return true;
}

// bool peek(struct Queue queue, int *frontValue)
// {
//     if (isEmpty(queue))
//     {
//         return false;
//     }
//     *frontValue = queue.data[queue.front];
//     return true;
// }

// bool isFull(struct Queue queue)
// {
//     return queue.rear == queue.maxSize - 1;
// }

// bool isEmpty(struct Queue queue)
// {
//     return queue.rear < queue.front;
// }

int main()
{
    Stack s;
    createEmptyStack(&s);

    struct Queue q;
    initQueue(&q, 50);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);
    enqueue(&q, 80);

    int topValue;
    pop(&s, &topValue);
    printf("Top value of stack: %d\n", topValue);

    int frontValue;
    dequeue(&q, &frontValue);
    printf("Front value of queue: %d\n", frontValue);

    return 0;
}
