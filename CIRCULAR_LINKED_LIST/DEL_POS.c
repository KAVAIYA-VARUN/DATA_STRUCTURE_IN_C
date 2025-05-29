#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* link;
};

struct node* create_list(struct node* head, int size);
void print_list(struct node* head);
struct node* del_begin(struct node* head);
struct node* del_pos(struct node* head, int pos);

int main()
{
    int size,pos;
    struct node* head = (struct node*)malloc(sizeof(struct node));
    printf("enter the size of the list:");
    scanf("%d",&size);
    head = create_list(head,size);
    printf("the list before altering\n");
    print_list(head);
    head = del_pos(head,pos);
    printf("the list after deleting the node at specific position\n");
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

struct node* del_begin(struct node* head)
{
    struct node* ptr = head;
    struct node* tail;
    struct node* temp = NULL;
    while(ptr->link!=head)
    {
        ptr = ptr->link;
    }
    tail = ptr;
    ptr = temp;
    ptr = head;
    {
        head = head->link;
        free(ptr);
        ptr = NULL;
        tail->link = head;
    }
    return head;
    
}

struct node* del_pos(struct node* head, int pos)
{
    struct node* ptr = head;
    int count = 0;
    while(ptr->link!=head)
    {
        ptr = ptr->link;
        count++;
    }
    count++;
    struct node* prev = head;
    printf("\nenter the position of the node which you want to delete:");
    scanf("%d",&pos);
    if(pos<1 || pos>count)
    {
        printf("invalid position\n");
    }
    else if(pos==1)
    {
        head = del_begin(head);
    }
    else
    {
        int i = 1;
        while(i<pos-1)
        {
            prev = prev->link;
            i++;
        }
        ptr = prev->link;
        prev->link = ptr->link;
    }
    return head;
}


