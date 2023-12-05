#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MobilePhone {
    int mobile_id;
    char model[100];
    float price;
    struct MobilePhone* next;
};

struct MobilePhone* head = NULL;

void addMobilePhone(int id, char model[], float price) {
    struct MobilePhone* newMobile = (struct MobilePhone*)malloc(sizeof(struct MobilePhone));
    newMobile->mobile_id = id;
    strcpy(newMobile->model, model);
    newMobile->price = price;
    newMobile->next = head;
    head = newMobile;
    
}

struct MobilePhone* searchMobileByID(int id) {
    struct MobilePhone* current = head;
    while (current != NULL) {
        if (current->mobile_id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void updateMobileByID(int id) {
    struct MobilePhone* current = head;
    while (current != NULL) {
        if (current->mobile_id == id) {
            char newModel[100];
            float newPrice;

            printf("Enter new model: ");
            scanf("%s", newModel);
            printf("Enter new price: ");
            scanf("%f", &newPrice);

            strcpy(current->model, newModel);
            current->price = newPrice;

            printf("Mobile phone with ID %d updated successfully.\n", id);
            return;
        }

        current = current->next;
    }

    printf("Mobile phone with ID %d not found.\n", id);
}

void deleteMobilePhoneByID(int id) {
    struct MobilePhone* current = head;
    struct MobilePhone* prev = NULL;

    while (current != NULL) {
        if (current->mobile_id == id) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("Mobile phone with ID %d deleted successfully.\n", id);
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Mobile phone with ID %d not found.\n", id);
}

void swap(struct MobilePhone* a, struct MobilePhone* b) {
    struct MobilePhone temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MobilePhone arr[], int N, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left].price > arr[largest].price)
        largest = left;

    if (right < N && arr[right].price > arr[largest].price)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(struct MobilePhone arr[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int partition(struct MobilePhone arr[], int low, int high) {
    struct MobilePhone pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].price > pivot.price) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(struct MobilePhone arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayAllMobilePhones() {
    int numPhones = 0;
    struct MobilePhone* current = head;
    while (current != NULL) {
        numPhones++;
        current = current->next;
    }

    if (numPhones == 0) {
        printf("No mobile phones available.\n");
        return;
    }

    struct MobilePhone* mobiles = (struct MobilePhone*)malloc(sizeof(struct MobilePhone) * numPhones);
    current = head;

    for (int i = 0; i < numPhones; i++) {
        mobiles[i] = *current;
        current = current->next;
    }

    quickSort(mobiles, 0, numPhones - 1);

    printf("All Mobile Phones:\n");
    for (int i = 0; i < numPhones; i++) {
        printf("Mobile ID: %d, Model: %s, Price: %.2f $\n", mobiles[i].mobile_id, mobiles[i].model, mobiles[i].price);
    }

    free(mobiles);
}

void displayTop5HighestPriceMobilePhones() {
    if (head == NULL) {
        printf("No mobile phones available.\n");
        return;
    }

    int numPhones = 0;
    struct MobilePhone* current = head;
    while (current != NULL) {
        numPhones++;
        current = current->next;
    }

    if (numPhones < 5) {
        printf("There are less than 5 mobile phones available.\n");
        return;
    }

    struct MobilePhone* mobiles = (struct MobilePhone*)malloc(sizeof(struct MobilePhone) * numPhones);
    current = head;

    for (int i = 0; i < numPhones; i++) {
        mobiles[i] = *current;
        current = current->next;
    }

    heapSort(mobiles, numPhones);

    printf("Top 5 Highest Priced Mobile Phones:\n");
    for (int i = numPhones - 1; i >= numPhones - 5; i--) {
        printf("Mobile ID: %d, Model: %s, Price: %.2f $\n", mobiles[i].mobile_id, mobiles[i].model, mobiles[i].price);
    }

    free(mobiles);
}

void saveToFile() {
    FILE *file;
    file = fopen("mobile_data.txt", "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct MobilePhone* current = head;
    while (current != NULL) {
        fprintf(file, "%d %s %.2f\n", current->mobile_id, current->model, current->price);
        current = current->next;
    }

    fclose(file);
    printf("Mobile data saved to file successfully.\n");
}

void loadFromFile() {
    FILE *file;
    file = fopen("mobile_data.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int id;
    char model[100];
    float price;

    while (fscanf(file, "%d %s %f", &id, model, &price) == 3) {
        addMobilePhone(id, model, price);
    }

    fclose(file);
    printf("Mobile data loaded from file successfully.\n");
}

int main() {
    

    int choice;
    do {
        printf("\n----------- Mobile Phone Shop ---------\n");
        printf("=======================================\n");
        printf("1. Add mobile phone\n");
        printf("2. Search mobile phone\n");
        printf("3. Update mobile\n");
        printf("4. Delete mobile phone\n");
        printf("5. Shop reports\n");
        printf("0. Exit\n");
        printf("#Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int id;
                char model[100];
                float price;

                printf("Enter mobile ID: ");
                scanf("%d", &id);
                printf("Enter model: ");
                scanf("%s", model);
                printf("Enter price: ");
                scanf("%f", &price);

                addMobilePhone(id, model, price);
                saveToFile(); 
                printf("Mobile phone added successfully.\n");
                saveToFile();
                break;
            }
            case 2: {
                int id;
                printf("Enter mobile ID to search: ");
                scanf("%d", &id);

                struct MobilePhone* result = searchMobileByID(id);

                if (result != NULL) {
                    printf("Mobile ID: %d, Model: %s, Price: %.2f\n", result->mobile_id, result->model, result->price);
                } else {
                    printf("Mobile phone with ID %d not found.\n", id);
                }

                break;
            }
            case 3: {
                int id;
                printf("Enter mobile ID to update: ");
                scanf("%d", &id);
                updateMobileByID(id);
                saveToFile(); 
                break;
            }
            case 4: {
                int id;
                printf("Enter mobile ID to delete: ");
                scanf("%d", &id);
                deleteMobilePhoneByID(id);
                saveToFile(); 
                break;
            }
            case 5: {
                int reportChoice;
                do {
                    printf("\n----------- Mobile Phone Shop ---------\n");
                    printf("=======================================\n");
                    printf("Shop Reports\n");
                    printf("1. Display all mobile phones\n");
                    printf("2. Display top 5 highest price mobile phones\n");
                    printf("0. Back to main menu\n");
                    printf("#Choose: ");
                    scanf("%d", &reportChoice);

                    switch (reportChoice) {
                        case 1:
                            displayAllMobilePhones();
                            break;
                        case 2:
                            displayTop5HighestPriceMobilePhones();
                            break;
                        case 0:
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (reportChoice != 0);
                break;
            }
            case 0:
                saveToFile(); 
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
