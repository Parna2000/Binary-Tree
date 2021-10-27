#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    char data;
    struct node *left;
    struct node *right;
};
struct node *createNode(char data)
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
        printf("%c ", root->data);
        root = root->right;
    }
    printf("\n");
}
int IsOperand(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
struct node *BuildTree(char postfix[], int size)
{
    struct stack *s = createStack();
    for (int i = 0; i < size; i++)
    {
        if (IsOperand(postfix[i]))
        {
            struct node *newNode = createNode(postfix[i]);
            push(s, newNode);
        }
        else
        {
            struct node *t1 = pop(s);
            struct node *t2 = pop(s);
            struct node *NewNode = createNode(postfix[i]);
            NewNode->left = t1;
            NewNode->right = t2;
            push(s, NewNode);
        }
    }
    struct node*node=pop(s);
    return node;
}
int main()
{
    char postfix[100];
    printf("Enter the postfix expression of the expression tree:\n");
    scanf("%s", postfix);
    printf("The expression tree is:\n");
    inOrder(BuildTree(postfix,strlen(postfix)));
    return 0;
}