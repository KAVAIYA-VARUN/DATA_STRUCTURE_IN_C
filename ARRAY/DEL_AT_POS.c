#include<stdio.h>

int main()
{
    int a[50],i,n,pos=1,data;

    printf("enter the size of array:");
    scanf("%d",&n);
    if(n>50)
    {
        printf("overflow condition\n");
    }
    else
    {
        for(i=0;i<n;i++)
            {
                printf("a[%d]:",i);
                scanf("%d",&a[i]);
            }
            printf("the array without altering\n");
        for(i=0;i<n;i++)
            {
                printf("a[%d] = %d\n",i,a[i]);
                pos++;
            }
    }

    printf("enter the position of the element which you want to delete:");
    scanf("%d",&pos);
    if(pos<0 || pos>n+1)
    {
        printf("invalid position");
    }
    else
    {

        for(i=(pos-1);i<n;i++)
            {
                a[i] = a[i+1];
            }
            n--;
        printf("the array after altering\n");
        for(i=0;i<n;i++)
            {
                printf("a[%d] = %d\n",i,a[i]);
            }
    }
    return 0;    
}