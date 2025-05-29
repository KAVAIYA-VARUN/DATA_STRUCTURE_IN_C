#include<stdio.h>

int main()
{
	int arr[50],size,i,j,temp;
	printf("enter the size of the array:");
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		printf("the data of [%d]:",i);
		scanf("%d",&arr[i]);
	}
	printf("\nthe array before sorting\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	
	for(i=0;i<size;i++)
	{
		int min = i;
		for(j=i+1;j<size;j++)
		{
			if(arr[j]<arr[min])
			{
				min = j;
			}
			if(min!=i)
			{
				temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;
				
			}
		}
	}
	printf("\nsorted array\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
