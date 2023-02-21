// Insertion
// DFS -> inorder, preorder, postorder (recursive)
#include <stdio.h>
#include<stdlib.h>

typedef struct tree{
    int info;
    struct tree* left;
    struct tree* right;
}tree;
void insert(tree** root,int value)
{
    if(*root == NULL)
    {
        tree* node = (tree*) malloc(sizeof(tree));
        node->left = NULL;
        node->info = value;
        node->right = NULL;
        *root = node;
        return;
    }
    if((*root)->info < value)
    {
        insert(&((*root)->right),value);
    }
    else if(value < (*root)->info)
    {
        insert(&((*root)->left),value);
    }
}

void inorder_recursive(tree* root)
{
    if(root == NULL)
        return;
    
    inorder_recursive(root->left);
    printf("%d,",root->info);
    inorder_recursive(root->right);
}

void preorder_recursive(tree* root)
{
    if(root == NULL)
        return;
    
    printf("%d,",root->info);
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}
void postorder_recursive(tree* root)
{
    if(root == NULL)
        return;
    
    postorder_recursive(root->left);
    postorder_recursive(root->right);
    printf("%d,",root->info);
}
int main()
{
    tree* root = NULL;

    insert(&root,20);
    insert(&root,30);
    insert(&root,10);
    insert(&root,23);
    insert(&root,13);
    insert(&root,34);
    insert(&root,55);
    insert(&root,40);

    inorder_recursive(root);
    printf("\n");
    preorder_recursive(root);
    printf("\n");
    postorder_recursive(root);
    printf("\n");
    level_order(root);
    printf("\n");

    return 0;
}