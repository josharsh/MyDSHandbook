#include <iostream>
using namespace std;
int n = 10;
int a[10], front = -1, rear = -1;

void enqueue(int x) {
    cout << "head :" << front << endl;
    cout << "tail :" << rear << endl;
    //check if array is full
    if ((rear + 1) % n == front) {
        cout << x << " cannot be inserted. Array is full" << endl;
        return;
    }

    //check if array is empty
    if (front == rear && rear == -1) {
        front = rear = 0;
        a[rear] = x;
        return;
    }

    rear = (rear + 1) % n;
    a[rear] = x;


}

void printArray() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}

void deque() {
    //check if array is empty
    if (rear == -1) {
        return;
    } else if (front == rear && front == 0) {
        front = rear = -1;
    } else {
        front = (front + 1) % n;
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    deque();
    deque();
    enqueue(11);
    enqueue(10);
    printArray();
    return 0;
}
