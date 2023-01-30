#include <stdio.h>// kal
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node* next;
}node;

node* insert(node* head)
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node ->next = NULL;
    printf("\tenter the value:");
    scanf("%d",&new_node->info);
    if(head == NULL)
    {
        head = new_node;
        new_node->next = new_node;
    }
    else{
        node* temp = head;
        do
        {
            temp = temp->next;
        } while(temp->next != head);
        temp->next = new_node;
        new_node->next = head;
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
        
        node* temp_head = head;
        printf("%d,",head->info);
        head = head->next;
        while(head!=temp_head)
        {
            printf("%d,",head->info);
            head = head->next;
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
        printf("3.exit\n");
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
            case 3: exit(0);
            default:
                printf("\twrong input\n");
        }
    }
    return 0;
}
