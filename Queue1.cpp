#include<iostream>
using namespace std;

class Queue 
{
private:
    int front, rear, size;
    int* queueArray;

public:
   
    Queue(int s) 
	{
        front = -1; 
        rear = -1;   
        size = s;
        queueArray = new int[size];
    }
    ~Queue()
	 {
        delete[] queueArray;
    }
    void enqueue(int value) 
	{
        if (rear == size - 1) 
		{
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1) 
		{
            front = 0; 
        }
        rear++;
        queueArray[rear] = value;
        cout << value << " enqueued into the queue." << endl;
    }

    // Dequeue 
    void dequeue()
	 {
        if (front == -1 || front > rear) 
		{
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << queueArray[front] << " dequeued from the queue." << endl;
        front++;
        // Reset 
        if (front > rear)
		 {
            front = rear = -1;
        }
    }

    // Display the queue
    void display() 
	{
        if (front == -1)
		 {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) 
		{
            cout << queueArray[i] << " ";
        }
        cout << endl;
    }
};

int main() 
{
    Queue q(5);  // Creating a queue of size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);  // This will show "Queue is full!"

    q.display();  // Displays the queue

    q.dequeue();  // Removes 10
    q.dequeue();  // Removes 20

    q.display();  // Displays the remaining elements

    return 0;
}
