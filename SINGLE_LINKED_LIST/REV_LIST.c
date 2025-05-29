#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node* create_list(struct node *head, int size);
void print_list(struct node *head);
struct node* rev_list(struct node *head,int size);

int main()
{
    int size;
    printf("enter the size of linked list you want to create:");
    scanf("%d",&size);
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head = create_list(head,size);
    print_list(head);
    head = rev_list(head,size);
    printf("the list after reversing it\n");
    print_list(head);
    return 0;
}

struct node* create_list(struct node *head, int size)
{
    int data,i;
    struct node* ptr;
    for(i=0;i<size;i++)
    {
        if(i==0)
        {
            printf("enter the data:");
            scanf("%d",&data);
            head->info = data;
            if(size==1)
            {
                head->link = NULL;
            }
            ptr = head;
        }
        else
        {
            struct node* current = (struct node*)malloc(sizeof(struct node));
            printf("enter the data:");
            scanf("%d",&data);
            current->info = data;
            ptr->link = current;
            current->link = NULL;
            ptr = ptr->link;// it can also be written as ptr = current
        }
    }
    return head;
}

void print_list(struct node *head)
{ 
    int i = 1;
    struct node *ptr = NULL;
    ptr = head;
    while(ptr!=0)
    {
        printf("the data of node[%d] = %d\n",i,ptr->info);
        i++;
        ptr = ptr->link;
    }
}

struct node* rev_list(struct node* head, int size)
{
    struct node* current = head;
    struct node* previous = 0;
    struct node* next = head;

    while(next!=0)
    {
        next = next->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    head = previous;
    return head;
}