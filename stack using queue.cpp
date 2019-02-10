#include <iostream>
using namespace std;

class Node
{
	public:
	//data
	int data;
	//pointer to the next node
	Node *next;
	//construct that makes the pointer to null
	Node()
	{
		next=NULL;
	}
};
//class to implement queues

class Queue
{
	public:
 		Node *front;
 		Node *end;
 		QueueLL()
 		{
 			front=NULL;
 			end=NULL;
 		}
 		//to add element at start
 		void enqueue(int val)
		{
    		Node *temp = new Node;
    		temp->data = val;
    		temp->next = NULL;
    		if(front == NULL)
    		{
        		front=end=temp;
        		end->next=NULL;
    		}
    		else
    		{
        		end->next=temp;
            	end=temp;
        		end->next = NULL;
    		}
		}
		//to remove element from last
		int dequeue()
		{
			if(front==NULL)
				cout<<"The queue is empty"<<endl;
			else
			{
    			Node *temp=end;
 				Node *current=front;
 				while(current->next!=end)
 				{
 					current=current->next;
				}
				current->next=NULL;
				end=current;
				delete temp;
			}
		}
		//to determine the size of queue
		int size()
		{
	    	int i=0;
	   		Node *current=front;
			while (current!=NULL)
			{
		    	i++;
		    	current=current->next;
			}
			return i;
		}
		//to determine if stack is empty
		bool isEmpty()
		{
        	if(front == NULL) 
	    		return true;
	    	else
        		return false;
    	}
    	//to determine the top element in syack and display it
    	int top()
    	{
    		if(front==NULL)
    			return -1;
    		else
    			return front->data;
		}
		//to display the entire stack
		void display()
		{
			Node *current=front;
			while(current!=NULL)
			{
				cout<<current->data<<"->";
				current=current->next;
			}
			cout<<endl;
		}
};
//class to implement a stack using a queue
class SUQ
{
    public:
    Queue q1;
    void push(int num)
    {
		q1.enqueue(num);
		while(q1.top()!=num) 
			q1.enqueue(q1.dequeue());
    }
    int pop()
    {
		return q1.dequeue();
    }
    void display()
    {
	q1.display();
    }
};

int main()
{
	SUQ s1;
	for(int i=1;i<=10;i++)
		s1.push(i);
	cout<<"the stack is"<<endl;
	s1.display();
	for(int i=1;i<=4;i++)
		s1.pop();
	cout<<"the stack is"<<endl;
	s1.display();
	return 0;
}
