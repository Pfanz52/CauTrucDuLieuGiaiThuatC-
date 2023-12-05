//Viết một chương trình sử dụng hàng đợi để chứng minh hệ thống xếp hàng (nhận hàng đợi
//Các con số được sử dụng trong bệnh viện, ngân hàng, ...).

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Define a structure for the queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Initialize the queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Enqueue an element to the queue
void enqueue(struct Queue* q, int value) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Dequeue an element from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    struct QueueNode* temp = q->front;
    int value = temp->data;

    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
    }

    free(temp);
    return value;
}

// Function to get a queue number
int getQueueNumber(struct Queue* q) {
    static int queueNumber = 1;
    enqueue(q, queueNumber);
    return queueNumber++;
}

int main() {
    struct Queue q;
    initQueue(&q);

    int choice, queueNumber;

    do {
        printf("\nMenu:\n");
        printf("1. Get Queue Number\n");
        printf("2. Serve Next Customer\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                queueNumber = getQueueNumber(&q);
                printf("You got queue number %d.\n", queueNumber);
                break;
            case 2:
                if (!isEmpty(&q)) {
                    int served = dequeue(&q);
                    printf("Serving customer with queue number %d.\n", served);
                } else {
                    printf("No customers in the queue.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
