// About AVL Trees
#include <stdio.h>
#include <stdlib.h>

int number_of_nodes(int height)
{
    if (height == 0)
    {
        return 1;
    }
    else if (height == 1)
    {
        return 2;
    }
    else
    {
        return 1 + number_of_nodes(height - 1) + number_of_nodes(height - 2);
    }
}
int number_f_shapes(int height)
{
    if (height == 0)
    {
        return 1;
    }
    else if (height == 1)
    {
        return 2;
    }
    else
    {
        return 2 * number_f_shapes(height - 1) * number_f_shapes(height - 2);
    }
}

int main()
{
    printf("Choose any one of the following option:\n1.Count the number of nodes of an AVL tree\n2.Count the number of possible shapes of the AVL tree\n3.Exit\n");
    while (1)
    {
        int choice, height;
        printf("Enter the choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the height of the tree:\n");
            scanf("%d", &height);
            printf("Number of nodes in a tree of height %d is %d\n", height, number_of_nodes(height));
            break;
        case 2:
            printf("Enter the height of the tree:\n");
            scanf("%d", &height);
            printf("Number of possible shapes for a tree of height %d is %d\n", height, number_f_shapes(height));
            break;
        case 3:
            printf("Bye bye!!\n");
            return 0;
        }
    }
    return 0;
}