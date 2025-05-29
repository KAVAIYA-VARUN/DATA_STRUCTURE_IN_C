#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node* create_list(struct node *head, int size);
void print_list(struct node *head);
struct node* add_at_start(struct node *head, int data);
struct node* add_at_last(struct node *head, int data);
struct node* add_at_pos(struct node *head, int data, int pos);

int main()
{
    int size,data,pos,count;
    int choice,n;
    printf("enter the size of linked list you want to create:");
    scanf("%d",&size);
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head = create_list(head,size);
    printf("the list before altering the list\n\n");
    print_list(head);

    printf("\nenter 1 if you want to alter the list\nenter 2 if you dont want to alter the list\n\n");
    scanf("%d",&choice);

    if(choice==1)
    {
        printf("\nenter 1 to add at start:\nenter 2 to add at end:\nenter 3 to add at any position:");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
            head = add_at_start(head,data);
            printf("\nthe list after entering the node at start\n");
            print_list(head);
            break;

            case 2:
            head = add_at_last(head,data);
            printf("\nthe list after entering the node at last\n");
            print_list(head);
            break;

            case 3:
            head = add_at_pos(head, data, pos);
            printf("\nthe list after entering the node at any position\n");
            print_list(head);
        }

    }
    else
    {
        printf("the list without alteration is\n");
        print_list(head);
    }
    
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
            printf("enter the data of node:");
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
            printf("enter the data of node:");
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

struct node *add_at_start(struct node *head, int data)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    printf("\nenter the data of first node:");
    scanf("%d",&data);
    new->info = data;
    new->link = head;
    head = new;
    return head;
}

struct node *add_at_last(struct node *head, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    printf("\nenter the data of the last node:");
    scanf("%d",&data);
    new->info = data;
    new->link = NULL;

    struct node *ptr2;
    ptr2 = head;
    while(ptr2->link!=NULL)
    {
        ptr2 = ptr2->link;
    }
    ptr2->link = new;
    return head;
}

struct node* add_at_pos(struct node* head, int data, int pos)
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
        printf("enter the position of node where you want to insert\n");
        scanf("%d",&pos);
        
        if(pos>count)
        {
            printf("invalid node position\n\nthe original list is:\n");
        }
        ptr = head;
        if(pos==1)
        {
            struct node* new = (struct node*)malloc(sizeof(struct node));
            printf("enter the data of the node:");
            scanf("%d",&data);
            new->info = data;
            new->link = head;
            head = new;
            return head;
        }
        else
        {
            ptr = head;
            int i = 1;
            while(i<pos-1)
            {
                ptr = ptr->link;
                i++;
            }
            struct node* new = (struct node*)malloc(sizeof(struct node));
            printf("enter the data of the node:");
            scanf("%d",&data);
            new->info = data;
            new->link = ptr->link;
            ptr->link = new;
        }
        return head;
    }
    
