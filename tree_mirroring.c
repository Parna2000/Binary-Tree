// convert a tree to its mirror
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
struct stack
{
    int size;
    int top;
    struct node **arr;
};
struct stack *createStack()
{
    struct stack *s = malloc(sizeof(struct stack));
    if (!s)
    {
        return NULL;
    }
    s->size = 20;
    s->top = -1;
    s->arr = malloc(s->size * sizeof(struct stack));
    if (!s->arr)
    {
        return NULL;
    }
    return s;
}
int isEmpty(struct stack *s)
{
    return s->top == -1;
}
int isFull(struct stack *s)
{
    return s->top == s->size - 1;
}
void push(struct stack *s, struct node *root)
{
    if (isFull(s))
    {
        printf("Stack overflow!!\n");
        return;
    }
    s->top++;
    s->arr[s->top] = root;
}
struct node *pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow!!\n");
    }
    struct node *root = s->arr[s->top];
    s->top--;
    return root;
}
struct node *Top(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow!!\n");
    }
    struct node *root = s->arr[s->top];
    return root;
}
void inOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct stack *s = createStack();
    while (1)
    {
        while (root)
        {
            push(s, root);
            root = root->left;
        }
        if (isEmpty(s))
        {
            break;
        }
        root = pop(s);
        printf("%d ", root->data);
        root = root->right;
    }
    printf("\n");
}
int leaf(struct node *root)
{
    if (root != NULL && root->left == NULL && root->right == NULL)
        return 1;
    else
        return 0;
}

void mirror(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    else
    {
        mirror(root->left);
        mirror(root->right);
        struct node *temp = root->left;
        root->left = root->right;
        root->right = temp;
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
    // r3->left = r7;
    // struct node *temp = deep(root);
    printf("Initialy the tree is:\n");
    inOrder(root);
    printf("After mirroring the tree is:\n");
    mirror(root);
    inOrder(root);
    return 0;
}