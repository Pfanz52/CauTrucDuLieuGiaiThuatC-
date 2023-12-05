#include <stdio.h>
#include <stdlib.h>

//    1. Insert Book
//    2. Search Book By ISBN
//    3. Delete Book By ISBN
//    4. Display All Books
// cau truc bookstore
typedef struct Bookstore
{
    unsigned int isbn;
    char title[50];
    // char author[50];
    // float price;
} book;

// Nhap thong tin cac cuon sach
// book nhap()
// {
//     book n;
//     printf("Nhap Ma So ISBN: ");
//     scanf("%lu", &n.isbn);
//     getchar();
//     printf("nhap Ten Sach: ");
//     gets(n.title);
//     printf("nhap Ten Tac Gia: ");
//     // gets(n.author);
//     // printf("Nhap gia cuon sach: ");
//     // scanf("%f", &n.price);

//     return n;
// }
// // xuat ra man hinh
// void in(book n)
// {
//     printf("\n%lu %s", n.isbn, n.title);
// }

// Tao mot node moi
struct node
{
    book data;
    struct node *next;
};
typedef struct node node;
//con tro head
node*head=NULL;

node *makeNode(unsigned int isbn, char*title )
{
    // cap phat dong 1 node
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data.isbn = isbn;
    strcpy(newNode->data.title,title);
    newNode->next = NULL;
    return newNode;
}

// Duyet DSLK
void duyet(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
// Dem so node
int size(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

// Them vao dau DSLK
void pushfront(node **head, int x)
{
    node *newNode = makeNode(x);
    newNode->next = (*head);
    (*head) = newNode;
    return;
}

// Them node vao cuoi DSLK
void pushback(node **head, int x)
{
    node *newNode = makeNode(x);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    node *tmp = *head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

// Them node vao vi tri k trong DSLK
void insert(node **head, int k, int x)
{
    int n = size(*head);
    if (k < 1 || k > n + 1)
        return;
    // {
    //     printf("vi tri chen khong hop le!\n");
    //     return;
    // }
    if (k == 1)
    {
        pushfront(head, x);
    }
    else if (k == n + 1)
    {
        pushback(head, x);
    }
    else
    {
        node *temp = (*head);
        for (int i = 1; i < k - 1; i++)
        {
            temp = temp->next;
        }
        node *newNode = makeNode(x);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Xoa node khoi dau DSLK
void popfront(node **head)
{
    if (*head == NULL)
        return;
    node *tmp = *head;
    *head = tmp->next;
    free(tmp);
}

// xoa node khoi cuoi DSLK
void popback(node **head)
{
    if (*head == NULL)
        return;
    node *tmp = *head;
    if (tmp->next == NULL)
    {
        *head = NULL;
        free(tmp);
        return;
    }
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    node *last = tmp->next;
    tmp->next = NULL;
    free(last);
}

// xoa node o vi tri k trong DSLK
void erase(node **head, int k)
{
    int n = size(*head);
    if (k < 1 || k > n)
        return;
    if (k == 1)
        popfront(head);
    else
    {
        node *truoc = *head;
        node *sau = *head;
        for (int i = 1; i <= k - 1; i++)
        {
            sau = truoc;
            truoc = truoc->next;
        }
        sau->next = truoc->next;
        free(truoc);
    }
}

// Tim node thu k trong DSLK
void kthNode(node *head, int pos)
{
    int n = size(head);
    if (pos < 1 || pos > n)
    {
        printf("Vi tri khong hop le !\n");
        return;
    }
    node *temp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        temp = temp->next;
    }
    printf("%d ", temp->data);
}

void menu()
{
    printf("\n===============================\n");
    printf("\nMENU OF BOOKSTORE\n");
    printf("===============================\n");
    printf("         Bookstore\n");
    printf("===============================\n");
    printf("1. Insert Book\n");
    printf("2. Search Book By ISBN\n");
    printf("3. Delete Book By ISBN\n");
    printf("4. Display All Books\n");
    printf("5. Exit\n");
    printf("===============================\n");
    printf("Your choice:\n");
};
int main()
{
    int m;
    printf("nhap so luong cuon sach: \n");
    scanf("%d", &m);
    // getchar();
    book a[m];
    for (int i = 0; i < m; i++)
    {
        getchar();
        a[i] = nhap();
    }

    node *head = NULL;
    pushfront(&head, 100);
    pushfront(&head, 200);
    pushfront(&head, 300);
    // pushfront(&head, 2);
    // pushback(&head, 10);
    // insert(&head, 2, 22);
    duyet(head);
    menu();
    int choice;
    do
    {

        printf("\nYour choice <1/2/3/4/5>: ");
        scanf("%d", &choice);
        // system("cls");
        // getchar();
        switch (choice)
        {
        case 1:
            printf("\n1\n");
            pushfront(&head, 1);
            pushfront(&head, 2);
            pushback(&head, 10);
            insert(&head, 2, 22);
            duyet(head);

            break;

        case 2:
            printf("\n2\n");
            kthNode(head, 2);

            break;

        case 3:
            printf("\n3\n");
            popfront(&head);
            popback(&head);
            erase(&head, 2);
            duyet(head);

            break;

        case 4:
            printf("\n4\n");
            duyet(head);
            break;

        case 5:
            printf("\n5\n");
            getchar();
            break;
        default:
            printf("\nLet's choice another <1/2/3/4/5>.\n");
        }
    } while (choice != 5);

    return 0;
}