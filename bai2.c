#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Book struct
typedef struct Book
{
    int isbn;
    char title[50];
} Book;

// Define Node struct
typedef struct Node
{
    Book book;
    struct Node *next;
} Node;

// Global variable for the linked list head
Node *head = NULL;

// Function to insert a book
void insertBook(int isbn, char *title)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->book.isbn = isbn;
    strcpy(newNode->book.title, title);
    newNode->next = head;
    head = newNode;
}

// Function to search a book by ISBN
Node *searchBookByISBN(int isbn)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->book.isbn == isbn)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a book by ISBN
void deleteBookByISBN(int isbn)
{
    Node *current = head;
    Node *prev = NULL;

    while (current != NULL)
    {
        if (current->book.isbn == isbn)
        {
            if (prev != NULL)
            {
                prev->next = current->next;
            }
            else
            {
                head = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to display all books
void displayAllBooks()
{
    Node *current = head;
    while (current != NULL)
    {
        printf("ISBN: %d, Title: %s\n", current->book.isbn, current->book.title);
        current = current->next;
    }
}

// Function to free memory used by linked list
void freeMemory()
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    int choice;
    int isbn;
    char title[50];

    do
    {
        printf("\n================================\n");
        printf("Bookstore Demo\n");
        printf("================================\n");
        printf("1. Insert Book\n");
        printf("2. Search Book By ISBN\n");
        printf("3. Delete Book By ISBN\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("================================\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter ISBN: ");
            scanf("%d", &isbn);
            printf("Enter Title: ");
            scanf(" %[^\n]s", title);
            insertBook(isbn, title);
            break;
        case 2:
            printf("Enter ISBN to search: ");
            scanf("%d", &isbn);
            Node *result = searchBookByISBN(isbn);
            if (result != NULL)
            {
                printf("Book Found - ISBN: %d, Title: %s\n", result->book.isbn, result->book.title);
            }
            else
            {
                printf("Book not found.\n");
            }
            break;
        case 3:
            printf("Enter ISBN to delete: ");
            scanf("%d", &isbn);
            deleteBookByISBN(isbn);
            break;
        case 4:
            displayAllBooks();
            break;
        case 5:
            freeMemory();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
