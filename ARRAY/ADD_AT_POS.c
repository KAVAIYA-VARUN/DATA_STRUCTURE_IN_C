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

    printf("enter the postion where you want to add the element:");
    scanf("%d",&pos);
    if(pos<0 || pos>n+1)
    {
        printf("invalid position");
    }
    else
    {
        printf("enter the data of that element:");
        scanf("%d",&data);

        for(i=(n-1);i>=pos-1;i--)
            {
                a[i+1] = a[i];
            }
        a[pos-1] = data;
        n++;
        printf("the array after altering\n");
        for(i=0;i<n;i++)
            {
                printf("a[%d] = %d\n",i,a[i]);
            }
    }
    return 0;    
}