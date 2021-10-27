// Check if the given tree is AVL(Adelson-Velskii-Landis) tree or not
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    // int size;
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
int binaryTree(struct node *root)
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
    if (!binaryTree(root->left) || !binaryTree(root->right))
    {
        return 0;
    }
    return 1;
}
int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int l = height(root->left);
        int r = height(root->right);
        if (l > r)
        {
            return l + 1;
        }
        else
        {
            return r + 1;
        }
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
    struct node *r7 = createNode(17);
    struct node *r8 = createNode(16);
    root->left = r1;
    root->right = r2;
    r1->left = r3;
    r1->right = r4;
    r2->left = r5;
    r2->right = r6;
    // r3->left = r7;
    // r7->left = r8;
    if (binaryTree(root) && ((height(root->left) - height(root->right)) <= 1 && (height(root->left) - height(root->right)) >= -1))
    {
        printf("The tree is an AVL tree\n");
    }
    else
    {
        printf("The tree is not an AVL tree\n");
    }
    return 0;
}