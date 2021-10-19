// find the diameter of a binary tree
// find the number of leaf nodes the tree
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data)
{
    struct node *root = malloc(sizeof(struct node));
    if (!root)
    {
        return NULL;
    }
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}
int height(struct node*root){
    if(root==NULL){
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    if(l>r)
    return l+1;
    else
    return r+1;
}
int max(int a,int b){
    if(a>b)
    return a;
    else
    return b;
}
int diameter(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh+rh+1,max(ld,rd));
}
int main()
{
    // struct node *root = (struct node *)malloc(sizeof(struct node));
    struct node *root = createNode(23); /*           23          */
    struct node *r1 = createNode(20);   /*           /\          */
    struct node *r2 = createNode(25);   /*          20 25        */
    struct node *r3 = createNode(18);   /*          /\  /\       */
    struct node *r4 = createNode(21);   /*         18 21 24 26   */
    struct node *r5 = createNode(24);
    struct node *r6 = createNode(26);
    struct node *r7 = createNode(29);
    root->left = r1;
    root->right = r2;
    r1->left = r3;
    r1->right = r4;
    r2->left = r5;
    r2->right = r6;
    // r3->left = r7;
    printf("The diameter of the tree is: %d\n", diameter(root));
    return 0;
}