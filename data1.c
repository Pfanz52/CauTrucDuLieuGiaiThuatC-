#include <stdio.h>
unsigned long fibonacci(unsigned int index);//goi ham in ra day so fibonacci
int main(int count, char *args[])
{
    unsigned int num;
    int i;
    printf("Input number of fibonacci series: ");//nhap do lon cua day so fibonacci
    scanf("%d", &num);
    printf("Fibonacci series: ");//hien thi day so fibonacci
    for (i = 1; i <= num; i++)
    {
        printf("%lu ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
unsigned long fibonacci(unsigned int index)//dinh nghia ham 
{
   
    if (index == 1)
    {
        return 0;
    }
    else if (index == 2)
    {
        return 1;
    }
    return fibonacci(index - 1) + fibonacci(index - 2);//dung ham de quy in ra so tiep theo trong day fibonacci
}