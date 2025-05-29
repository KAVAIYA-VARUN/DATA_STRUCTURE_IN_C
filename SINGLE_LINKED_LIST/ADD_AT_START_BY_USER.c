/*inserting an element by user at the beginning of existing linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node* add_at_start(struct node *head, int data);
void print_list(struct node* head);

int main()
{
    int data;
    struct node *head = malloc(sizeof(struct node));  
    head->info = 10;
    head->link = NULL;

    struct node *current = (struct node*)malloc(sizeof(struct node));
    current->info = 20;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->info = 30;
    current->link = NULL;
    head->link->link = current;

    printf("the list before adding the node at the beginning\n");
    print_list(head);

    printf("enter the info of first node:");
    scanf("%d",&data);

    printf("the list after adding the node at the beginning\n");

    head = add_at_start(head, data);
    print_list(head);

    return 0;
}

struct node* add_at_start(struct node *head, int data)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->info = data;
    ptr->link = head;
    head = ptr;
    return head;
}

void print_list(struct node* head)
{
    struct node *ptr;
    ptr = head;
    int i=1;
    while(ptr!=0)
    {
        printf("the data of node[%d] = %d\n",i,ptr->info);
        ptr = ptr->link;
        i++;
    }
}