/*Write a program to perform basic operations with binary trees such as adding, searching,
deleting, and displaying elements in a binary tree.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollnumber;
    char studentname[50];
    char phonenumber[20];
};

struct TreeNode {
    struct Student data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

TreeNode* createNode(struct Student data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, struct Student data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data.rollnumber < root->data.rollnumber) {
        root->left = insert(root->left, data);
    } else if (data.rollnumber > root->data.rollnumber) {
        root->right = insert(root->right, data);
    }

    return root;
}

TreeNode* search(TreeNode* root, char name[50]) {
    if (root == NULL || strcmp(name, root->data.studentname) == 0) {
        return root;
    }

    if (strcmp(name, root->data.studentname) < 0) {
        return search(root->left, name);
    }

    return search(root->right, name);
}

void inOrder(TreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("Roll Number: %d, Name: %s, Phone Number: %s\n", 
               root->data.rollnumber, root->data.studentname, root->data.phonenumber);
        inOrder(root->right);
    }
}

void quickSort(struct Student arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high].rollnumber;
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j].rollnumber < pivot) {
                i++;
                struct Student temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        struct Student temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sortStudents(TreeNode* root, struct Student arr[], int* index) {
    if (root != NULL) {
        sortStudents(root->left, arr, index);
        arr[(*index)++] = root->data;
        sortStudents(root->right, arr, index);
    }
}

int main() {
    TreeNode* root = NULL;

    while (1) {
        printf("==============================\n");
        printf("Student Management System\n");
        printf("==============================\n");
        printf("1. Add student\n");
        printf("2. Search by student name\n");
        printf("3. Sort by roll number\n");
        printf("4. Display all students\n");
        printf("5. Exit\n");
        printf("==============================\n");
        printf("Your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Student newStudent;
                printf("Enter Roll Number: ");
                scanf("%d", &newStudent.rollnumber);
                printf("Enter Student Name: ");
                scanf(" %[^\n]s", newStudent.studentname);
                printf("Enter Phone Number: ");
                scanf(" %[^\n]s", newStudent.phonenumber);
                root = insert(root, newStudent);
                break;
            }
            case 2: {
                char name[50];
                printf("Enter Student Name to Search: ");
                scanf(" %[^\n]s", name);
                TreeNode* result = search(root, name);
                if (result != NULL) {
                    printf("Roll Number: %d, Name: %s, Phone Number: %s\n", 
                           result->data.rollnumber, result->data.studentname, result->data.phonenumber);
                } else {
                    printf("Student not found.\n");
                }
                break;
            }
            case 3: {
                int index = 0;
                struct Student students[100];
                sortStudents(root, students, &index);
                quickSort(students, 0, index - 1);
                printf("Students sorted by roll number:\n");
                for (int i = 0; i < index; i++) {
                    printf("Roll Number: %d, Name: %s, Phone Number: %s\n", 
                           students[i].rollnumber, students[i].studentname, students[i].phonenumber);
                }
                break;
            }
            case 4: {
                printf("List of all students:\n");
                inOrder(root);
                break;
            }
            case 5: {
                // Free allocated memory for tree nodes (optional, but recommended)
                // Code for freeing memory goes here if needed
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}
