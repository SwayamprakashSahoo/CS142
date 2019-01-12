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
class LinkedList
{
	//head+circles inside linked with each other
	public:
	//head->circle type pointer
	Node *head;
	Node *tail;
	//constructor
	LinkedList()
	{
		head=NULL;
		tail=NULL;
	}
	//circles inside linked with each other
	//rules how circles will be linked
	//insert
	void insert(int value)
	{
		//if 1st node is added
		Node *temp = new Node;
		//insert data in the node
		temp->data=value;
		//1st node only
		if(head==NULL)
		{
		   head=temp;
		   //tail=temp;
	    }
		//2nd node only
		//head->next = temp;
		
		//any other node including second
		else
		{
	       tail->next=temp;
	    }
	    tail=temp;
	}
	//insert at a particular position
	void insertAt(int pos, int value)
	{
	    int i=0;
	   	Node *current=head;
		while (current!=NULL)
		{
		    i++;
		    current=current->next;
		}
		if(pos>i)
		{
		    cout<<"Linked List does not have that many elements"<<endl;
		}
		else
		{
	       //for inserting link at p1
	       if(pos==1)
	       {
	           Node *temp=new Node;
	           temp->data=value;
	           temp->next=head;
	           head=temp;
	       }
		   //other than p1 reach the place before the position
	   	   else
	       {
		       Node *temp=head;
	           int i=1;
		       while(i<pos-1)
		       {
		          temp=temp->next;
		          i++;
		       }
		       //create a node
		       Node *temp2=new Node;
		       temp2->data=value;
		       temp2->next=temp->next;
		       temp->next=temp2;
	       }
		}
	}
	//deletion
	void delet()
	{
		//store the tail in temp
		Node *temp=tail;
		//b4 tail has to point to null
		Node *current=head;
		while (current->next!=tail)
		{
	        current=current->next;
		}
		current->next=NULL;
		//update tail
		tail=current;
		
	}
	//delete from a particular position
	void deleteAt(int pos)
	{
	    Node *temp= new Node;
	    temp=head;
	    if(pos==1)
	    {
	        head=temp->next;
	        delete temp;
	    }
	    else
	    {
	        int i=1;
		    while(i<pos-1 && temp!=NULL)
		    {
		        temp=temp->next;
		        i++;
		    }
		    Node *next=temp->next->next;
		    //delete temp
		    delete temp->next;
		    temp->next=next;
		
	    }
	}
	//count the number of items
	void countItems()
	{
	    int i=0;
	   	Node *current=head;
		while (current!=NULL)
		{
		    i++;
		    current=current->next;
		}
		cout<<"The number of items in the linked list is "<<i<<endl;
	}
	//display
	void display()
	{
		Node *current=head;
		while (current!=NULL)
		{
			cout<<current->data<<"->";
	        current=current->next;
		}
		cout<<"NULL"<<endl;
	}
};
int main()
{
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
    l1.insert(3);
    l1.insert(4);
	l1.display();
	l1.countItems();
	l1.delet();
	l1.display();
	l1.deleteAt(1);
	l1.display();
    l1.insertAt(1,5);
	l1.display();
	l1.insert(11);
	l1.display();
    
	return 0;
}
