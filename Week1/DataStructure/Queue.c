#include <stdio.h>
#define SIZE 5  // Small fixed size for simplicity

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full (Overflow)\n");
        return;
    }

    if (front == -1) front = 0;

    rear++;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue operation
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty (Underflow)\n");
        return;
    }

    printf("Dequeued: %d\n", queue[front]);
    front++;
}

// Display the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60); // This should trigger overflow
    display();

    return 0;
}

