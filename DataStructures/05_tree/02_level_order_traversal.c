#include<stdio.h>
#include<stdlib.h>
//implementation queue
#define max 100
typedef struct node
{
    int info;
    struct node* left;
    struct node* right;
}node;
void push(node* q[],int* rear,node* newnode)
{
    if((*rear)==max-1)
    {
        printf("Error: Queue Overflow\n");
        return;
    }
    q[(*rear)] = newnode;
    ++(*rear);
}
void pop(node* q[],int* front,int* rear)
{
    if(*front == *rear)
    {
        printf("Error: Queue underflow\n");
        return;
    }
    ++(*front);
}
void insert(node** root,int x)
{
    if(*root == NULL)
    {
        node* newnode = (node*) malloc(sizeof(node));
        newnode->left = NULL;
        newnode->right= NULL;
        newnode->info = x;
        *root = newnode;
    }
    else if((*root)->info<x)
    {
        insert(&((*root)->right),x);
    }
    else if((*root)->info>x)
    {
        insert(&((*root)->left),x);
    }
}
void bfs(node* root)
{
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    //queue
    node* q[max];
    int front=0,rear=0;
    push(q,&rear,root);
    while(front<rear)
    {
        int size = rear;
        // for(int i=front;i<size;i++)
        while(front<size)
        {
            node* obj = q[front];
            if(obj->left!=NULL) push(q,&rear,obj->left);
            if(obj->right!=NULL) push(q,&rear,obj->right);
            printf("%d ",obj->info);
            pop(q,&front,&rear);
        }
        printf("\n");
    }
}
int main()
{
    //insertion
    node* root=NULL;
    while(1)
    {
        printf("Options\n");
        printf("1. Insert\n");
        printf("2. bfs\n");
        printf("3. exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                {
                    int x;
                    scanf("%d",&x);
                    insert(&root,x);
                    break;
                }
            case 2:
                bfs(root);
                break;
            case 3:
                exit(0);
        }
    }
    return 0;
}
// One might wonder why pop() returns void, instead of value_type. That is, why must one use front()
//  and pop() to examine and remove the element at the front of the queue, instead of combining the
//   two in a single member function? In fact, there is a good reason for this design. If pop()
//    returned the front element, it would have to return by value rather than by reference: return 
//    by reference would create a dangling pointer. Return by value, however, is inefficient:
//     it involves at least one redundant copy constructor call. Since it is impossible for pop()
//      to return a value in such a way as to be both efficient and correct, it is more sensible 
//      for it to return no value at all and to require clients to use front()
//  to inspect the value at the front of the queue.