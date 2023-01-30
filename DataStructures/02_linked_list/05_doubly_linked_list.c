#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node* prev; // extra
    int info;
    struct node* next;
}node;

node* insert(node* head)
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node->prev = NULL; // extra
    new_node ->next = NULL;
    printf("\tenter the value:");
    scanf("%d",&new_node->info);
    if(head == NULL)
    {
        head = new_node;
    }
    else{
        node* temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp; //extra
    }
    return head;
}

void display(node* head)
{
    if(head == NULL)
    {
        printf("\nempty\n");
    }
    else
    {
        printf("\t");
        
        while(head!=NULL)
        {
            printf("%d,",head->info);
            head = head->next;
        }
    }
}

void rev_display(node* head)
{
    if(head == NULL)
    {
        printf("\nempty\n");
    }
    else
    {
        printf("\t");
        
        while(head->next!=NULL) // last
        {
            head = head->next;
        }
        while (head!=NULL)
        {
            printf("%d,",head->info);
            head = head->prev;
        }
        
    }
}
int main()
{
    node* head = NULL;
    int choice;
    while(1)
    {
        int choice;
        printf("Options:\n");

        printf("1.insert at end\n");//imp
        printf("2.display\n");//imp
        printf("3.display reverse\n");
        printf("4.exit\n");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                head = insert(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                rev_display(head);
                break;
            case 4: exit(0);
            default:
                printf("\twrong input\n");
        }
    }
    return 0;
}
