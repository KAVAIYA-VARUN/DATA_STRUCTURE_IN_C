#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

void add_at_end(struct node *head,int info);
void print_info(struct node *head);

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->info = 45;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->info = 95;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->info = 105;
    current->link = NULL;
    head->link->link = current;
    
    add_at_end(head, 100);
    print_info(head);

    return 0;
}
   

void add_at_end(struct node *head,int info)
{
    struct node *ptr,*temp;
    ptr = head;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->info = info;
    temp->link = NULL;
    
    while(ptr->link!=NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void print_info(struct node *head)
{
    struct node *ptr = NULL;
    ptr = head;
    int i=1;
    while(ptr!=0)
    {
        printf("the info of the node[%d] is %d\n",i,ptr->info);
        ptr = ptr->link;
        i++;
    }
}