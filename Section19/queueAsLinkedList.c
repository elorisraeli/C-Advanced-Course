#include <stdio.h>
#include <stdlib.h>

struct QNode {
    int key;
    struct QNode* next;
};

struct Queue {
    struct QNode *front, *rear;
};

struct QNode* newNode(int k); // create space in memory for new node
struct Queue* createQueue(); // create space in memory for the queue
void enQueue(struct Queue* q, int k); // enter an element to queue rear
struct QNode* deQueue(struct Queue* q); // delete an element from the queue front

void main(){
    printf("Start.\n");
    struct Queue* q = createQueue();
    enQueue(q, 1);
    enQueue(q, 2);
    deQueue(q);
    deQueue(q);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);
    struct QNode* n = deQueue(q);
    if (n != NULL)
        printf("Dequeued item is: %d \n", n->key);
    
    printf("End.\n");
}

struct QNode* newNode(int k){
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, int k){
    struct QNode* temp = newNode(k);
    // if the queue is empty, front and rear are the node.
    if (q->rear == NULL){
        q->front = q->rear = temp;
        return;
    }
    // Add the new node at the end if queue and change the rear
    q->rear->next = temp;
    q->rear = temp;
}

struct QNode* deQueue(struct Queue* q){
    // is queue is empty return null
    if (q->front == NULL);
        return NULL;
    // store previous front and move one node ahead
    struct QNode* temp = q->front;
    q->front = q->front->next;
    // if front become null, than change rear also as null
    if (q->front == NULL)
        q->rear = NULL;
    return temp;
}