#include <stdio.h>
#include <stdlib.h>

struct MobilePhone {
    int mobile_id;
    char model[100];
    float price;
    int quantity;
};

void displayAllProducts() {
    FILE *file = fopen("mobile_data.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    struct MobilePhone product;
    printf("Mobile ID | Model | Price\n");
    while (fread(&product, sizeof(struct MobilePhone), 1, file)) {
        printf("%9d | %s | %.2f\n", product.mobile_id, product.model, product.price);
    }

    fclose(file);
}

void reportSoldProducts(int id) {
    FILE *sourceFile = fopen("mobile_data.txt", "r");
    if (sourceFile == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    FILE *reportFile = fopen("baocao_sanpham.txt", "w");
    if (reportFile == NULL) {
        printf("Khong the tao hoac mo file baocao_sanpham.txt.\n");
        fclose(sourceFile);
        return;
    }

    struct MobilePhone product;
    while (fread(&product, sizeof(struct MobilePhone), 1, sourceFile)) {
        if (product.mobile_id == id) {
            fprintf(reportFile, "Mobile ID: %d | Model: %s | Price: %.2f\n", product.mobile_id, product.model, product.price);
        }
    }

    fclose(sourceFile);
    fclose(reportFile);
}

void reportTotalSoldProducts() {
    FILE *sourceFile = fopen("mobile_data.txt", "r");
    if (sourceFile == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    int totalProducts = 0;
    float totalRevenue = 0;

    struct MobilePhone product;
    while (fread(&product, sizeof(struct MobilePhone), 1, sourceFile)) {
        totalProducts += product.quantity;
        totalRevenue += product.quantity * product.price;
    }

    printf("Tong so san pham ban duoc: %d\n", totalProducts);
    printf("Tong doanh thu: %.2f\n", totalRevenue);

    fclose(sourceFile);
}

int main() {
    int choice;
    int id;

    do {
        printf("\n----------- Mobile Phone Shop ---------\n");
        printf("=======================================\n");
        printf("1. Hien thi tat ca san pham\n");
        printf("2. Bao cao san pham da ban duoc\n");
        printf("3. Tong so san pham ban duoc theo mobile_id\n");
        printf("4. Tong tat ca san pham ban duoc\n");
        printf("0. Exit\n");
        printf("#Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAllProducts();
                break;
            case 2:
                printf("Nhap mobile_id: ");
                scanf("%d", &id);
                reportSoldProducts(id);
                printf("Da luu bao cao san pham da ban duoc vao baocao_sanpham.txt.\n");
                break;
            case 3:
                reportTotalSoldProducts();
                break;
            case 0:
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 0);

    return 0;
}
