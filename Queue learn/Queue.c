#include "stdio.h"
#include "stdlib.h"
#define MAX_NUMBER 10

int num[MAX_NUMBER];
int front = -1;
int rear = -1;

int isFull () {
    if (rear == MAX_NUMBER - 1) {
        return 1;
    }
    return 0;
}
 
int isEmpty () {
    if (front == -1 || front > rear) {
        return 1;
    }
    return 0;
}

void insertData (int rear ) {
    if(rear==0) {
        return;
    }

    num[rear] = num[rear - 1];
    rear--;
    insertData(rear);
}

void enqueue (int data) {
    if (isFull()) {
        printf("Queue is full");
        return;
    } else {
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        int temp = rear;

        insertData(temp);
        num[front] = data;
        
    }
    
}

int dequeue () {
    if (isEmpty()) {
        printf("Queue is empty");
        exit(1);
    } else {
        int data = num[rear];
        
        num[rear] = 0;

        rear--;
        return data;
    }
}


void display(int arr[]) {
    

    
    for (int i = 0; i < MAX_NUMBER; i++) {
        printf("Element at index %d: %d\n", i, arr[i]);
    }

    
}

int main () {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display(num);
    dequeue();

    enqueue(5);

    printf("_______\n");

    display(num);
}