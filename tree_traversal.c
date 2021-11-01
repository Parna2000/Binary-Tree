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
struct stack
{
    int size;
    int top;
    struct node **sarr;
};
struct stack *CreateStack()
{
    struct stack *s = malloc(sizeof(struct stack));
    if (!s)
    {
        return NULL;
    }
    s->top = -1;
    s->size = 20;
    s->sarr = malloc(s->size * sizeof(struct node *));
    if (!s->sarr)
    {
        return NULL;
    }
    return s;
}
int stackIsEmpty(struct stack *s)
{
    return s->top == -1;
}
int stackIsFull(struct stack *s)
{
    return (s->top + 1) == s->size;
}
void push(struct stack *s, struct node *root)
{
    if (stackIsFull(s))
    {
        printf("Stack overflow!!\n");
        return;
    }
    s->top++;
    s->sarr[s->top] = root;
}
struct node *pop(struct stack *s)
{
    if (stackIsEmpty(s))
    {
        printf("Stack underflow!!\n");
        return NULL;
    }
    struct node *root = s->sarr[s->top];
    s->top--;
    return root;
}
struct node *top(struct stack *s)
{
    if (stackIsEmpty(s))
    {
        printf("Stack underflow!!\n");
        return NULL;
    }
    struct node *root = s->sarr[s->top];
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
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct stack *s = CreateStack();
    while (1)
    {
        while (root)
        {
            printf("%d ", root->data);
            push(s, root);
            root = root->left;
        }
        if (stackIsEmpty(s))
        {
            break;
        }
        root = pop(s);
        root = root->right;
    }
    printf("\n");
}
void inorder(struct node *root)
{
    while (root == NULL)
    {
        return;
    }
    struct stack *s = CreateStack();
    while (1)
    {
        while (root)
        {
            push(s, root);
            root = root->left;
        }
        if (stackIsEmpty(s))
        {
            break;
        }
        root = pop(s);
        printf("%d ", root->data);
        root = root->right;
    }
    printf("\n");
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct stack *s = CreateStack();
    struct node *previous = NULL;
    do
    {
        while (root)
        {
            push(s, root);
            root = root->left;
        }
        while (root == NULL && !stackIsEmpty(s))
        {
            root = top(s);
            if (root->right == NULL || root->right == previous)
            {
                root = pop(s);
                printf("%d ", root->data);
                previous = root;
                root = NULL;
            }
            else
            {
                root = root->right;
            }
        }
    } while (!stackIsEmpty(s));
    printf("\n");
}
void levelorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct queue *q = CreateQueue();
    struct node *temp;
    EnQueue(q, root);
    while (!queueIsEmpty(q))
    {
        temp = DeQueue(q);
        printf("%d ", temp->data);
        if (temp->left)
        {
            EnQueue(q, temp->left);
        }
        if (temp->right)
        {
            EnQueue(q, temp->right);
        }
    }
    printf("\n");
}
int main()
{
    struct node *root = createNode(28);
    struct node *r1 = createNode(25);
    struct node *r2 = createNode(31);
    struct node *r3 = createNode(23);
    struct node *r4 = createNode(26);
    struct node *r5 = createNode(30);
    struct node *r6 = createNode(32);
    root->left = r1;
    root->right = r2;
    r1->left = r3;
    r1->right = r4;
    r2->left = r5;
    r2->right = r6;
    printf("Choose any one of the following options:\n1.Inorder traversal\n2.Preorder traversal\n3.Postorder traversal\n4.Levelorder Traversal\n5,Exit\n");
    while (1)
    {
        int choice;
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            inorder(root);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            levelorder(root);
            break;
        case 5:
            printf("Bye bye!!\n");
            return 0;
        }
    }
    return 0;
}