#include <stdio.h>

// Hàm đệ quy để tính các số trong dãy cấp số cộng và tính tổng
void csc(int start, int cs, int n, int next, int sum)
// start so dau tien //cs la cong sai
// n la do dai csc //next so tiep theo
{
    if (n == 0)
    {
        return;
    }

    printf("%d ", next);
    csc(start, cs, n - 1, next + cs, sum + next);
}

int main()
{
    int start, cs, n;

    // Nhập số đầu tiên, công sstarti và độ dài củstart dãy cấp số công
    printf("nhap so dau tien: ");
    scanf("%d", &start);

    printf("nhap cong sai: ");
    scanf("%d", &cs);

    printf("nhap do lon cua day so: ");
    scanf("%d", &n);

    // Tạo mảng để lưu dãy số cấp số công
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = start + i * cs;
    }

    // Sắp xếp mảng theo chiều tăng dần
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // In rstart dãy số cấp số công đã sắp xếp
    printf("day so cap so cong (tang dan): ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nTong CSC: ");
    // int sum = (n * (2 * start + (n - 1) * cs)) / 2;
    int sum = n * start + (n * (n - 1) * cs) / 2;
    printf("%d\n", sum);

    return 0;
}
