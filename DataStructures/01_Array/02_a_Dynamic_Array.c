// 0 based indexing through out the program

#include <stdio.h>
#include <stdlib.h>
void insert(int* a, int* size, int* count)
{
    if((*count)==(*size)) // checking if array is full
    {
        (*size) = (*size)*2;
        // int b[(*size)];
        a = (int*)realloc(a, (*size) * sizeof(int));
    }
    int index,value,i;
    again:
    printf("Enter the index where you want to insert: ");
    scanf("%d",&index);
    if(index>(*size)-1 || index<0) // checking for index out of bounds
    {
        printf("\nindex out of range try again\n\n");
        goto again;
    }
    else if(index>*count) // checking for partially filled array
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
void append(int* a, int (*size), int* count)
{
    if((*count)==(*size)) // checking if array is full
    {
        (*size) = (*size)*2;
        // int b[(*size)];
        a = (int*)realloc(a, (*size) * sizeof(int));
    }
    int value;
    printf("Enter the value: ");
    scanf("%d",&value);
    a[(*count)]= value; 
    ++(*count); 
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
    printf("\tDynamic Array by help of static array\n");
    int size;
    // int a[10]; malloc ka use karna hi padega and for that why dont we take size from user
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int* a = (int*)malloc(size*sizeof(int));
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
            insert(a,&size,&count);
            break;
        case 2:
            delete(a,&count);
            break;
        case 3:
            print(a,count);
            break;
        case 4:
            append(a,&size,&count);
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