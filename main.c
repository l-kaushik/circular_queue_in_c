#include "queueCircular.h"

int main()
{
    Queue *q = initializeQueue(5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    display(q);
    return 0;
}