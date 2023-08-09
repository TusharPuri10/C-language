// testing malloc and realloc
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int* a = (int*)malloc(5*sizeof(int));
    for(int i = 0; i < 5; i++)
        a[i]=i;
    
    a = (int*) realloc(a, 10*sizeof(int));
    for(int i=0;i<5;i++)
        a[i+5]=i+10;
    
    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    return 0;
}