#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* link;
} *top = NULL;

void push(int data);
void pop();
void peek();

int main()
{
    int data,choice=1;
    {
        while(choice == 0 || choice == 1 || choice == 2)
        {
            printf("enter 0 to check the topmost element in the stack\nenter 1 to push an element into the stack\nenter 2 to pop an element from the stack\n");
            scanf("%d",&choice);
            if(choice==1)
            {
                push(data);
            }
         
            else if(choice==0)
            {
                peek();
            }
            else if(choice==2)
            {
                pop();
            }
            else
            {
                exit(1);
            }
        }
    }
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
        printf("the topmost element in the stack = %d\n",top->info);
    }
}
void pop()
{
    struct node* ptr = top;
    if(top==0)
    {
        printf("the stack is empty");
    }
    top = top->link;
    free(ptr);
    ptr = NULL;
}
