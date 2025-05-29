#include<stdio.h>
#include<stdlib.h>

#define max 5

int stack_s1[max],stack_s2[max];
int top1 = -1, top2 = -1;
int count = 0;

void enqueue(int data);
void print_queue(int data);
void push1(int data);
void dequeue();
void push2(int data);
int pop1();
int pop2();

int main()
{
	int choice,data;
	while(1)
	{
		printf("\nenter 0 to exit\nenter 1 to insert an element in the queue\nenter 2 to print the elements in the queue\nenter 3 to delete an element\n");	
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				exit(1);
			case 1:
				enqueue(data);
				break;
			case 2:
				print_queue(data);
				break;
			case 3:
				dequeue();
				break;
			default:
				printf("wrong choice\n");
		}
	}
	return 0;
}

void push1(int data)
{
	if(top1 == max-1)
	{
		printf("\nthe queue is full\n");
	}
	else
	{
		top1++;
		stack_s1[top1] = data;
	}
}

void enqueue(int data)
{
	printf("\nenter the data of the  element:");
	scanf("%d",&data);
	push1(data);
	count++;
}

void print_queue(int data)
{
	int i;
	printf("the elements in the queue are\n");
	for(i=top1;i>=0;i--)
	{
		printf("%d\n",stack_s1[i]);
	}
}

void dequeue()
{
	int i,el1,del;
	if(top1 == -1 && top2 == -1)
	{
		printf("the queue is empty\n");
	}
	else
	{
		for(i=0;i<count;i++)
		{
			el1 = pop1();
			push2(el1);
		}
		del = pop2();
		count--;
		for(i=0;i<count;i++)
		{
			el1 = pop2();
			push1(el1);
		}
	}
}

int pop1()
{
	return stack_s1[top1--];
}

void push2(int data)
{
	if(top2 == max-1)
	{
		printf("the queue is full\n");
	}
	else
	{
		top2++;
	    stack_s2[top2] = data;
	}
}

int pop2()
{
	return stack_s2[top2--];
}

