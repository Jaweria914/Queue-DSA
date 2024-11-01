#include<iostream>
using namespace std;
class queue{
	public:
	 int marks;
    queue *next;
    
    queue(){
    	marks=0;
    	next=NULL;
	}
};
class linkqueue{
	public:
   
	queue *front;
	queue *rear;
	
	
	linkqueue(){
		front=NULL;
		rear=NULL;
	}
	void enqueue(int value){
		queue *newnode =new queue;
		newnode->marks=value;
		
		if(rear == NULL){
			front=rear=newnode;
			rear->next=front;
			return;
    		}
    		else{
    		rear->next=newnode;
    		rear=newnode;
    		rear->next=front;
			}
    }
	void dequeue(){
		if( front == NULL){
			cout<<"Queue Underflow, Cannot Dequeue."<<endl;
	    }
	    if(front == rear){
	    	delete front;
	    	front = rear = NULL;
		}
		else{
			queue *temp=front;
			front=front->next;
			rear->next=front;
			delete temp;
		}
	}
		void display(){
			queue *d =front;
			cout<<"Queue Elements: "<<endl;
			do{
				cout<<d->marks<<endl;
				d=d->next;
			}while(d!=front);
		}
		
		
};
int main(){
	linkqueue lq;
	lq.enqueue(10);
	lq.enqueue(20);
	lq.enqueue(30);
	lq.enqueue(40);
	lq.display();
	lq.dequeue();
	lq.display();
	
	
}
