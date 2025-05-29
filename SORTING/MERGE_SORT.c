#include<stdio.h>

void divide(int arr[],int lb,int ub);
void mergesort(int arr[],int lb,int mid,int ub);

int main()
{
    int arr[100];
    int size,i,lb,ub,loc;
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

    divide(arr,lb,ub);
    printf("Sorted Array\n");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

void divide(int arr[],int lb,int ub)
{
    int mid;
    if(lb<ub)
    {
        mid = (lb + ub) / 2;
        divide(arr,lb,mid);
        divide(arr,mid+1,ub);
        mergesort(arr,lb,mid,ub);
    }
}

void mergesort(int arr[],int lb,int mid,int ub)
{
    int merged_array[ub+1];
    int idx1 = lb;
    int idx2 = mid + 1;
    int x = lb;
    int i;
    int j;

    while(idx1 <= mid && idx2 <= ub)
    {
        if(arr[idx1]<=arr[idx2])
        {
            merged_array[x] = arr[idx1];
            x++;
            idx1++;
        }
        else
        {
            merged_array[x] = arr[idx2];
            x++;
            idx2++;
        }
    }
    if(idx1 > mid)
    {
        while(idx2 <= ub)
        {
            merged_array[x] = arr[idx2];
            x++;
            idx2++;
        }
    }
    else
    {
        while(idx1 <= mid)
        {
            merged_array[x] = arr[idx1];
            x++;
            idx1++;
        }
    }
    for(i=lb;i<ub+1;i++)
    {
        arr[i] = merged_array[i];
    }
}