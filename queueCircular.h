#ifndef QUEUE_CIRCULAR_H
#define QUEUE_CIRCULAR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int front; // indicating an empty index
    int rear;  // indicating the last filled index
    int *arr;
} Queue;

#endif