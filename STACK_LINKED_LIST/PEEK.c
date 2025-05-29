#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* link;
} *top = NULL;

void push(int data);
void peek();

int main()
{
    int data,choice=1;
    {
        while(choice==1)
        {
            printf("enter 1 to push an element into the stack\nenter 0 to check the topmost element in the stack");
            scanf("%d",&choice);
            if(choice==0)
            {
                break;
            }
            push(data);
        }
    }
    peek();
    return 0;
}

void push(int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&data);
    new->info = data;
    new->link = top;
    top = new;
}

void peek()
{
    if(top==0)
    {
        printf("the stack is empty");
    }
    else
    {
        printf("the topmost element in the stack = %d",top->info);
    }
}