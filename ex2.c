#include <stdio.h>
unsigned long fibonacci(unsigned int index);//goi ham in ra day so fibonacci
int main(int count, char *args[])
{
    unsigned int num;
    int i;
    printf("Input number of fibonacci series: ");
    scanf("%d", &num);//nhap vao do lon cua day so
    printf("Fibonacci series: ");
    for (i = 1; i <= num; i++)
    {
        printf("%lu ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
unsigned long fibonacci(unsigned int index)//ham de quy in ra day so fibonacci
{
    if (index == 1 || index == 2)
    {
        return 1;
    }
    return fibonacci(index - 1) + fibonacci(index - 2);//goi de quy in ra cac so tiep theo
}