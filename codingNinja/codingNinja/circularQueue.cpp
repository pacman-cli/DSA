#include <bits/stdc++.h>
class CircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure.
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        rear = front = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack,
    // and false otherwise.
    bool enqueue(int value)
    {
        // condition 1: check queue is full or not
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            // cout << "Queue is full";
            return false;
        }
        // condition 2: first element element to push, empty queue
        else if (front == -1)
        {
            front = rear = 0;
            // arr[rear] = value;
        }
        // condition 3: if front is somewhere in the middle and rear is in the last of the
        //  array then insert next would be in the empty spaces which is before front and first index
        //  then it will be circular
        else if (rear == size - 1 && front != 0)
        {
            rear = 0; // to maintain the cyclic nature
            // arr[rear] = value;
        }
        else
        {
            rear++; // normal flow
            // arr[rear] = value;
        }
        arr[rear] = value; // push inside the queue
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty,
    // otherwise returns the popped element.
    int dequeue()
    {
        if (front == -1)
        {
            // cout << "Queue is Empty";
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
        {
            front = rear = -1; // single element
        }
        else if (front == size - 1)
        {
            front = 0; // to maintain the cyclic nature
        }
        else
        {
            front++;
        }

        return ans;
    }
};
