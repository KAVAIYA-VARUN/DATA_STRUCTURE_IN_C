#include<stdio.h>

int main()
{
	int arr[50],size,i,j,temp,n;
	printf("enter the size of the array:");
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		printf("enter the data of the element:");
		scanf("%d",&arr[i]);
	}
//	printf("\nthe array before sorting\n");
//	for(i=0;i<size;i++)
//	{
//		printf("%d ",arr[i]);
//	}
	
	for(i=0;i<size;i++)
	{
		int min = i;
		for(j=i+1;j<size;j++)
		{
			if(arr[min]>arr[j])
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
    printf("\nenter the element whose index you want to check:");
    scanf("%d",&n);
    int mid,found = 0,el;
	int l = 0, r = size - 1;
	while(l<=r)
	{
		mid = (l+r) / 2;
		if(arr[mid] == n)
		{
			found = 1;
			el = mid;
			break;
		}
		else if(arr[mid] < n)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	if(found == 1)
		{
			printf("\nthe index of the element = %d",el);
		}
		else
		{
			printf("\ninvalid element\n");
		}
	return 0;
}


