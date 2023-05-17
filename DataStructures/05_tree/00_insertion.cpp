#include<iostream>
#include<vector>
using namespace std;
struct node{
    int info;
    struct node* left;
    struct node* right;
};
typedef struct node node;
node* newNode(int data=0)
{
    node*  newnode = (node*) malloc(sizeof(node));
    newnode->info = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
//traversals
void inorder_recursive(node* root)
{
    if(root == NULL)
        return;
    
    inorder_recursive(root->left);
    printf("%d,",root->info);
    inorder_recursive(root->right);
}

void preorder_recursive(node* root)
{
    if(root == NULL)
        return;
    
    printf("%d,",root->info);
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}
void postorder_recursive(node* root)
{
    if(root == NULL)
        return;
    
    postorder_recursive(root->left);
    postorder_recursive(root->right);
    printf("%d,",root->info);
}
////////////
node* insert(node* root0, vector<int> &vec,int index)
{
    if(index>=vec.size())
        return NULL;
    
    if(root0==NULL)
        root0 = newNode(vec[index]);
    else
        root0->info=vec[index];

    root0->left = insert(root0->left,vec,2*index+1);
    root0->right= insert(root0->right,vec,2*index+2);
    
    return root0;
}
void create_tree(node* root0, vector<int> &vec){
    
    root0 = insert(root0,vec,0);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int size;
        cin>>size;
        vector<int> v;
        int x;
        for(int i=0;i<size;i++)
        {
            cin>>x;
            v.push_back(x);
        }
        
        node* root = newNode();
        create_tree(root,v);

    inorder_recursive(root);
    printf("\n");
    preorder_recursive(root);
    printf("\n");
    postorder_recursive(root);
    printf("\n");
    }
    return 0;
}