#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node* create_list(struct node *head, int size);
void print_list(struct node *head);
struct node* ins_order(struct node* head);

int main()
{
    int size,n;
    printf("enter the size of linked list you want to create\nenter the data in ascending order");
    scanf("%d",&size);
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head = create_list(head,size);
    printf("the elements of the list are\n");
    print_list(head);
    printf("enter 1 to insert element in the list\nenter 0 to exit\n");
    scanf("%d",&n);
    if(n==1)
    {
        head = ins_order(head);
    }
    else
    {
        exit(1);
    }
    printf("the list after altering\n");
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
    int i =1;
    struct node *ptr = NULL;
    ptr = head;
    while(ptr!=0)
    {
        printf("the data of node[%d] = %d\n",i,ptr->info);
        i++;
        ptr = ptr->link;
    }
}

struct node* ins_order(struct node* head)
{
    int data;
    struct node* ptr = head;
    struct node* ptr2 = NULL;
    struct node* new = (struct node*)malloc(sizeof(struct node));
    printf("enter the data of new node:");
    scanf("%d",&data);
    new->info = data;
    new->link = NULL;
    if(head == NULL || new->info < head->info)
    {
        new->link = head;
        head = new;
    }
    else
    {
    while(ptr->info<=new->info && ptr->link!=NULL)
    {
        ptr2 = ptr;
        ptr = ptr->link;
    }
    if(ptr->link==NULL)
    {
        ptr->link = new;
        new->link = NULL;
    }
    else
    {
        ptr2->link = new;
        new->link = ptr;
    }
    }
    return head;
}