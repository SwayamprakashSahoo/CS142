//c++ program to implement stacks using single linked list
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
//class to implement stacks
class StackLL
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
	void pop()
	{
    	Node *temp=top;
		top=temp->next;
		temp->next=NULL;
		delete temp;
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
    //to determine the top element in syack and display it
    void topp()
    {
    	if(top==NULL)
    		cout<<"no element in list"<<endl;
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
};

int main()
{
	StackLL s1;
	for(int i=0;i<10;i++)
	{
		s1.push(i);
	}
	cout<<"The stack now is: "<<endl;
	s1.display();
	cout<<endl;
	
	cout<<"The stack is empty:"<<s1.isEmpty()<<endl;
	cout<<endl;
	
	cout<<"The size of the stack is: "<<s1.size()<<endl;
	cout<<endl;
	
	s1.topp();
	cout<<endl;
	
	for(int i=1;i<4;i++)
	{
		s1.pop();
	}
	cout<<"After popping 3 elements of the stack ";
	cout<<"the stack now is: "<<endl;
	s1.display();
	cout<<endl;
	
	cout<<"The stack is empty:"<<s1.isEmpty()<<endl;
	cout<<endl;
	
	cout<<"The size of the stack is: "<<s1.size()<<endl;
	cout<<endl;
	
	s1.topp();
	cout<<endl;
	
	return 0;
}
