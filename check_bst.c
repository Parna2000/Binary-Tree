// Check if a given tree is a binary search tree

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
int check(struct node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    if (root->left != NULL && root->left->data > root->data)
    {
        return 0;
    }
    if (root->right != NULL && root->right->data < root->data)
    {
        return 0;
    }
    if ((!check(root->left)) || (!check(root->right)))
    {
        return 0;
    }
    return 1;
}
int main()
{
    // struct node *root = (struct node *)malloc(sizeof(struct node));
    struct node *root = createNode(23); /*            23          */
    struct node *r1 = createNode(20);   /*            /\          */
    struct node *r2 = createNode(25);   /*           20 25        */
    struct node *r3 = createNode(29);   /*           /\  /\       */
    struct node *r4 = createNode(21);   /*         18 21 24 26    */
    struct node *r5 = createNode(24);
    struct node *r6 = createNode(26);
    struct node *r7 = createNode(29);
    root->left = r1;
    root->right = r2;
    r1->left = r3;
    r1->right = r4;
    r2->left = r5;
    r2->right = r6;
    // r3->right = r7;
    if (check(root))
    {
        printf("This is a binary search tree!!\n");
    }
    else
    {
        printf("This is not a binary search tree!!\n");
    }
    return 0;
}