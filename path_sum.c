// Check the existence of the path with a given sum
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct queue
{
    int size;
    int f;
    int r;
    struct node **arr;
};
struct node *createNode(int data)
{
    struct node *root = malloc(sizeof(struct node));
    if (!root)
    {
        return 0;
    }
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}
int path(struct node *root, int sum)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int l = 0, r = 0;
        sum = sum - (root->data);
        if (root->left)
        {
            l = path(root->left, sum);
        }
        if (root->right)
        {
            r = path(root->right, sum);
        }
        if (sum == 0)
        {
            return 1;
        }
        return 0;
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
    r3->left = r7;
    // struct node *temp = deep(root);
    int data;
    printf("Enter the required sum:\n");
    scanf("%d", &data);
    if (path(root, data))
        printf("Path exists\n");
    else
        printf("Path donot exits\n");
    return 0;
}