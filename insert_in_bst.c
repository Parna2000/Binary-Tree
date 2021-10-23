// inserting the element in the inorder traversal
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
int max(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    else
    {
        return max(root->right);
    }
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else
    {
        if (root->data > data)
        {
            root->left = insert(root->left, data);
        }
        else if (root->data < data)
        {
            root->right = insert(root->right, data);
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
    int d1;
    printf("Enter the element to be inserted:\n");
    scanf("%d", &d1);
    root = insert(root, d1);
    printf("The maximum element of the tree is: %d\n", max(root));
    return 0;
}