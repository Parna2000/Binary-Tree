// count number of siblings of a node
// sum of all the elements of a generic tree
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *firstChild;
    struct node *nextSibling;
};
struct node *createNode(int data)
{
    struct node *root = malloc(sizeof(struct node));
    if (!root)
    {
        return NULL;
    }
    root->data = data;
    root->firstChild = NULL;
    root->nextSibling = NULL;
    return root;
}
// struct node*find(int data){
// return;
// }
int sib(struct node *current)
{
    int s = 0;
    while (current)
    {
        if (current->firstChild)
        {
            current = current->firstChild;
        }
        else
            current = current->nextSibling;
        s++;
    }
    return s;
}
int main()
{
    struct node *root = createNode(23);
    struct node *r1 = createNode(22);
    struct node *r2 = createNode(24);
    struct node *r3 = createNode(25);
    struct node *r4 = createNode(26);
    struct node *r5 = createNode(27);
    root->firstChild = r1;
    r1->nextSibling = r2;
    r2->nextSibling = r3;
    r3->nextSibling = r4;
    r3->firstChild = r5;
    printf("Number of children of %d node is: %d\n", r3->data, sib(r3));
    return 0;
}