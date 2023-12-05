#include <stdio.h>

// Định nghĩa hàm đệ quy để tính tổng của cấp số cộng
int sumOfAP(int a, int d, int n)
{
    if (n == 1)
    {
        return a; // Điểm dừng của đệ quy, trả về phần tử đầu tiên
    }
    else
    {
        return a + sumOfAP(a + d, d, n - 1); // Gọi đệ quy để tính tổng phần tử tiếp theo
    }
}

int main()
{
    // int a = 2; // Phần tử đầu tiên
    // int d = 3; // Hiệu d
    // int n = 5; // Số phần tử trong cấp số cộng
    int a, d, n;
    scanf("%d%d%d", &a, &d, &n);

    int sum = sumOfAP(a, d, n);
    printf("Tong CSC: %d\n", sum);

    return 0;
}
