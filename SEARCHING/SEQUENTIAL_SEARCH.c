#include<stdio.h>

int main()
{
	int arr[50],i,n,size,found = 0,temp;
	printf("enter the size of the array:");
	scanf("%d",&size);
	printf("\nenter the elements of the array\n");
	
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("\nenter the element whose index you want to check:");
	scanf("%d",&n);
	
	for(i=0;i<size;i++)
	{
		if(arr[i] == n)
		{
			found = 1;
			temp = i;
		}
	}
	if(found == 1)
	{
		printf("\nthe index of the element = %d",temp);
	}
	else
	{
		printf("\ninvalid element\n");
	}
	return 0;
}
