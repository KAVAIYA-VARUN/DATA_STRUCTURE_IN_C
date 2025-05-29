#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
void count_of_nodes(struct node *head);

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

    count_of_nodes(head);
    return 0;
}
    void count_of_nodes(struct node *head)
    {
        int count = 0;
        if(head == NULL)
        {
            printf("the list is empty");
        }
        struct node *ptr = NULL;
        ptr = head;
        
        while(ptr!=NULL)
        {
            count++;
            ptr = ptr->link;
        }
        printf("number of nodes in the linked list is %d",count);
    }
    
