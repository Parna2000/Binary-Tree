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
void levelOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        struct queue *q = createQueue();
        EnQueue(q, root);
        struct node *temp;
        while (!isEmpty(q))
        {
            temp = DeQueue(q);
            printf("%d ", temp->data);
            if (temp->left)
                EnQueue(q, temp->left);
            if (temp->right)
                EnQueue(q, temp->right);
        }
        printf("\n");
    }
}
struct node *buildTree(int pre[], int in[], int inStart, int inEnd)
{
    if (inStart > inEnd)
    {
        return NULL;
    }
    struct node *new = malloc(sizeof(struct node));
    int preindex = 0;
    new->data = pre[preindex];
    preindex++;
    if (inStart == inEnd)
    {
        return new;
    }
    else
    {
        int inindex;
        for (int i = 0; i < inEnd; i++)
        {
            if (in[i] == pre[0])
            {
                inindex = i;
                break;
            }
        }
        new->left = buildTree(pre, in, inStart, inindex - 1);
        new->right = buildTree(pre, in, inindex + 1, inEnd);
        return new;
    }
}
int main()
{
    int in[20], pre[20], n;
    printf("Enter the length of traversal:\n");
    scanf("%d", &n);
    printf("Enter the inorder traversal:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]);
    }
    printf("Enter the preorder traversal:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pre[i]);
    }
    struct node *new = buildTree(in, pre, 0, n - 1);
    printf("So, the required tree is:\n");
    levelOrder(new);
    return 0;
}