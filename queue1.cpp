//c++ program to implement queues using single linked list
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

class QueueLL
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
    	void top()
    	{
    		if(front==NULL)
    			cout<<"no element in list"<<endl;
    		else
    			cout<<"top element: "<<front->data<<endl;
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

int main()
{
	QueueLL s1;
	for(int i=1;i<=10;i++)
	{
		s1.enqueue(i);
	}
	cout<<"The queue now is: "<<endl;
	s1.display();
	cout<<endl;
	
	cout<<"The queue is empty:"<<s1.isEmpty()<<endl;
	cout<<endl;
	
	cout<<"The size of the queue is: "<<s1.size()<<endl;
	cout<<endl;
	
	s1.top();
	cout<<endl;
	
	for(int i=1;i<4;i++)
	{
		s1.dequeue();
	}
	cout<<"After popping 3 elements of the queue ";
	cout<<"the queue now is: "<<endl;
	s1.display();
	cout<<endl;
	
	cout<<"The queue is empty:"<<s1.isEmpty()<<endl;
	cout<<endl;
	
	cout<<"The size of the queue is: "<<s1.size()<<endl;
	cout<<endl;
	
	s1.top();
	cout<<endl;
	
	return 0;
}
