#include "queue.h"
#include <stdexcept>

void init(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(const Queue* q) {
    return q->front == -1;
}

bool isFull(const Queue* q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw std::overflow_error("Queue Overflow: Kapasitas penuh");
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("Queue Underflow: Antrean kosong");
    }
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("Antrean kosong");
    }
    return q->data[q->front];
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw std::underflow_error("Antrean kosong");
    }
    return q->data[q->rear];
}
