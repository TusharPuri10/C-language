#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node* next;
}node;

node* insert(node* head)//insert at index 1 based indexing
{
    node* new_node = (node*)malloc(sizeof(node));//memory allocate
    printf("\tenter dettail:");
    scanf("%d",&new_node->info);
    new_node->next = NULL;
    if(head == NULL)
    {
        head = new_node;
    }
    else{
        int index;
        printf("\t enter the index:");
        scanf("%d",&index);//2
       node* temp = head;//index se pahle wale node pe daal degi
       if(index==1)
       {
            printf("\tinsert_at_begin\n");
       }
       else{
        int i=1;
        while(i<=index-2)//index -2 tak loop chalna hai
        {
            if(temp->next != NULL)//last node //while ka error //ye cheez karo jab tak -> while.
                temp = temp->next; // no zaroorat
            ++i;
        }
        new_node->next  = temp->next;
        temp->next = new_node;
       }
    return head;
    }
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
int main()
{
    node* head = NULL;
    int choice;
    while(1)
    {
        int choice;
        printf("Options:\n");

       // printf("1.insert at end\n");//imp
        printf("1.insert at index\n");
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
