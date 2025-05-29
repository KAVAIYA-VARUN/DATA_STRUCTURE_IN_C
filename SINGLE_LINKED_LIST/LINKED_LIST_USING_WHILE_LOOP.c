#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* link;
};

struct node* create_list(struct node* head);
void print_list(struct node* head);
void print_head(struct node* head);

int main()
{
    struct node* head = NULL;
    int n;
    while(1)
    {
        printf("1] to insert the node in the list\n");
        printf("2] to print all the elements in the list\n");
        printf("3] to print the data of the head node\n");
        printf("4] to exit\n");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
            head = create_list(head);
            break;

            case 2:
            print_list(head);
            break;
            
            case 3:
            print_head(head);
            break;

            case 4:
            exit(1);

            default:
            printf("invalid choice\n");
            exit(1);
        }
    }
    return 0;
}

void print_list(struct node* head)
{
    struct node* ptr = head;
    int i = 1;
    if(ptr == NULL)
    {
        printf("the list is empty\n");
    }
    while(ptr!=NULL)
    {
        printf("data of node[%d] = %d\n",i,ptr->info);
        i++;
        ptr = ptr->link;
    }
}

struct node* create_list(struct node* head)
{
    int data;
    {
        struct node* new = (struct node*)malloc(sizeof(struct node));
        if(head == NULL)
        {
            printf("enter the data of the head node:");
            scanf("%d",&data);
            new->info = data;
            new->link = NULL;
            head = new;
        }
        else
        {
            struct node* ptr = head;
            while(ptr->link!=NULL)
            {
                ptr = ptr->link;
            }
            printf("enter the data of the node:");
            scanf("%d",&data);
            new->info = data;
            ptr->link = new;
            new->link = NULL;
            ptr = new;
        }
    }
    return head;
}

void print_head(struct node* head)
{
    struct node* ptr = head;
    printf("the data of the head node = %d\n",ptr->info);
}