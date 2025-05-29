#include<stdio.h>

int main()
{
    int size,i,n,pos;
    printf("enter the size of the array");
    scanf("%d",&size);
    int arr[size];
    printf("enter the elements in the array\n");
    for(i=0;i<size;i++)
    {
        printf("arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    printf("\n=========\n");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nenter the position where you want to add an element:");
    scanf("%d",&pos);
    if(pos<1 || pos>size)
    {
        printf("invalid position\n");
    }
    printf("enter the new element of the array:");
    scanf("%d",&n);
    size++;
    for(i=size;i>=pos-1;i--)
    {
        arr[i+1] = arr[i];
    }
    arr[pos-1] = n;
    printf("the array elements after adding new element\n");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}