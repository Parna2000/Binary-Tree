// Insertion of a node in a AVL tree
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
int isBst(struct node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    if (root->left != NULL && root->data < root->left->data)
    {
        return 0;
    }
    if (root->right != NULL && root->data > root->right->data)
    {
        return 0;
    }
    if ((!isBst(root->left)) || (!isBst(root->right)))
    {
        return 0;
    }
    return 1;
}
int height(struct node *root)
{
    if (root == NULL)
    {
        return -1;
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
int isAvl(struct node *root)
{
    return (isBst(root) && (height(root->left) - height(root->right) <= 1) && (height(root->left) - height(root->right) >= -1));
}
struct node *singleLeft(struct node *x)
{
    struct node *w = x->left;
    x->left = w->right;
    w->right = x;
    return w;
}
struct node *singleRight(struct node *x)
{
    struct node *w = x->right;
    x->right = w->left;
    w->left = x;
    return w;
}
struct node *doubleLeft(struct node *x)
{
    x->left = singleRight(x->left);
    x = singleLeft(x);
    return x;
}
struct node *doubleRight(struct node *x)
{
    x->right = singleLeft(x->right);
    x = singleRight(x);
    return x;
}
struct node *insertNode(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (root->data > data)
    {
        root->left = insertNode(root->left, data);

        if (!isAvl(root))
        {
            if (data < root->left->data)
            {
                root = singleLeft(root);
            }
            else
            {
                root = doubleLeft(root);
            }
        }
    }
    else if (root->data < data)
    {
        root->right = insertNode(root->right, data);

        if (!isAvl(root))
        {
            if (data > root->right->data)
            {
                root = singleRight(root);
            }
            else
            {
                root = doubleRight(root);
            }
        }
    }
    return root;
}
int main()
{
    // struct node *root = (struct node *)malloc(sizeof(struct node));
    struct node *root = createNode(23); /*            23          */
    struct node *r1 = createNode(20);   /*            /\          */
    struct node *r2 = createNode(25);   /*           20 25        */
    struct node *r3 = createNode(18);   /*           /\  /\       */
    struct node *r4 = createNode(21);   /*         18 21 24 26    */
    struct node *r5 = createNode(24);   /*         /              */
    struct node *r6 = createNode(26);   /*        17              */
    struct node *r7 = createNode(17);
    struct node *r8 = createNode(16);
    root->left = r1;
    root->right = r2;
    r1->left = r3;
    r1->right = r4;
    r2->left = r5;
    r2->right = r6;
    r3->left = r7;
    // r7->left = r8;
    printf("Enter the element to be inserted:\n");
    int d;
    scanf("%d", &d);
    insertNode(root, d);
    printf("The height of the AVLtree is: %d\n", height(root));
    return 0;
}