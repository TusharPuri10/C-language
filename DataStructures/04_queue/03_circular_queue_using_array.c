#include <stdio.h>
#include <stdlib.h>
#define max 5

int insert(int a[],int front,int rear)
{
    if((rear == max-1 && front==0)  || rear+1==front)
        printf("Overflow\n");
    else{
        if(rear==max-1)
            rear = 0;
        else
            ++rear;
        printf("Enter the value: ");
        scanf("%d",&a[rear]);
    }
    return rear;
}

int delete(int a[],int front,int rear)
{
    if(front == -1)
        printf("Queue is empty\n");
    else{
        printf("deleted element is %d\n",a[front]);
        if(front == rear)
            front = -1;
        else
            ++front;
    }
    return front;
}

void display(int a[], int front, int rear)
{
    if(front == -1)
        printf("Queue is empty\n");
    else{
        if(front<=rear)
        {
            for(int i=front;i<=rear;i++)
                printf("%d,",a[i]);
        }
        else{
            for(int i=front;i<max;i++)
                printf("%d,",a[i]);
            for(int i=0;i<=rear;i++)
                printf("%d,",a[i]);
        }
        printf("\n");
    }
}
int main()
{
    int front = -1, rear = -1;
    int choice,flag=0;
    int a[max];
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
                rear = insert(a,front,rear);
                if(flag==0)
                    ++front;
                flag=1;
                break;
            case 2:
                front = delete(a,front,rear);
                if(front ==-1)
                {
                    rear=-1;
                    front=-1;
                    flag=0;
                }
                break;
            case 3:
                display(a,front,rear);
                break;
            case 4: exit(0);
            default:
                printf("\twrong input\n");
        }
    }
    return 0;
}