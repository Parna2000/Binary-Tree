// Find the least common ancestor of two nodes in a tree
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
struct queue
{
    int size;
    int f;
    int r;
    struct node **arr;
};
struct queue *createQueue()
{
    struct queue *q = malloc(sizeof(struct queue));
    if (!q)
    {
        return NULL;
    }
    q->size = 20;
    q->f = -1;
    q->r = -1;
    q->arr = malloc(q->size * sizeof(struct node *));
    if (!q->arr)
    {
        return NULL;
    }
    return q;
}
int isEmpty(struct queue *q)
{
    return (q->f == -1);
}
int isFull(struct queue *q)
{
    return (q->r + 1) % q->size == q->f;
}
void EnQueue(struct queue *q, struct node *root)
{
    if (isFull(q))
    {
        printf("Queue overflow!!\n");
        return;
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = root;
        if (q->f == -1)
        {
            q->f = q->r;
        }
    }
}
struct node *DeQueue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow!!\n");
    }
    struct node *root = q->arr[q->f];
    if (q->f == q->r)
    {
        q->f = q->r = -1;
    }
    else
    {
        q->f = (q->f + 1) % q->size;
    }
    return root;
}
struct node *lca(struct node *root, int d1, int d2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (d1 == d2)
    {
        struct queue *q = createQueue();
        EnQueue(q, root);
        struct node *temp;
        while (!isEmpty(q))
        {
            temp = DeQueue(q);
            if (temp->data == d1)
            {
                return temp;
            }
            if (temp->left)
                EnQueue(q, temp->left);
            if (temp->right)
                EnQueue(q, temp->right);
        }
        return NULL;
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
    printf("Enter the two nodes whose LCA (least common ancestor) we want to find:\n");
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("The LCA of these two nodes is: %d\n");
    return 0;
}