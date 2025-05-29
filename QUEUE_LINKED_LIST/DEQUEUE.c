#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};
struct node* front = 0;
struct node* rear = 0;

void enqueue(int data);
void print_queue();
int dequeue();
void peek();
void delel(int el);

int main()
{
	int choice,data,el;
	while(1)
	{
		printf("\nenter 1 to insert an element in the queue\nenter 2 to print the elements in the queue\nenter 3 to delete an element\nenter 4 to check the first element of the queue\nenter 5 to check the deleted element\nenter 6 to exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			enqueue(data);
			break;
		case 2:
			print_queue();
			break;
		case 3:
			el = dequeue();
			break;
		case 4:
			peek();
			break;
		case 5:
			delel(el);
			break;
		case 6:
			exit(1);
		default:
			printf("wrong choice\n");
	    }
	}
	return 0;
}

void enqueue(int data)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	printf("enter the data of the node:");
	scanf("%d",&data);
	new->info = data;
	new->link = NULL;
	if(front == 0 && rear ==0)
	{
		front = rear = new;
	}
	else
	{
		rear->link = new;
		rear = new;
	}
}

void print_queue()
{
	struct node* ptr = front;
	printf("the elements in the queue are\n");
    while(ptr!=0)
    {
    	printf("%d",ptr->info);
    	ptr = ptr->link;
	}
}
int dequeue()
{
	int h;
	struct node* ptr = front;
	if(front == NULL)
	{
		printf("the queue is empty\n");
		exit(1);
	}
	else
	{
		h = front->info;
		front = front->link;
		free(ptr);
		ptr = NULL;
	}
    return h;
}
void peek()
{
	struct node* ptr = front;
	printf("the first node of the list = %d",ptr->info);
}

void delel(int el)
{
	printf("the deleted element = %d",el);
}
