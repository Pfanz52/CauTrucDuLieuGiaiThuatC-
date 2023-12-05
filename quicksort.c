#include <stdio.h>
// Ham phan hoach LOMUTO : tra ve chi so cua khoa PIVOT
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
    // khi da duyet het day
    i++;
    int tmp = a[i];
    a[i] = a[r];
    a[r] = tmp;
    printf("Phan hoach tu phan tu chi so %d toi %d\n", l, r);
    for (int i = l; i < r; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return i;
}

//De quy giai quick sort
void quicksort(int a[],int l, int r)
{
    if(l<r)
    {
        int pos = partition(a,l,r);
        //De quy ssang trai
        quicksort(a,l,pos-1);
        //De quy sang phai
        quicksort(a,pos+1,r);
    }
}

int main()
{
    int n;
    printf("\nNhap kich thuoc cho mang: ");
    scanf("%d",&n);
    
    int a[n];
    printf("\nNhap day so can sap xep.\n");
    for(int i =0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("\nAfter QUICK SORT\n");
    for(int i =0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}