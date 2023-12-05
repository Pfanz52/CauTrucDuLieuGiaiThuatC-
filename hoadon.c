#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for Order
struct Order {
    char customer_name[100];
    char phone_number[15];
    int product_id;
    char product_name[100];
    float product_price;
    float total_payment;
    char date_time[20];
    struct Order* next;
};

// Global head pointer for the linked list
struct Order* head = NULL;

void saveToFile(char* fileName, char* data) {
    FILE* file = fopen(fileName, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "%s\n", data);
    fclose(file);
}

// Function to create a new order and add it to the linked list
void createOrder() {
    struct Order* newOrder = (struct Order*)malloc(sizeof(struct Order));

    printf("Enter customer name: ");
    scanf(" %[^\n]s", newOrder->customer_name);

    printf("Enter phone number: ");
    scanf("%s", newOrder->phone_number);

    printf("Enter product ID: ");
    scanf("%d", &newOrder->product_id);

    printf("Enter product name: ");
    scanf(" %[^\n]s", newOrder->product_name);

    printf("Enter product price: ");
    scanf("%f", &newOrder->product_price);

    printf("Enter total payment: ");
    scanf("%f", &newOrder->total_payment);

    printf("Enter date time of payment (dd/mm/yyyy hh:mm): ");
    scanf("%s", newOrder->date_time);

    // Set the next pointer to the current head
    newOrder->next = head;

    // Update head to point to the new order
    head = newOrder;

    printf("\nOrder created successfully.\n");

    // Save customer information to file
    char customerInfo[256];
    sprintf(customerInfo, "%s,%s,%d,%s,%.2f,%.2f,%s",
            newOrder->customer_name, newOrder->phone_number, newOrder->product_id,
            newOrder->product_name, newOrder->product_price, newOrder->total_payment,
            newOrder->date_time);
    saveToFile("khachhang.txt", customerInfo);
}

// Function to display all orders
void displayAllOrders() {
    struct Order* current = head;

    while (current != NULL) {
        printf("\nOrder Details:\n");
        printf("Customer Name: %s\n", current->customer_name);
        printf("Phone Number: %s\n", current->phone_number);
        printf("Product ID: %d\n", current->product_id);
        printf("Product Name: %s\n", current->product_name);
        printf("Product Price: %.2f\n", current->product_price);
        printf("Total Payment: %.2f\n", current->total_payment);
        printf("Date Time of Payment: %s\n", current->date_time);

        // Move to the next order
        current = current->next;
    }
}

int main() {
    int choice;

    do {
        printf("\n----------- Order Management System ---------\n");
        printf("=============================================\n");
        printf("1. Create Order\n");
        printf("2. Display All Orders\n");
        printf("0. Exit\n");
        printf("#Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createOrder();
                break;
            case 2:
                displayAllOrders();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    // Clean up memory (optional)
    struct Order* current = head;
    while (current != NULL) {
        struct Order* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
