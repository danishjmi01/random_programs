// C program for recursive level order traversal in spiral form
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
void printSpiral(struct node *root);
void _printSpiral(struct node* root, int level,int);
int height(struct node* node);
int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
void printSpiral(struct node *root){
int dir =1;
int h= height(root);
printf("height %d",h);
        for(int i =1; i <= h; i++){

                _printSpiral(root,i,dir);
        dir = dir * -1;
        }
}

void _printSpiral(struct node* root, int level,int dir){
        if(level == 1){
                printf("%d ",root->data);
                return;
        }
//      printf("%d ",root->data);
        if(dir == 1){
        _printSpiral(root->right,level-1,dir);
        _printSpiral(root->left,level-1,dir);}
        else{
        _printSpiral(root->left,level-1,dir);
        _printSpiral(root->right,level-1,dir);}
}
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

/* Driver program to test above functions*/
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    printf("Spiral Order traversal of binary tree is \n");
    printSpiral(root);

    return 0;
  }
