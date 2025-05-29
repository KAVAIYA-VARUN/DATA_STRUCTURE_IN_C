#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* link;
};

struct node* create_list(struct node* head, int size);
void print_list(struct node* head);
struct node* add_at_end(struct node* head);

int main()
{
    int size;
    struct node* head = (struct node*)malloc(sizeof(struct node));
    printf("enter the size of the list:");
    scanf("%d",&size);
    head = create_list(head,size);
    printf("the list before altering\n");
    print_list(head);
    printf("\nthe list after adding node at end\n");
    head = add_at_end(head);
    print_list(head);
    return 0;
}

struct node* create_list(struct node* head, int size)
{
    int i,data;
    struct node* ptr;
    for(i=0;i<size;i++)
    {
        if(i==0)
        {
            printf("enter the data of the node:");
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
            printf("enter the data of the node:");
            scanf("%d",&data);
            current->info = data;
            ptr->link = current;
            current->link = NULL;
            ptr = current;      
        } 
        ptr->link = head;   
    }
    return head;
}

void print_list(struct node* head)
{
    struct node* ptr = head;
    int i = 1;
    while(ptr->link!=head)
    {
        printf("the data of node[%d] = %d\n",i,ptr->info);
        ptr = ptr->link;
        i++;
    }
    printf("the data of node[%d] = %d",i,ptr->info);
}

struct node* add_at_end(struct node* head)
{
    int data;
    struct node* ptr = head;
    while(ptr->link!=head)
    {
        ptr = ptr->link;
    }
    struct node* new = (struct node*)malloc(sizeof(struct node));
    printf("enter the data of the node:");
    scanf("%d",&data);
    new->info = data;
    new->link = head;
    ptr->link = new;
    return head;
}