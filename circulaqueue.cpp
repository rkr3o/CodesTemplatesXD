#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
private:
    vector<int> arr;
    int size;
    int rear, front;

public:
    CircularQueue(int n)
    {
        arr.resize(n);
        size = n;
        front = rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1 and rear == -1)
            return true;

        return false;
    }

    bool isFull()
    {
        if (front == 0 and rear == size - 1 || rear == (front - 1) % size - 1)
        {
            return true;
        }
        return false;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 and front != 0)
        {
            rear = 0 ;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        if (front == rear)
        {
            front = rear = -1; // Reset the queue when the last element is dequeued.
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else {
            front++;
        }
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No rear element." << endl;
            return -1;
        }

        return arr[rear];
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }

        return arr[front];
    }
};

int main()
{
    CircularQueue cq(5);

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);

    cout << "Front: " << cq.getFront() << endl; // Output: 1
    cout << "Rear: " << cq.getRear() << endl;   // Output: 4

    cq.dequeue();
    cq.dequeue();

    cout << "Front: " << cq.getFront() << endl; // Output: 3
    cout << "Rear: " << cq.getRear() << endl;   // Output: 4

    cq.enqueue(5);
    cq.enqueue(6);
    cq.enqueue(7); // This will give a message: "Queue is full. Cannot enqueue."

    return 0;
}
