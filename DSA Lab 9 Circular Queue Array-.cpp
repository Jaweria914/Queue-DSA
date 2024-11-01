#include <iostream>
using namespace std;
class CircularQueue 
{
private:
    int front, rear, size;
    int *arr;
public:
    CircularQueue(int s) 
	{
        size = s;
        arr = new int[size];
        front = rear = -1;
    }
    bool isFull() 
	{
        return (rear + 1) % size == front;
    }
    bool isEmpty() 
	{
        return front == -1;
    }
    void enqueue(int value) 
	{
        if (isFull()) 
		{
            cout << "Queue is full. " << value << " cannot be enqueued." << endl;
            return;
        }
        if (isEmpty()) 
		{
            front = rear = 0;
        } 
		else 
		{
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        cout << "Enqueued: "<<value<<endl;
    }
    void dequeue() 
	{
        if (isEmpty())
		{
            cout << "Queue is empty."<<endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) 
		{
            front = rear = -1; 
        } 
		else 
		{
            front = (front + 1) % size;
        }
    }
    void display() 
	{
        if (isEmpty()) 
		{
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) 
		{
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};
int main() 
{
    CircularQueue q(5);  
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(60);
    q.display();
    return 0;
}
