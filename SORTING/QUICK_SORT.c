#include<stdio.h>

int partition(int arr[],int lb, int ub);
void quicksort(int arr[],int lb,int ub);
void swap(int *a, int *b);

int main()
{
    int arr[5];
    int size,i,lb,ub,start,end,pivot,loc;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    printf("Enter the elements of the array\n");
    for(i=0;i<size;i++)
    {
        printf("data[%d]:",i);
        scanf("%d",&arr[i]);
    }
    printf("Array elements in unsorted form\n");
    for(i=0;i<size;i++)
    {
        printf("data[%d] = %d\n",i,arr[i]);
    }
    lb = 0;
    ub = (size-1);
    quicksort(arr,lb,ub);
    printf("Sorted array\n");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

void quicksort(int arr[],int lb,int ub)
{
    int loc;
    if(lb<ub)
    {
        loc = partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
    }
}

int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[lb],&arr[end]);
    return end;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}