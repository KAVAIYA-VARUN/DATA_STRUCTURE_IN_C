#include<stdio.h>

int main()
{
	int arr[50],temp,size,i,j,count;
	printf("enter the size of the array:");
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		printf("the data of [%d]:",i);
		scanf("%d",&arr[i]);
	}
	printf("the array before sorting\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	for(i=0;i<size-1;i++)
	{
		count = 0;
		for(j=0;j<size-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				count = 1;
			}
		}
		if(count == 0)
		{
			break;
		}
	}
	printf("\nsorted array\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
