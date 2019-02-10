//c++ program to implement queues using arrays

#include <iostream>
using namespace std;

class QueueArr
{
	public:
	int queue[50];
	int front, end, n;
	QueueArr()
	{
		front=-1;
		end=-1;
		n=50;
	}
	void enqueue(int val)
	{
		if (end == n - 1)
			cout<<"Queue Overflow"<<endl;
		else
		{
			if(front==-1)
				front=0;
			end++;
			queue[end]=val;
		}
	}
	void dequeue()
	{
    	if (front == - 1 || front > end)
		{
			cout<<"Queue Underflow"<<endl;
   			return ;
   		}
		else
		{
      		cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      		front++;;
   		}
	}
	//to determine the size of queue
	int size()
	{
		if(end == -1)
			cout<<"empty"<<endl;

		int no = 0;
		int i=front;
		while(i!=end)
		{
			no++;
			i++;
		}

		return no+1;
	}
	//to determine if the queue is empty
	bool isEmpty()
	{
		if(front<0)
			return true;
		else
			return false;
	}
	//to determine the top element of stack
	int topp()
	{
		if(front<0)
			cout<<"No top element as queue is empty"<<endl;
		else
		{
			cout<<"The top element of the queue is: "<<queue[front]<<endl;
		}
	}
	//to display the entire queue
	void display()
	{
   		if (front == - 1)
   			cout<<"Queue is empty"<<endl;
   		else
		{
      		cout<<"Queue elements are : ";
      		for (int i = front; i <= end; i++)
         		cout<<queue[i]<<" ";
      		cout<<endl;
	   	}
	}
};

int main()
{
	QueueArr s1;
	for(int i=1;i<11;i++)
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
	
	s1.topp();
	cout<<endl;
	
	for(int i=1;i<4;i++)
	{
		s1.dequeue();
	}
	cout<<"After deleting 3 elements of the queue ";
	cout<<"the queue now is: "<<endl;
	s1.display();
	cout<<endl;
	
	cout<<"The queue is empty:"<<s1.isEmpty()<<endl;
	cout<<endl;
	
	cout<<"The size of the queue is: "<<s1.size()<<endl;
	cout<<endl;
	
	s1.topp();
	cout<<endl;
	
	return 0;
}

