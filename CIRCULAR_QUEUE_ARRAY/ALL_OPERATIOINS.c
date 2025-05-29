#include<stdio.h>
#include<stdlib.h>

#define max 5
int queue_array[max];
int front = -1, rear = -1;
void insert(int data);
void print_queue(int data);
void peek();
int dequeue();
void delel(int el);

int main()
{
	int choice,data,el,h;
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
	    		el = dequeue();
	    		break;
	    	case 4:
	    		delel(el);
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
	if(front == -1 && rear == -1)
	{
		front = rear = 0;
		printf("\nenter the  data of the element:");
		scanf("%d",&data);
		queue_array[rear] = data;
	}
	else if(((rear+1)%max) == front)
	{
		printf("the queue is full\n");
	}
	else
	{
		rear = (rear+1) % max;
		printf("\nenter the data of the element:");
		scanf("%d",&data);
		queue_array[rear] = data;
	}
}

void print_queue(int data)
{
	int i = front;
	if(front == -1)
	{
		printf("\nthe queue is empty\n");
	}
	else
	{
		printf("the elements in the queue are\n");
		while(i!=rear)
		{
			printf("%d",queue_array[i]);
			i = (i+1) % max;
		}
		printf("%d",queue_array[rear]);
	}
}

void peek()
{
	printf("the front element = %d",queue_array[front]);
}

int dequeue()
{
	int h;
	
	if(front == -1 && rear == -1)
	{
		printf("the queue is empty\n");
	}
	else if(front == rear)
	{
		front = rear = -1;
	}
	else
	{
		h = queue_array[front];
		front = (front+1)%max;
	}
	return h;
}

void delel(int el)
{
	printf("the deleted element = %d",el);
}
