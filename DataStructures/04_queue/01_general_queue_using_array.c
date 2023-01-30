#include <stdio.h>

void enqueue(int q[], int value, int* rear)
{
    if(*rear == 10)
    {
        printf("Overflow\n");
        return;
    }
    q[*rear]=value;
    ++(*rear);
}
int dequeue(int q[], int* front, int* rear)
{
    if(*front == *rear)
    {
        printf("empty\n");
        return 0;
    }
    int x = q[(*front)];
    ++(*front);
    return x;
    
}
void displaY(int q[],int front, int rear)
{
    if(front==rear)
    {
        printf("Empty\n");
        return;
    }
    for(int i=front;i<rear;i++)
    {
        printf("%d,",q[i]);
    }
    printf("\n");
}
int main()
{
    int q[10],front=0,rear=0;
    enqueue(q,10,&rear);
    enqueue(q,17,&rear);
    printf("%d\n",dequeue(q,&front,&rear));
    enqueue(q,20,&rear);
    enqueue(q,30,&rear);
    printf("%d\n",dequeue(q,&front,&rear));
    enqueue(q,120,&rear);
    printf("%d\n",dequeue(q,&front,&rear));
    enqueue(q,2,&rear);
    enqueue(q,20,&rear);
    enqueue(q,110,&rear);
    printf("%d\n",dequeue(q,&front,&rear));
    enqueue(q,10,&rear);
    printf("%d\n",dequeue(q,&front,&rear));
    enqueue(q,17,&rear);

    displaY(q,front,rear);

    enqueue(q,100,&rear);

    printf("%d\n",dequeue(q,&front,&rear));
    printf("%d\n",dequeue(q,&front,&rear));
    printf("%d\n",dequeue(q,&front,&rear));
    printf("%d\n",dequeue(q,&front,&rear));
    printf("%d\n",dequeue(q,&front,&rear));
    printf("%d\n",dequeue(q,&front,&rear));
    printf("%d\n",dequeue(q,&front,&rear));

    displaY(q,front,rear);
    
    return 0;
}