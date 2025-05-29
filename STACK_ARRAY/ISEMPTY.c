#include<stdio.h>
#include<stdlib.h>

#define max 4

int stack_arr[max];
int top = -1;
void push(int data);
int isempty();
void print_stack(int data);

int main()
{
    int choice=1,data;
    int n;
    while(choice==1)
    {
        printf("enter 1 to push the element in the stack\nenter 0 to exit");
        scanf("%d",&choice);
        if(choice==0)
        { 
            break;
        }
        push(data);
    }

    print_stack(data);
    return 0;
}

void push(int data)
{
    int element;
    if(top == max - 1)
    {
        printf("stack overflow");
        exit(1);
    }
    else
    {
        element = isempty();
        printf("stack underflow\n");
    }
    printf("enter the data of the element which you want to push:");
    scanf("%d",&data);
    top++;
    stack_arr[top] = data;
}

void print_stack(int data)
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("data = %d\n",stack_arr[i]);
    }
}

int isempty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
