#ifndef QUEUE_CIRCULAR_H
#define QUEUE_CIRCULAR_H

#include <stdio.h>
#include <stdlib.h>

// global variables
extern int DEQUEUE_STATUS;

// structure declaration
typedef struct Queue
{
    int size;
    int front; // indicating an empty index
    int rear;  // indicating the last filled index
    int *arr;
} Queue;

// initialize the queue with given size
Queue *initializeQueue(int size);

// check if queue is full or not
int isFull(Queue *q);

// enqueue into queue
void enqueue(Queue *q, int value);

// check if queue is empty or not
int isEmpty(Queue *q);

// dequeue an element from queue
int dequeue(Queue *q);

// display all elements of the queue
void display(Queue *q);

#endif