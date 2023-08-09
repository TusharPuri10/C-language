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

node* delete_end(node* head)// dealloacate karni padti hai memory
{
    if(head == NULL)
    {
        printf("\tempty\n");
    }
    else{
        node* temp = head;
        while(temp->next->next!=NULL)//yahan temp 2nd last element hoga
        {
            temp = temp->next;
        }
        //yahn temp next hamara last;
        printf("\t%d\n",temp->next->info);
        node* last_element = temp->next;// toh fir temp next last element hoga
        temp->next = NULL;// "last element ki jagah NULL agya" "saar"
        free(last_element);// deallocate of memory

    }
    // {head 1} (head 2) 3 4 5 6
    return head;
}

node* delete_begin(node* head)
{
    if(head == NULL)
    {
        printf("\tempty\n");
    }
    else{
        printf("\t%d\n",head->info);
        node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

node* delete_index(node* head)
{
    
    if(head == NULL)
    {
        printf("\tempty\n");
    }
    else{
        int index;
        printf("\t enter the index:");
        scanf("%d",&index);//2
       node* temp = head;//index se pahle wale node pe daal degi
       if(index==1)
       {
            printf("\tdelete_at_begin\n");
       }
       else{
        int i=1;
        while(i<=index-2)//3
        {
            if(temp->next != NULL)
            {    temp = temp->next;
            } // no zaroorat
            ++i;
        }
        if(temp->next == NULL)// last element temp ...temp delete karne wale se ek pahle wala
        {
            printf("wrong index");
            return head;
        }
        node* deall = temp->next;// dealloacting memory
        temp->next = temp->next->next;//delete karne wale ki jagah aaya uske next wala
        free(deall);
       }
    }
    return head;
}

void Display(node* head)
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
        printf("1.insert at end\n");//imp
        printf("2.display\n");//imp
        printf("3.delete by index\n");
        printf("4.delete from end\n");
        printf("5.delete from begin\n");
        printf("6.exit\n");

        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                head = insert(head);
                break;
            case 2:
                Display(head);
                break;
            case 3:
                head = delete_index(head);
                break;
            case 4:
                head = delete_end(head);
                break;
            case 5:
                head = delete_begin(head);
                break;
            case 6:
                exit(0);
            default:
                printf("\twrong input\n");
        }
    }
    return 0;
}
