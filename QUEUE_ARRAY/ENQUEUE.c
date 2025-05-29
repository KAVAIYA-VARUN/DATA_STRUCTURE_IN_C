#include<stdio.h>
#include<stdlib.h>

#define max 5
int queue_array[max];
int front = -1, rear = -1;
void insert(int data);
void print_queue(int data);
void print_front(int data);

int main()
{
	int choice,data;
	while(1)
	{
		printf("\n enter 0 to print the elements in the queue\nenter 1 to insert the element in the queue\nenter 2 to print the front element\nenter 3 to exit\n");
		scanf("%d",&choice);
	    switch(choice)
	    {
	    	case 0:
	    		print_queue(data);
	    	case 1:
	    		insert(data);
	    		break;
	    	case 2:
	    		print_front(data);
	    		break;
	    	case 3:
	    		exit(1);
	    	default:
	    		printf("wrong choice");
		}
	}
	
	return 0;
}

void insert(int data)
{
	if(rear == max - 1)
	{
		printf("the queue is full\n");
	}
	else
	{
		if(front == -1)
		{
			front = 0;
		}
		rear++;
		printf("\nenter the data of the element:");
		scanf("%d",&data);                       
		queue_array[rear] = data;
	}
}

void print_queue(int data)
{
	int i;
	if(front == -1)
	{
		printf("\nthe queue is empty\n");
	}
	else
	{
		printf("the elements in the queue are\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d",queue_array[i]);
		}
	}
}

void print_front(int data)
{
	front = 0;
	printf("the front element = %d",queue_array[front]);
}
