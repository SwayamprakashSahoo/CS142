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
		data=0;
		next=NULL;
	}
};
//class to implement stacks
class Stack
{
	public:
	Node *top= NULL;
	//to push or insert a value to 1st position in stack
	void push(int val)
	{
		Node *temp = new Node;
		temp->data = val;
		if(top==NULL)
		{
			top=temp;
		}
		else
		{
	        temp->next=top;
	        top=temp;
		}
	}
	//to pop or removes the first element of stack
	int pop()
	{
    	int popped=0;
        if(isEmpty()==true)//if the stack is empty
        	return -1;
        else 
        {
            Node* temp=top;
            popped=temp->data;
            top=top->next;
            temp->next=NULL;
            delete temp;
            return popped;
        }
	}
	//to determine the size of stack
	int size()
	{
	    int i=0;
	   	Node *current=top;
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
        if(top == NULL) 
	    	return true;
	    else
        	return false;
    }
    //to determine the top element in stack and display it
    void topp()
    {
    	if(top==NULL)
    		cout<<"no element in stack"<<endl;     	
		else
    		cout<<"top element: "<<top->data<<endl;
	}
	//to display the entire stack
	void display()
	{
		Node *current=top;
		while(current!=NULL)
		{
			cout<<current->data<<"->";
			current=current->next;
		}
		cout<<endl;
	}
	//to print the elements of the stack in the reverse order
	void displayRev()
	{
		displayRev(top);
	}
	void displayRev(Node *temp)
    {
        if(temp->next==NULL)
        	cout<<temp->data<<"->";
        else
        {
            displayRev(temp->next);
            cout<<temp->data<<"->";
        }
       // cout<<endl;
    }
};
//class to implement a queue using a stack
class QUS
{
    public:
    Stack s1;
    void enqueue(int a)
    {
		s1.push(a);
    }
    void dequeue()
    {
		if(s1.size()==0)//queue is empty. so there is nothing to dequeue
        	cout<<"Stack Underflow."<<endl;
		else if(s1.size()==1)
		{
			cout<<endl;
			cout<<"dequeued element="<<s1.pop()<<endl;
		}
        else
		{
	    	int poppedValue=s1.pop();
	    	dequeue();
            s1.push(poppedValue);
		}
    }
    //to display the queue
    void display()
    {
        s1.displayRev();
    }
};

int main()
{
	QUS q1;
	for(int i=1;i<=10;i++)
		q1.enqueue(i);
	cout<<"the queue is"<<endl;
	q1.display();
	for(int i=1;i<=4;i++)
		q1.dequeue();
	cout<<"the queue is"<<endl;
	q1.display();
	return 0;
}
