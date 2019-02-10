//c++ program to implement stacks using arrays
#include <iostream>
using namespace std;

class StackArr
{
	public:
		int stack[50];
		int top,n;
		
		StackArr()
		{
			top=-1;
			n=50;
		}
		//ti insert an element into 1st position of stack
		void push(int val) 
		{
   			if(top>=n-1)
      			cout<<"Stack Overflow"<<endl; 
      		else
      		{
   				top++;
      			stack[top]=val;
      		}
   		}
		//to delete an element from 1st position of stack
		void pop()
		{
			if(top<=-1)
      			cout<<"Stack Underflow"<<endl;
  			else
			{
      			cout<<"The popped element is "<< stack[top] <<endl;
      			top--;
   			}
		}
		//to determine the size of stack
		int size()
		{
		    if(top == -1)
				return 0;
			//stores the no. of elements
			int no = 0;
			for(int i=0;stack[i]!=stack[top];i++)
			{
				no++;
			}
			return no+1;
		}
		//to determine if the stack is empty
		bool isEmpty()
		{
			if(top<0)
				return true;
			else
				return false;
		}
		//to determine the top element of stack
		int topp()
		{
			if(top<0)
				cout<<"No top element as stack is empty"<<endl;
			else
			{
				cout<<"The top element of the stack is: "<<stack[top]<<endl;
			}
		}
		//to display the entire stack
		void display()
		{
   			if(top>=0)
			{
      			for(int i=top; i>=0; i--)
         			cout<<stack[i]<<"->";
         		cout<<endl;
   			}
			else
      			cout<<"Stack is empty"<<endl;
		}
};

int main()
{
	StackArr s1;
	for(int i=1;i<11;i++)
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
