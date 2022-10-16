#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode
{
    int data;
    struct treeNode *leftPtr;
    struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

// Prototypes:
void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

void main()
{
    int i;
    int item;
    TreeNodePtr rootPtr = NULL;

    srand(time(NULL));
    printf("The number being placed in the tree are: \n");
    for (i = 0; i <= 10; i++)
    {
        item = rand() % 14; // generates number in range 0-15
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }

    printf("\n\nThe preOrder traversal is: \n");
    preOrder(rootPtr);

    printf("\n\nThe postOrder traversal is: \n");
    postOrder(rootPtr);

    printf("\n\nThe inOrder traversal is: \n");
    inOrder(rootPtr);
}

void insertNode(TreeNodePtr *treePtr, int value)
{
    if (*treePtr == NULL)
    {
        *treePtr = malloc(sizeof(TreeNode));
        // if memory was allocated then assign data
        if (*treePtr != NULL)
        {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else
            printf("%d not inserted. No memory available.\n");
    }
    else{ // tree is not empty
        if(value < (*treePtr)->data)
            insertNode(&((*treePtr)->leftPtr), value);
        else if (value > (*treePtr)->data)
            insertNode(&(*treePtr)->rightPtr, value);
        else // duplicate data value (ignored)
            printf(" (Duplicate of %d)", (*treePtr)->data);
    }
}

void inOrder(TreeNodePtr treePtr){
    if (treePtr != NULL)
    {
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

void preOrder(TreeNodePtr treePtr){
    if (treePtr != NULL)
    {
        printf("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

void postOrder(TreeNodePtr treePtr){
    if (treePtr != NULL)
    {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }
}