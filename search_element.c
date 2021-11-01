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
    struct node *root = (struct node *)malloc(sizeof(struct node));
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
    int f;
    int r;
    int capacity;
    struct node **arr;
};
struct queue *CreateQueue()
{
    struct queue *q = malloc(sizeof(struct queue));
    if (!q)
    {
        return NULL;
    }
    q->capacity = 20;
    q->f = -1;
    q->r = -1;
    q->arr = malloc(q->capacity * sizeof(struct node *));
    if (!q->arr)
    {
        return NULL;
    }
    return q;
}
int queueIsEmpty(struct queue *q)
{
    return q->f == -1;
}
int queueIsFull(struct queue *q)
{
    return (q->r + 1) % q->capacity == q->f;
}
void EnQueue(struct queue *q, struct node *root)
{
    if (queueIsFull(q))
    {
        printf("Queue overflow!!\n");
        return;
    }
    q->r = (q->r + 1) % q->capacity;
    q->arr[q->r] = root;
    if (q->f == -1)
    {
        q->f = q->r;
    }
}
struct node *DeQueue(struct queue *q)
{
    if (queueIsEmpty(q))
    {
        printf("Queue underflow!!\n");
        return NULL;
    }
    struct node *root = q->arr[q->f];
    if (q->f == q->r)
    {
        q->f = q->r = -1;
    }
    else
    {
        q->f = (q->f + 1) % q->capacity;
    }
    return root;
}
int searchElement(struct node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->data == data)
    {
        return 1;
    }
    else
    {
        return (searchElement(root->left, data) || searchElement(root->right, data));
    }
}
int searchNode(struct node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    struct queue *q = CreateQueue();
    struct node *temp;
    EnQueue(q, root);
    while (!queueIsEmpty(q))
    {
        temp = DeQueue(q);
        if (temp->data == data)
        {
            return 1;
        }
        if (temp->left)
        {
            EnQueue(q, temp->left);
        }
        if (temp->right)
        {
            EnQueue(q, temp->right);
        }
    }
    return 0;
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
    int data;
    printf("Enter the element to be searched:\n");
    scanf("%d", &data);
    printf("RECUSIVELY:\n");
    if (searchElement(root, data))
    {
        printf("The element is present in the tree\n");
    }
    else
    {
        printf("The element is not present in the tree\n");
    }
    printf("NON-RECUSIVELY:\n");
    if (searchNode(root, data))
    {
        printf("The element is present in the tree\n");
    }
    else
    {
        printf("The element is not present in the tree\n");
    }
    return 0;
}