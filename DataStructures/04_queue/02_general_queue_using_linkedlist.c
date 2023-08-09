#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node* next;
}node;

node* insert(node* rear)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->next = NULL;
    printf("Enter the value to insert: ");
    scanf("%d",&new_node->info);
    if(rear == NULL)
        rear = new_node;
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
    return rear;
}

node* delete(node* front)
{
    if(front == NULL)
        printf("Queue is Empty\n");
    else
    {
        node* temp = front;
        printf("deleting element %d\n",front->info);
        front = front->next;
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
        while(front!=NULL)
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
                rear = insert(rear);
                if(flag==0)
                    front=rear;
                flag=1;
                break;
            case 2:
                front = delete(front);
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