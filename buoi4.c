/*Write a program to perform basic operations with binary trees such as adding, searching,
deleting, and displaying elements in a binary tree.*/
#include <stdio.h>
#include <stdlib.h>
void menu()
{
    printf("MENU OF PROGRAM\n");
    printf("===========================\n");
    printf("Binary Search Tree Demo\n");
    printf("===========================\n");
    printf("1. Insert to tree\n");
    printf("2. Delete elements by value\n");
    printf("3. Display all elememts\n");
    printf("4. Search to key\n");
    printf("5. Exit\n");
    printf("===========================\n");
    printf("Your choice: \n");
    printf("\n");
}
// 1111111111111111111111111111111111111111111111111
struct node
{
    int key;
    struct node *left;
    struct node *right;
};

// 2222222222222222222222222222222222222222222222222
//  create a newnode
struct node *newNode(int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

// DUYET BINARY TREE
void inorder(struct node *root)
{
    if (root != NULL)
    {
        // duyet sang trai
        inorder(root->left);

        // duyet root
        printf("%d -> ", root->key);

        // duyet sang phai
        inorder(root->right);
    }
}

// Search tree
struct node *search(struct node *root, int key)
{
    if (root == NULL || root->key == key)
    {
        return root;
    }
    else if (key < root->key)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}
// 3333333333333333333333333333333333333333333333333
//  insert
struct node *insert(struct node *root, int key)
{
    // return a newnode if the tree is empty
    if (root == NULL)
        return newNode(key);

    // traverse to the right place and insert the node
    // tim dung noi de chen
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

/* Given a non-empty binary search tree, return the node with minimum
key value found in that tree. Note that the entire tree does not
need to be searched. */
struct node *minValueNode(struct node *root)
{
    struct node *current = root;
    // loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// 4444444444444444444444444444444444444444444444444
//  seach

// 5555555555555555555555555555555555555555555555555
//  delete
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;
    /*TH1:
    -IF THE KEY TO BE DELETED IS SMALLER THAN ROOT'S KEY
     -THEN IT IS LIES IN LEFT SUBTREE*/
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    /*TH2:
   -IF THE KEY TO BE DELETED IS GREATER THAN ROOT'S KEY
    -THEN IT IS LIES IN RIGHT SUBTREE*/
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    /*TH3:
        -IF THE KEY IS SAME AS ROOT'S KEY, THEN THIS IS NODE
         -TO BE DELETE*/
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        /*node with two child: get thr inorder successor (smallest in the right subtree)*/
        struct node *temp = minValueNode(root->right);
        // copy the inorder successor's content to this node
        root->key = temp->key;
        // delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// 6666666666666666666666666666666666666666666666666
//  display

int main()
{
    menu();
    struct node *root = NULL;
    int choice;
    int key;
    int searchkey;
    do
    {
        printf("\nLET'S CHOICE ONE FUNCTION <1/2/3/4/5>: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n1. INSERT\n");
            printf("\ninsert->key: ");
            scanf("%d", &key);
            root = insert(root, key);
            inorder(root);
            // printf("Inorder traversal: ");
            break;
        case 2:
            printf("\nDELETE TREE\n");
            printf("\nBINARY TPREE NOW\n");
            inorder(root);
            printf("\n");
            printf("\ninput delete->key: ");
            scanf("%d", &key);
            struct node *node = deleteNode(root, key);
            if (node != NULL)
            {
                printf("\nAFTER %d IS DELETED\n", key);
                root = deleteNode(root, key);
                inorder(root);
            }
            else
            {
                inorder(root);
                printf("\n%d key is not in insert.\n", key);
            }
            break;
        case 3:
            printf("\nDISPLAY ALL\n");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("\nSEARCH TREE\n");
            printf("\ninput search->key: ");
            scanf("%d", &searchkey);
            struct node *result = search(root, searchkey);
            if (result != NULL)
            {
                printf("\n%d FOUND in the tree\n", searchkey);
                inorder(root);
            }
            else
            {
                inorder(root);
                printf("\n%d is NOT found in the tree\n", searchkey);
            }
            break;
        case 5:
            printf("\nExit program\n");
            break;
        default:
            printf("\n INVALID CHOICE.\n PLEASE TRY AGAIN!.\n");
        }
    } while (choice != 5);
    free(root);
    return 0;
}