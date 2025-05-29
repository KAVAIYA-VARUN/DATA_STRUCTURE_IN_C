#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int info;
    struct node* llink;
    struct node* rlink;
};

struct node* create_list(struct node* head, int size);
void check_list(struct node* head);
struct node* del_pos(struct node* head, int pos);

int main()
{
    int size,data,pos,count;
    printf("enter the size of the linked list:");
    scanf("%d",&size);
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head = create_list(head,size);
    printf("the list before altering\n");
    check_list(head);
    printf("the list after deleting the first node\n");
    head = del_pos(head,pos);
    check_list(head);
    return 0;
}

void check_list(struct node* head)
{
    struct node* ptr = head;
    int i = 1;
    while(ptr!=0)
    {
        printf("the data of the node[%d] = %d\n",i,ptr->info);
        ptr = ptr->rlink;
        i++;
    }
}

struct node* create_list(struct node* head, int size)
{
    int i,data;
    struct node* temp;
    for(i=0;i<size;i++)
    {

        if(i==0)
        {
            printf("enter the data:");
            scanf("%d",&data);
            head->info = data;
            if(size==1)
            {
                head->llink = NULL;
                head->rlink = NULL;
            }    
            temp = head;
            temp->llink = NULL;
        }
        else
        {
            struct node* current = (struct node*)malloc(sizeof(struct node));
            printf("enter the data:");
            scanf("%d",&data);
            current->info = data;
            temp->rlink = current;
            current->llink = temp;
            current->rlink = NULL;
            temp = current;
        }
    }
    return head;


}

struct node* del_pos(struct node* head, int pos)
{
    struct node* ptr = head;
    struct node* prev = head;
    printf("enter the position of the node which you want to delete:");
    scanf("%d",&pos);
    if(pos==1)
    {
        ptr = ptr->rlink;
        free(head);
        ptr->llink = NULL;
        head = ptr;
        return head;
    }

    while(pos!=1)
    {
        prev = ptr;
        ptr = ptr->rlink;
        pos--;
    }
    if(ptr->rlink==NULL)
    {
        prev->rlink = NULL;
        return head;
    }
    else
    {
        prev->rlink = ptr->rlink;
        ptr->rlink->llink = prev;
        free(ptr);
        return head;
    }
}