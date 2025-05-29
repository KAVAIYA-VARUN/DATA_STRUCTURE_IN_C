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
    printf("\nenter the position of the elemet which you want to delete:");
    scanf("%d",&pos);
    if(pos<1 || pos>size)
    {
        printf("invalid position");
    }
    for(i=size;i>=pos-1;i--)
    {
        arr[pos-1] = arr[pos];
        pos++;
    }
    size--;
    printf("the array elements after deleting an element\n");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}