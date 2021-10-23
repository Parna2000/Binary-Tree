// inorder successor and predecessor
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
int min(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    else if (root->left)
    {
        return min(root->left);
    }
}
int pre(struct node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        if (root->data == data)
        {
            if (root->left)
            {
                return (max(root->left));
            }
            else if (!root->left)
            {
                return root->data;
            }
        }
        else
        {
            while (1)
            {
                if (root->data > data)
                {
                    root = root->left;
                }
                else
                {
                    root = root->right;
                }
                if (root->data == data)
                {
                    break;
                }
            }
            if (root->left)
            {
                return (max(root->left));
            }
            else if (!root->left)
            {
                return root->data;
            }
        }
    }
}
int suc(struct node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == data)
    {
        if (root->right)
        {
            return min(root->right);
        }
        else if (root->right == NULL)
        {
            return root->data;
        }
    }
    else
    {
        while (1)
        {
            if (root->data > data)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
            if (root->data == data)
            {
                break;
            }
        }
        if (root->right)
        {
            return min(root->right);
        }
        else if (root->right == NULL)
        {
            return root->data;
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
    int d1;
    printf("Enter the node data:\n");
    scanf("%d", &d1);
    printf("The inorder predecessor of %d is : %d\n", d1, pre(root, d1));
    printf("The inorder successor of %d is : %d\n", d1, suc(root, d1));
    return 0;
}