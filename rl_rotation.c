// Restoring an AVL(Adelson-Velskii-Landis) tree by single rotation
// Useful when we insert left child to a left-subtree or right child to a right-subtree
// Since in these cases height difference becomes two
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    // int height;
};
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
    if (root->right != NULL && root->data > root->right->data)
    {
        return 0;
    }
    if (root->left != NULL && root->data < root->left->data)
    {
        return 0;
    }
    if ((!check(root->left)) || (!check(root->right)))
    {
        return 0;
    }
    return 1;
}
int check_avl(struct node *root)
{
    if (check(root) && (height(root->left) - height(root->right) >= -1) && (height(root->left) - height(root->right) <= 1))
    {
        return 1;
    }
    return 0;
}
struct node *singleRotateLeft(struct node *x)
{
    struct node *w = x->left;
    x->left = w->right;
    w->right = x;
    return w;
}
struct node *singleRotateRight(struct node *x)
{
    struct node *w = x->right;
    x->right = w->left;
    w->left = x;
    return w;
}
struct node *doubleRotateRightLeft(struct node *root)
{
    root->right = singleRotateLeft(root->right);
    return (singleRotateRight(root));
}
int main()
{
    // struct node *root = (struct node *)malloc(sizeof(struct node));
    struct node *root = createNode(23); /*            23          */
    struct node *r1 = createNode(20);   /*            /\          */
    struct node *r2 = createNode(27);   /*           20 27        */
    struct node *r3 = createNode(18);   /*               /\       */
    struct node *r4 = createNode(21);   /*             26 28      */
    struct node *r5 = createNode(26);   /*             /          */
    struct node *r6 = createNode(28);   /*            25          */
    struct node *r7 = createNode(17);   /*                        */
    struct node *r8 = createNode(25);   /*                        */
    root->left = r1;
    root->right = r2;
    // r1->left = r3;
    // r1->right = r4;
    r2->left = r5;
    r2->right = r6;
    // r4->right = r7;
    r5->left = r8;
    printf("The height of the tree is: %d\n", height(root));
    // root = doubleRotateLeftRight(root);
    if (check_avl(root))
    {
        printf("This is an AVL tree\n");
    }
    else
    {
        printf("This is not AVL tree\n");
        printf("Now we will balance this tree and make it AVL\n");
        root = doubleRotateRightLeft(root);
        printf("Now, the height of the AVLtree is: %d\n", height(root) + height(r3));
    }
    return 0;
}