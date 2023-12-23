#include "queueCircular.h"

int main()
{
    Queue *q = initializeQueue(5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printf("Index of rear: %d and value: %d\n\n", q->rear, q->arr[q->rear]);
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    printf("\nIndex of rear: %d and value: %d\nIndex of front: %d\n", q->rear, q->arr[q->rear], q->front);
    display(q);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("\nIndex of rear: %d and value: %d\nIndex of front: %d\n", q->rear, q->arr[q->rear], q->front);
    display(q);
    return 0;
}