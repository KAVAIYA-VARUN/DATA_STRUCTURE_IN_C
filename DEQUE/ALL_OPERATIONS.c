#include<stdio.h>
#include<stdlib.h>

#define max 5
int deque[max];
int front = -1, rear = -1;
void insertfront(int data);
void deletefront();
void insertrear(int data);
void deleterear();
void print_deque(int data);
void print_front(int data);
void print_rear(int data);

int main()
{
	int choice,data;
	while(1)
	{
		printf("\nenter 1 to insert from front\nenter 2 to insert from rear\nenter 3 to delete from front\nenter 4 to delete from rear\nenter 5 to print the elements in the que\nenter 6 to print the front element\nenter 7 to print the rear element\nenter 8 to exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			insertfront(data);
			break;
		case 2:
			insertrear(data);
			break;
		case 3:
			deletefront();
			break;
		case 4:
			deleterear();
			break;
		case 5:
			print_deque(data);
			break;
		case 6:
			print_front(data);
			break;
		case 7:
			print_rear(data);
			break;
		case 8:
			exit(1);
		default:
			printf("wrong choice\n");
		}
	}
	return 0;
}

void insertfront(int data)
{
	if((front == 0 && rear == max-1) || (front == rear+1))
	{
		printf("the que is full\n");
	}
	else if(front == -1 && rear == -1)
	{
		front = rear = 0;
		printf("\nenter the data of the element:");
		scanf("%d",&data);
		deque[front] = data;
	}
	else if(front == 0)
	{
		front = max-1;
		printf("\n enter the data of the element:");
		scanf("%d",&data);
		deque[front] = data;
	}
	else
	{
		front--;
		printf("\nenter the data of the element:");
		scanf("%d",&data);
		deque[front] = data;
	}
}

void insertrear(int data)
{
	if((front == 0 && rear == max-1) || (front == rear+1))
	{
		printf("the que is full\n");
	}
	else if(front == -1 && rear == -1)
	{
		front = rear = 0;
		printf("\nenter the data of the element:");
		scanf("%d",&data);
		deque[rear] = data;
	}
	else if(rear == max-1)
	{
		rear = 0;
		printf("\nenter the data of the element:");
		scanf("%d",&data);
		deque[rear] = data;
	}
	else
	{
		rear++;
		printf("\nenter the data of the element:");
		scanf("%d",&data);
		deque[rear] = data;
	}
}

void print_deque(int data)
{
	int i = front;
	printf("\n the elements of the que are\n");
	while(i!=rear)
	{
		printf("%d",deque[i]);
		i = (i+1) % max;
	}
	printf("%d",deque[rear]);
}

void print_front(int data)
{
	printf("\nthe front element = %d",deque[front]);
}

void print_rear(int data)
{
	printf("\nthe rear element = %d",deque[rear]);
}

void deletefront()
{
	if(front == -1 && rear == -1)
	{
		printf("\nthe que is empty\n");
	}
	else if(front == rear)
	{
		front = rear = -1;
	}
	else if(front == max-1)
	{
		front = 0;
	}
	else
	{
		front++;
	}
}

void deleterear()
{
	if(front == -1 && rear == -1)
	{
		printf("\nthe que is empty\n");
	}
	else if(front == rear)
	{
		front = rear = -1;
	}
	else if(rear == 0)
	{
		rear =  max - 1;
	}
	else
	{
		rear--;
	}
}
