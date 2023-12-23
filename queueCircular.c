#include "queueCircular.h"

int DEQUEUE_STATUS = -1;

void checkNull(void *ptr)
{
    if (ptr == NULL)
    {
        printf("Memory can't be allocated");
        exit(EXIT_FAILURE);
    }
}

Queue *initializeQueue(int size)
{
    Queue *q = malloc(sizeof(Queue));
    checkNull(q);
    q->size = size;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    checkNull(q->arr);

    return q;
}

int isFull(Queue *q)
{
    // if rear + 1 == front
    return ((q->rear + 1) % q->size == q->front);
}

int isEmpty(Queue *q)
{
    return q->rear == q->front;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        // printf("%d %d\n\n",q->front, q->rear);
        printf("Queue overflow\n");
        return;
    }
    
    if(isEmpty(q))
        q->front = 0;

    q->rear = (q->rear+1) % q->size; // circular increment
    q->arr[q->rear] = value;
}

int dequeue(Queue *q)
{
    int status = DEQUEUE_STATUS;
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
    }
    else
    {
        if (q->front == (q->rear + 1) % q->size)
        {
            // If there was only one element in the queue
            q->front = q->rear = -1;
        }
    }
    return status;

    // on failure returns -1 or user defined value else return the dequeued value
}

void display(Queue *q)
{
    // initializing with front index
    int i = q->front;

    do{
        printf("%d ",q->arr[i]);
        i = (i + 1) % q->size;
    }while(i != (q->rear + 1) % q->size);
}