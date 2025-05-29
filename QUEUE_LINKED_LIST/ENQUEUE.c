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

int main()
{
	int choice,data;
	while(1)
	{
		printf("\nenter 1 to insert an element in the queue\nenter 2 to print the elements in the queue\nenter 3 to exit\n");
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
