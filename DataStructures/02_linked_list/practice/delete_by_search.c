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

node* delete_search(node* head)// 1 2 ( p1) 4 5 6 7 3
{
   
   if(head == NULL)
   {
        printf("\nempty\n");
        return head;
   }
   int val;
   scanf("%d",&val);
   node* temp = head;
   while(temp->next!=NULL)
   {
        if(val == temp->next->info) //temp->info  1 2 (3 temp) (4 ko skip karne ke lie) 5 6
        {
            temp->next = temp->next->next;// skip agar hota hai delete karne ke lie meaning aage increment karne ki zaroorat nhi hai
        }
        else // important
            temp = temp->next;
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
        printf("3. delete search\n");
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
                head = delete_search(head);
                break;
            case 4: exit(0);
            default:
                printf("\twrong input\n");
        }
    }
    return 0;
}
