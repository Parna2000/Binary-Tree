// find the number of keys that are strictly greater than k
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
int size(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return (size(root->left) + size(root->right) + 1);
    }
}
int GreaterthanConstant(struct node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int count = 0;
        while (root!=NULL)
        {
            if (root->data > data)
            {
                count = count + size(root->right) + 1;
                root = root->left;
            }
            else if (root->data < data)
            {
                root = root->right;
            }
            else
            {
                count = count + size(root->right);
                break;
            }
        }
        return count;
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
    printf("Enter the number:\n");
    int num;
    scanf("%d", &num);
    printf("The number of elements that are strictly greater than %d is: %d\n", num, GreaterthanConstant(root, num));
    return 0;
}