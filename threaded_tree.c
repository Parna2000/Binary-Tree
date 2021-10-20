#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    int LTag;
    int data;
    int RTag;
    struct node *right;
};
// RTag==0  ==>right points to the in-order successor
// RTag==1  ==>right points to the right child
// find the inorder successor of a given node
struct node *createNode(int data)
{
    struct node *root = malloc(sizeof(struct node));
    if (!root)
    {
        return NULL;
    }
    root->data = data;
    root->RTag = 1;
    root->LTag = 1;
    root->left = NULL;
    root->right = NULL;
    return root;
}
int inorderSuccessor(struct node *root)
{
    if (root->RTag == 0)
    {
        return root->right->data;
    }
    else
    {
        struct node *pos = root->right;
        while (pos->LTag == 1)
        {
            pos = pos->left;
        }
        return pos->data;
    }
}
int main()
{
    // struct node *root = (struct node *)malloc(sizeof(struct node));
    struct node *root = createNode(23); /*            23          */
    struct node *r1 = createNode(20);   /*            /\          */
    struct node *r2 = createNode(25);   /*           20 25        */
    struct node *r3 = createNode(18);   /*           /\  /\       */
    struct node *r4 = createNode(21);   /*         18 21 24 26    */
    struct node *r5 = createNode(24);
    struct node *r6 = createNode(26);
    struct node *r7 = createNode(29);
    root->left = r1;
    root->right = r2;
    root->LTag=0;
    root->RTag=0;
    r1->left = r3;
    r1->right = r4;
    root->LTag=0;
    root->RTag=0;
    r2->left = r5;
    r2->right = r6;
    root->LTag=0;
    root->RTag=0;
    // r3->left = r7;
    // lets find the preorder successor of r2
    printf("The preorder successor of %d is: %d\n", r2->data, inorderSuccessor(r2));
    return 0;
}