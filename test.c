#include <stdio.h>
int partition(int a[], int l, int r)
{
    int i = l - 1, pivot = a[r];
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    i++;
    int tmp = a[i];
    a[i] = a[r];
    a[r] = tmp;
    printf("\nPHAN HOACH TU CHI SO %d TOI %d\n", l, r);
    for (int i = l; i <= r; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return i;
}
// 7.1 DE QUY TIEP TUC QUICK SORT CHO DEN HET

void qsort(int a[], int l, int r)
{
    if (l < r)
    {
        int pos = partition(a, l, r);
        // DE QUY SNG TRAI
        qsort(a, l, pos - 1);
        // DE QUY SANG PHAI
        qsort(a, pos + 1, r);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}