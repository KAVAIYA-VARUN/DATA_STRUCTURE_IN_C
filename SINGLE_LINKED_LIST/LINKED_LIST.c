#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

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

    

    return 0;
}