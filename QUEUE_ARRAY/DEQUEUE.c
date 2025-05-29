#include<stdio.h>
#include<stdlib.h>

#define max 5
int queue_array[max];
int front = -1, rear = -1;
void insert(int data);
void print_queue(int data);
void peek();
void dequeue();
void delel();

int main()
{
	int choice,data;
	while(1)
	{
		printf("\nenter 0 to print the elements in the queue\nenter 1 to insert the element in the queue\nenter 2 to print the front element\nenter 3 to delete an element\nenter 4 to check the deleted element\nenter 5 to exit\n");
		scanf("%d",&choice);
	    switch(choice)
	    {
	    	case 0:
	    		print_queue(data);
	    		break;
	    	case 1:
	    		insert(data);
	    		break;
	    	case 2:
	    		peek();
	    		break;
	    	case 3:
	    		dequeue();
	    		break;
	    	case 4:
	    		delel();
	    		break;
	    	case 5:
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
		printf("\nthe queue is full\n");
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

void peek()
{
	printf("the front element = %d",queue_array[front]);
}

void dequeue()
{
	if(front == -1 && rear == -1)
	{
		printf("the queue is empty\n");
	}
	else
	{
		front++;
	}
}

void delel()
{
	printf("the deleted element = %d",queue_array[front]);
	front++;
}
