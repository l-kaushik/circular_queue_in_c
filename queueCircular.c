#include "queueCircular.h"

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
    q->front = q->rear = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    checkNull(q->arr);

    return q;
}

int isFull(Queue *q)
{
    // if rear + 1 == front
    if ((q->rear + 1) % q->size == q->front) 
        return 1;
    return 0;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue overflow\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size; // circular increment
        q->arr[q->rear] = value;
    }
}

int isEmpty(Queue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    return 0;
}

int dequeue(Queue *q)
{
    int status = -1; // return signal
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        status = q->arr[q->front];
    }
    return status;

    // on failure returns -1 else return the dequeued value
    // warning: if dequeued value is -1 and you checking for dequeue status then it may cause some error
}

void display(Queue *q)
{
    // initializing with front + 1 index
    int i = (q->front + 1) % q->size;

    if (isEmpty(q))
    {
        printf("Queue underflow\n");
        return;
    }
    while (i != q->rear + 1)
    {
        if (i > q->size - 1)
        {
            // skipping if points beyond the array
            i = (i + 1) % (q->size + 1);
        }
        printf("%d\t", q->arr[i]);

        i = (i + 1) % (q->size + 1);
    }
}