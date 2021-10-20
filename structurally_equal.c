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
int equal(struct node *root, struct node *shoot)
{
    if (root == NULL && shoot == NULL)
    {
        return 1;
    }
    if (root == NULL || shoot == NULL)
    {
        return 0;
    }
    else
    {
        return (root->data == shoot->data && equal(root->left, shoot->left) && equal(root->right, shoot->right));
    }
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
    // struct node *temp = deep(root);
    struct node *shoot = createNode(23); /*           23          */
    struct node *s1 = createNode(20);    /*           /\          */
    struct node *s2 = createNode(25);    /*          20 25        */
    struct node *s3 = createNode(18);    /*          /\  /\       */
    struct node *s4 = createNode(21);    /*         18 21 24 26   */
    struct node *s5 = createNode(24);
    struct node *s6 = createNode(26);
    struct node *s7 = createNode(29);
    shoot->left = s1;
    shoot->right = s2;
    s1->left = s3;
    s1->right = s4;
    s2->left = s5;
    s2->right = s6;
    // s3->left = s7;
    if (equal(root, shoot))
    {
        printf("Both the trees are structurally identical\n");
    }
    else
    {
        printf("Both the trees are not structurally identical\n");
    }
    return 0;
}