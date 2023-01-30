// 0 based indexing through out the program

#include <stdio.h>
#include <stdlib.h>
int* insert(int* a,  int* count)
{
    if(a == NULL) // checking if array is full
    {
        a = (int*)malloc(sizeof(int));
    }
    else{
        a=realloc(a,((*count)+1)*sizeof(int));
    }
    int index,value,i;
    again:
    printf("Enter the index where you want to insert: ");
    scanf("%d",&index);
    if(index>*count) // checking for partially filled array
    {
        printf("\nList is only filled till index %d so you cannot insert at index more than %d\n\n",(*count)-1,*count);
        goto again;
    }
    printf("Enter the value: ");
    scanf("%d",&value);
    for(i=(*count); i>index; i--)
        a[i] = a[i-1];
    a[index]=value;
    ++(*count);
    printf("count is %d\n",*count);
    return a;//address updated that's why we need to return
}
void delete(int* a, int* count)
{
    if(*count == 0)
    {
        printf("\nArray is empty\n\n");
        return;
    }
    int index,i;
    again:
    printf("Enter the index where you want to delete: ");
    scanf("%d",&index);
    if(index>(*count)-1 || index<0) // checking for index out of bounds
    {
        printf("\nindex out of range try again\n\n");
        goto again;
    }
    for(i=index ; i<=(*count)-2;i++)
        a[i]=a[i+1];
    --(*count);
}
void print(int* a, int count)
{
    if(count == 0)
    {
        printf("\nArray is empty\n\n");
        return;
    }
    for(int i=0; i<(count); i++)
        printf("%d ",a[i]);
    printf("\n");
}
int* append(int* a, int* count)
{
    if(a == NULL) // checking if array is full
    {
        a = (int*)malloc(sizeof(int));
    }
    else{
        a=realloc(a,((*count)+1)*sizeof(int));
    }
    int value;
    printf("Enter the value: ");
    scanf("%d",&value);
    a[(*count)]= value; 
    ++(*count);
    return a;
}
void search(int* a, int count)
{
    if(count == 0)
    {
        printf("\nArray is empty\n\n");
        return;
    }
    int key,flag=0;;
    printf("Enter the key: ");
    scanf("%d",&key);
    for(int i=0;i<(count);i++)
    {
        if(a[i]==key)
        {
            printf("%d found at index %d\n",key,i);
            ++flag;
        }
    }
    if(flag == 0)
        printf("\nkey not found\n\n");

}
int main()
{
    printf("\tDynamic Array where each time memory is allocated\n");
    // int a[10]; malloc ka use karna hi padega and for that why dont we take size from user (here not taking size from user)
    // printf("Enter the size of the array: ");
    // scanf("%d",&size);
    // int* a = (int*)malloc(size*sizeof(int));
    int* a = NULL;
    int count = 0;
    while(1)
    {
        printf("Options:\n");
        printf("1. insert\n");
        printf("2. delete\n");
        printf("3. print\n");
        printf("4. append\n");
        printf("5. search\n");
        printf("6. exit\n");
        int choice;
        printf("ENTER CHOICE -> ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            a=insert(a,&count);
            break;
        case 2:
            delete(a,&count);
            break;
        case 3:
            print(a,count);
            break;
        case 4:
            a=append(a,&count);
            break;
        case 5:
            search(a,count);
            break;
        case 6:
            exit(0);
        default: printf("wrong choice\n");
        }
    }
}