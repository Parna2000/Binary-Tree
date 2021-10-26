#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *firstChild;
    struct node *nextSibling;
};
int height(int n, int arr[])
{
    int maxDepth=-1,currentDepth=-1,j;
    for (int i = 0; i < n; i++)
    {
        j=i,currentDepth=0;
        while (arr[j]!=-1)
        {
            currentDepth++;
            j=arr[j];
        }
        if(currentDepth>maxDepth){
            maxDepth=currentDepth;
        }
    }
    return maxDepth;
}
int main()
{
    int n;
    printf("Enter the length of the array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The height of the tree is: %d\n", height(n, arr));
    return 0;
}