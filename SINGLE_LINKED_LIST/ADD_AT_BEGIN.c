#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node* add_at_begin(struct node *head, int info);

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->info = 45;
    head->link = NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr->info = 55;
    ptr->link = NULL;

    head->link = ptr;

    int info = 3; 
    head = add_at_begin(head, info);

    ptr = head;
    int i = 1;
    while(ptr!=0)
    {
        printf("the data of node[%d] = %d\n",i,ptr->info);
        i++;
        ptr = ptr->link;
    }

    return 0;
}

struct node* add_at_begin(struct node *head, int info)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->info = info;
    ptr->link = NULL;

    ptr->link = head;
    head = ptr;
    return head;
}