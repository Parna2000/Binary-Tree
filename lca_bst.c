// find the least common ancestor of two given nodes
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
struct node *lca(struct node *root, int d1, int d2)
{
    while (1)
    {
        if ((d1 < root->data && d2 > root->data) || (d2 < root->data && d1 > root->data))
        {
            return root;
        }
        if (d1 < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
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
    struct node *r7 = createNode(29);
    root->left = r1;
    root->right = r2;
    r1->left = r3;
    r1->right = r4;
    r2->left = r5;
    r2->right = r6;
    // r3->right = r7;
    int d1, d2;
    printf("Enter the elements for which you want to find the least common ancestor:\n");
    scanf("%d %d", &d1, &d2);
    struct node *shoot = lca(root, d1, d2);
    printf("The lca of %d and %d is: %d\n", d1, d2, shoot->data);
    return 0;
}