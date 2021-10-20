// print all the root to leaf paths

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
void printpath(int path[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", path[i]);
    }
}
void pathi(struct node *root, int path[], int pathlen)
{
    if (root == NULL)
    {
        return;
    }
    path[pathlen] = root->data;
    pathlen++;
    if(root->left==NULL&&root->right==NULL){
        printpath(path,pathlen);
    }
    if (root->left)
    {
        pathi(root->left, path, pathlen);
        // printpath(path, pathlen);
    }
    printf("\n");
    if (root->right)
    {
        pathi(root->right, path, pathlen);
    }
}
int main()
{
    // struct node *root = (struct node *)malloc(sizeof(struct node));
    struct node *root = createNode(23); /*            23          */
    struct node *r1 = createNode(20);   /*            /\          */
    struct node *r2 = createNode(25);   /*           20 25        */
    struct node *r3 = createNode(18);   /*           /\  /\       */
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
    r3->left = r7;
    // struct node *temp = deep(root);
    int pathlen = 0;
    int path[100];
    printf("All the paths from root to leaf are\n");
    pathi(root, path, pathlen);
    printf("\n");
    return 0;
}