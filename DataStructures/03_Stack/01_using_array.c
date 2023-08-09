#include<stdio.h>
#include<stdlib.h>
#define max 10

int push(int top,int a[])
{
    if(top==max-1)
    {
        printf("\toverflow\n");
    }
    else
    {
        ++top;
        printf("enter the value you want to push:");
        scanf("%d",&a[top]);
    }
    return top;
}
int pop(int top,int a[])
{
    if(top==-1)
    {
        printf("\tunderflow\n");
    }
    else
    {
        printf("...deleting: %d",a[top]);
        --top;
    }
    return top;
}
void display(int top,int a[])
{
    if(top==-1)
    {
        printf("\tunderflow\n");
    }
    printf("\t");
    for(int i=top;i>=0;i--)
    {
        printf("%d,",a[i]);
    }
}

int main()
{
    int top=-1,a[max],choice;
    while(1)
    {
        printf("\noptions:\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.exit\n\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                top = push(top,a);
                break;
            case 2:
                top = pop(top,a);
                break;
            case 3:
                display(top,a);
                break;
            case 4:
                exit(0);
            default:
                printf("wrong input\n");
        }
    }
    return 0;
}