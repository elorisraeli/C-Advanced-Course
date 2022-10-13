#include <stdio.h>
#include <stdlib.h>

// self referential structure
typedef struct node
{
    char data;
    struct node *nextPtr;
} node_t;

typedef node_t *ListNodePtr;

// Prototypes:
void insert(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char value);
void insertAtBeginning(ListNodePtr *head, char value);
char delete (ListNodePtr *head, char value);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPtr);

void main()
{
    ListNodePtr head = NULL;
    int choice = 0;
    char item = '\0';
    // display the menu:
    printf("Enter your choice:\n"
           "   1 to insert an element into the list in alphabetic order.\n"
           "   2 to insert an element at the end of the list.\n"
           "   3 to insert an element at the beginning of the list.\n"
           "   4 to delete an element from the list.\n"
           "   5 to delete an element from the beginning of the list.\n"
           "   6 to end.\n");
    printf(":: ");
    scanf("%d", &choice);
    while (choice != 6)
    {
        switch (choice)
        {
        case 1: // insert
            printf("Enter a character: ");
            scanf("\n%c", &item);
            insert(&head, item);
            printList(head);
            break;
        case 2: // insert at end
            printf("Enter a character: ");
            scanf("\n%c", &item);
            insertAtEnd(&head, item);
            printList(head);
            break;
        case 3: // insert at beginning
            printf("Enter a character: ");
            scanf("\n%c", &item);
            insertAtBeginning(&head, item);
            printList(head);
            break;
        case 4: // delete
            // if list is not empty
            if (!isEmpty(head))
            {
                printf("Enter a character: ");
                scanf("\n%c", &item);
                // if character is found, remove it
                if (delete (&head, item))
                {
                    printf("%c deleted.\n", item);
                    printList(head);
                }
                else
                    printf("%c not found.\n", item);
            }
            else
                printf("List is empty.\n\n");
            break;
        case 5: // delete at beginning
            // if list is not empty
            if (!isEmpty(head))
            {
                printf("Enter a character: ");
                scanf("\n%c", &item);
                // if character is found, remove it
                deleteAtBeginning(&head);
                printf("%c deleted.\n", item);
                printList(head);
            }
            else
                printf("List is empty.\n\n");
            break;
        default:
            printf("Invalid choice.\n\n");
            printf("Enter your choice:\n"
                   "   1 to insert an element into the list in alphabetic order.\n"
                   "   2 to insert an element at the end of the list.\n"
                   "   3 to insert an element at the beginning of the list.\n"
                   "   4 to delete an element from the list.\n"
                   "   5 to delete an element from the beginning of the list.\n"
                   "   6 to end.\n");
            printf(":: ");
            break;
        } // end switch
        printf("? ");
        scanf("%d", &choice);
    } // end while

    printf("End of run.\n");
}

void insertAtBeginning(ListNodePtr *head, char value)
{
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data = value;
    new_node->nextPtr = *head;
    *head = new_node;
}

void insertAtEnd(ListNodePtr *head, char value)
{
    ListNodePtr current = *head;
    if (current != NULL)
    {
        while (current->nextPtr != NULL)
            current = current->nextPtr;
        // now we are in the end of the list and we can add new variable
        current->nextPtr = malloc(sizeof(node_t));
        current->nextPtr->data = value;
        current->nextPtr->nextPtr = NULL;
    }
    // current (head) is null so:
    else
    {
        current = malloc(sizeof(node_t));
        current->data = value;
        current->nextPtr = NULL;
        *head = current;
    }
}

// insert in alphabetic order
void insert(ListNodePtr *head, char value)
{
    ListNodePtr newPtr;              // pointer to new node
    ListNodePtr previousPtr;         // pointer to previous node in list
    ListNodePtr currentPtr;          // pointer to current node in list
    newPtr = malloc(sizeof(node_t)); // create node

    if (newPtr != NULL)
    { // is space available
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        previousPtr = NULL;
        currentPtr = *head;
        // loop to find correct location in the list
        while ((currentPtr != NULL) && (value > currentPtr->data))
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        // insert new node at the beginning of list
        if (previousPtr == NULL)
        {
            newPtr->nextPtr = *head;
            *head = newPtr;
        }
        else
        { // insert new node between previousPtr and currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
        printf("%c not inserted. No memory available.\n", value);
}

void deleteAtBeginning(ListNodePtr *head)
{
    ListNodePtr tempPtr = NULL; // temporary node pointer
    if (head == NULL)
        return;
    else
    {
        tempPtr = *head;          // hold onto node being removed
        *head = (*head)->nextPtr; // de-thread the node
        free(tempPtr);            // free the de-threaded node
        tempPtr = NULL;           // to clear the data in the memory (Jason the teacher not does that)
    }
}

char delete (ListNodePtr *head, char value)
{
    ListNodePtr previousPtr; // pointer to previous node in list
    ListNodePtr currentPtr;  // pointer to current node in list
    ListNodePtr tempPtr;     // temporary node pointer
    // delete first node
    if (value == (*head)->data)
    {
        tempPtr = *head;
        *head = (*head)->nextPtr;
        free(tempPtr);
        tempPtr = NULL;
        return value;
    }
    else
    {
        previousPtr = *head;
        currentPtr = (*head)->nextPtr;
        // loop to find correct location in the list
        while ((currentPtr != NULL) && (currentPtr->data != value))
        {
            previousPtr->nextPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        // delete node at currentPtr
        if (currentPtr != NULL)
        {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            tempPtr = NULL;
            return value;
        }

    } // end else

    return '\0';
}

void printList(ListNodePtr currentPtr)
{
    // if list is empty
    if (currentPtr == NULL)
        printf("List is empty.\n\n");
    else
        printf("The list is: \n");

    while (currentPtr != NULL)
    {
        printf("%c --> ", currentPtr->data);
        currentPtr = currentPtr->nextPtr;
    }
    printf("NULL\n\n");
}

int isEmpty(ListNodePtr head)
{
    return (head == NULL);
}