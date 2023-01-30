#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node* next;
}node;

node* insert(node* front,node* rear)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->next = front;//extra
    printf("Enter the value to insert: ");
    scanf("%d",&new_node->info);
    if(rear == NULL)
    {
        rear = new_node;
        new_node->next = new_node;//extra
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
    return rear;
}

node* delete(node* front,node* rear)
{
    if(front == NULL)
        printf("Queue is Empty\n");
    else
    {
        node* temp = front;
        printf("deleting element %d\n",front->info);
        if(front->next == front)
        {
            front = NULL;
        }
        else
        {
            front=front->next;
            rear->next = front;
        }
        free(temp);
    }
    return front;
}

void display(node* front, node* rear)
{
    if(front == NULL)
        printf("Queue is Empty\n");
    else
    {
        printf("%d,",front->info);
        node* temp = front;
        front=front->next;
        while(front!=temp)
        {
            printf("%d,",front->info);
            front=front->next;
        }
    }
}
int main()
{
    node* front = NULL;
    node* rear = NULL;
    int choice,flag=0;
    while(1)
    {
        printf("Options:\n");
        printf("1.insert\n");//imp
        printf("2.delete\n");//imp
        printf("3.display\n");//imp
        printf("4.exit\n");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        printf("\n");

        switch(choice)
        {
            case 1:
                rear = insert(front,rear);
                if(flag==0)
                    front=rear;
                flag=1;
                break;
            case 2:
                front = delete(front,rear);
                if(front == NULL)
                {
                    rear = NULL;
                    flag=0;
                }
                break;
            case 3:
                display(front,rear);
                break;
            case 4: exit(0);
            default:
                printf("\twrong input\n");
        }
    }
    return 0;
}