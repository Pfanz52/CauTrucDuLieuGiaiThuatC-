//Sử dụng ngăn xếp để viết một chương trình nhập 10 số nguyên và hiển thị 
#include <stdio.h>

void nhap_va_hien_thi_10_so() {
    int stack[10];
    int top = -1; // Khoi tao dinh ngan xep

    // Nhap 10 so nguyen tu nguoi dung
    for (int i = 0; i < 10; i++) {
        printf("Nhap so thu %d: ", i+1);
        scanf("%d", &stack[++top]); // Them so vao ngan xep va tang dinh
    }

    // Hien thi cac so nguyen da nhap
    printf("ngan xep 10 so nguyen la:\n");
    while (top >= 0) {
        printf("| %d |\n", stack[top--]); // In so va giam dinh
    }
    printf("____");
}

int main() {
    nhap_va_hien_thi_10_so();
    return 0;
}
