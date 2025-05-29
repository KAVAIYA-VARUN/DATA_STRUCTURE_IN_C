#include<stdio.h>
#include<stdlib.h>

#define max 4

int stack_arr[max];
int top = -1;
void push(int data);
int pop();
void print_stack(int data);

int main()
{
    int choice=1,data;
    int n;
    int del;
    while(choice==1)
    {
        printf("enter 1 to push the element in the stack\nnenter 0 to exit");
        scanf("%d",&choice);
        if(choice==0)
        { 
            break;
        }
        push(data);
    }

    print_stack(data);
    printf("enter 1 to pop the topmost element of the stack\nenter 0 to exit");
    scanf("%d",&n);
    if(n==1)
    {
        del = pop();
    }
    printf("stack after altering it\n");
    print_stack(data);
    return 0;
}

void push(int data)
{
    if(top == max-1)
    {
        printf("stack overflow");
        return;
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

int pop()
{
    int val;
    if(top==-1)
    {
        printf("underflow condition\n");
        exit(1);
    }
    val = stack_arr[top];
    top--;
    return val;
}