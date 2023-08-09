#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}node;

node* push(node * top)
{
    node* new = (node*)malloc(sizeof(node));
    printf("\tenter value you want to push:");
    scanf("%d", &new->info);
    new->next = NULL;
    new->next = top;
    top = new;
    return top;
}

node* pop(node* top)
{
    if(top == NULL)
    {
        printf("\tunderflow\n");
    }
    else
    {
        node* temp = top;
        printf("\t...deleting: %d\n",top->info);
        top = top->next;
        free(temp);
    }
    return top;
}

void display(node* top)
{
    if(top == NULL)
    {
        printf("\tunderflow\n");
    }
    else
    {
        printf("\t");
        while(top != NULL)
        {
            printf("%d,",top->info);
            top = top->next;
        }
    }
}
int main()
{
    node *top = NULL;
    while(1)
    {
        int choice;
        printf("Options:\n");
        printf("1.push\n");//imp
        printf("2.pop\n");//imp
        printf("3.display\n");//imp
        printf("4.exit\n");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                top = push(top);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4: exit(0);
            default:
                printf("\twrong input\n");
                
        }
    }
    return 0;
}