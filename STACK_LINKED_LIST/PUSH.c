#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* link;
} *top = NULL;

void push(int data);
void print_stack();

int main()
{
    int data,choice=1;
    {
        while(choice==1)
        {
            printf("enter 1 to push an element into the stack\nenter 0 to exit");
            scanf("%d",&choice);
            if(choice==0)
            {
                break;
            }
            push(data);
        }
    }
    printf("the elements in the stack are\n");
    print_stack();
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

void print_stack()
{
    struct node* ptr = top;
    if(top==0)
    {
        printf("stack is empty");
    }
    else
    {
        while(top!=NULL)
        {
            printf("%d\n",ptr->info);
            ptr = ptr->link;
        }
    }
}