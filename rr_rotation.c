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
struct node *singleRotateRight(struct node *x)
{
    struct node *w = x->right;
    x->right = w->left;
    w->left = x;
    return w;
}
int main()
{
    struct node *root = createNode(23); /*            23          */
    struct node *r1 = createNode(20);   /*            /\          */
    struct node *r2 = createNode(25);   /*           20 25        */
    struct node *r3 = createNode(18);   /*           /\  /\       */
    struct node *r4 = createNode(21);   /*         18 21 24 26    */
    struct node *r5 = createNode(24);   /*                   \    */
    struct node *r6 = createNode(26);   /*                   27   */
    struct node *r7 = createNode(27);   /*                     \  */
    struct node *r8 = createNode(28);   /*                     28 */
    root->left = r1;
    root->right = r2;
    r1->left = r3;
    r1->right = r4;
    r2->left = r5;
    r2->right = r6;
    r6->right = r7;
    r7->right = r8;
    printf("The height of the tree is: %d\n", height(root));
    if (check_avl(root))
    {
        printf("This is an AVL tree\n");
    }
    else
    {
        printf("This is not AVL tree\n");
        printf("Now we will balance this tree and make it AVL\n");
        r6 = singleRotateRight(r6);
        printf("Now, the height of the AVLtree is: %d\n", height(root) + height(r6));
    }
    return 0;
}