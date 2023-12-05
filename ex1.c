#include <stdio.h>

// Dinh nghia ham de quy in ra so tu start den end
void printNumbers(int start, int end)
{
    if (start <= end)
    {
        printf("%d ", start);
        printNumbers(start + 1, end); // Goi de quy de in so tiep theo
    }
}

int main()
{
    int start = 1;
    int end = 100;
    //hien thi ket qua
    printf("Cac so tu %d den %d:\n", start, end);
    printNumbers(start, end);

    return 0;
}
