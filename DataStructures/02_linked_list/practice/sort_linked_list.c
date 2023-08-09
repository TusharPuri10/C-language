#include <stdio.h>
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
    }
    else{
        node* temp = head;
        while(temp->next!=NULL) //last element
        {
            temp = temp->next;
        }
        temp->next = new_node;
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

void swap(node* x, node* y)
{
    int tmp = x->info;
    x->info = y->info;
    y->info = tmp;
}
node* sortLinkedList(node* head)
{
    node* temp1 = head;
    if(temp1 == NULL)
    {
        printf("\nempty\n");
    }
    else
    {
        while(temp1->next != NULL)
        {
            node* temp2 = temp1->next;
            while(temp2 != NULL)
            {
                if(temp1->info > temp2->info)
                {
                    swap(temp1,temp2);
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }
    return head;
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
        printf("3.sort\n");//imp
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
                head = sortLinkedList(head);
                break;
            case 4: exit(0);
            default:
                printf("\twrong input\n");
        }
    }
    return 0;
}
