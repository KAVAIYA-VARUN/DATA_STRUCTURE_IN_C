#include<stdio.h>
#define max 4

int stack_arr[max];
int top = -1;
void push(int data);
void print_stack(int data);

int main()
{
    int choice=1,data;
    
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