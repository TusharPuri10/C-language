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
        while(temp->next!=NULL)
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

node* delete_duplicate(node* head)// 1 2 ( p1) 4 5 6 7 3
{
   node* ptr1;//3
   ptr1 = head;
   if(head == NULL)
   {
        printf("\nempty\n");
        return head;
   }
   while(ptr1->next->next!= NULL) // second last
   {
       node* ptr2 = ptr1;//3
       while(ptr2->next!=NULL)// last
       {
           if(ptr2->next->info == ptr1->info)//
           {
                ptr2->next = ptr2->next->next; // skip
           }
           else
                ptr2 = ptr2->next;
       }
       ptr1 = ptr1->next;
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
        printf("3. delete duplicate\n");
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
            case 3:
                head = delete_duplicate(head);
                break;
            case 4: exit(0);
            default:
                printf("\twrong input\n");
        }
    }
    return 0;
}
