#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* llink;
    struct node* rlink;
};

struct node* create_tree(struct node* root);
struct node* add_left_child(struct node* root);
struct node* add_right_child(struct node* root);
void preorder(struct node* root);
void inorder(struct node* root);
void postorder(struct node* root);
int count_nodes(struct node* root);
int sum_nodes(struct node* root);

int main()
{
    int n,nodes_count,nodes_sum;
    struct node* root = NULL;

    while(1)
    {
        printf("1] to insert the root in the tree\n");
        printf("2] to insert the left child\n");
        printf("3] to insert the right child\n");
        printf("4] to print the preorder traversal of the tree\n");
        printf("5] to print the inorder traversal of the tree\n");
        printf("6] to print the postorder traversal of the tree\n");
        printf("7] to print the number of nodes\n");
        printf("8] to print the sum of all the nodes\n");
        printf("9] to exit\n");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
            {
                if(root == NULL)
                {
                    root = create_tree(root);
                }
                else
                {
                    printf("root already exists\n");
                }
                break;
            }

            case 2:
            {
                if(root!=NULL)
                {
                    root = add_left_child(root);
                }
                else
                {
                    printf("create the root first\n");
                }
                break;
            }

            case 3:
            {
                if(root!=NULL)
                {
                    root = add_right_child(root);
                }
                else
                {
                    printf("create the root first\n");
                }
                break;
            }

            case 4:
            {
                printf("\nthe preorder traversal of the tree is given below\n\n");
                preorder(root);
                printf("\n\n");
                break;
            }

            case 5:
            {
                printf("\nthe inorder traversal of the tree is given below\n\n");
                inorder(root);
                printf("\n\n");
                break;
            }

            case 6:
            {
                printf("\nthe postorder traversal of the tree is given below\n\n");
                postorder(root);
                printf("\n\n");
                break;
            }
            case 7:
            {
                nodes_count = count_nodes(root);
                printf("The total number of nodes in the tree = %d\n",nodes_count);
                break;
            }
            case 8:
            {
                nodes_sum = sum_nodes(root);
                printf("The sum of all the nodes in the tree = %d\n",nodes_sum);
                break;
            }
            case 9:
            {
                exit(1);
            }

            default:
            printf("wrong choice enter again\n");
        }
    }
    return 0;
}

struct node* create_tree(struct node* root)
{
    int data;
    root = (struct node*)malloc(sizeof(struct node));
    printf("enter the data of the node:");
    scanf("%d",&data);
    root->info = data;
    root->llink = NULL;
    root->rlink = NULL;
    return root;
}

struct node* add_left_child(struct node* root)
{
    if(root->llink == NULL)
    {
        root->llink = create_tree(root);
    }
    else
    {
        add_left_child(root->llink);
    }
    return root;
}

struct node* add_right_child(struct node* root)
{
    if(root->rlink == NULL)
    {
        root->rlink = create_tree(root);
    }
    else
    {
        add_right_child(root->rlink);
    }
    return root;
}

void preorder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ",root->info);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

void inorder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->llink);
        printf("%d ",root->info);
        inorder(root->rlink);
    }
}

void postorder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d ",root->info);
    }
}

int count_nodes(struct node* root)
{
    struct node* ptr = root;
    int count = 0;
    int l,r;
    if(ptr == NULL)
    {
        return 0;
    }
    else
    {
        l = count_nodes(ptr->llink);
        r = count_nodes(ptr->rlink);
        return l+r+1;
    }
}
int sum_nodes(struct node* root)
{
    int sum = 0;
    int l,r;
    struct node* ptr = root;
    if(ptr == NULL)
    {
        return 0;
    }
    else
    {
        l = sum_nodes(ptr->llink);
        r = sum_nodes(ptr->rlink);
        return l+r+root->info;
    }
}