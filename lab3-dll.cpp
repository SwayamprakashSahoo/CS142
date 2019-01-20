//Implementation of Doubly Linked List using C++
#include <iostream>

using namespace std;
class Node
{
    public:
    //Data
    int data;
    //Pointer to the next Node and prev Node
    Node *next;
    Node *prev;
    //Constructor to make pointers next and prev to null
    Node()
    {
        next=NULL;
        prev=NULL;
    }
};
class LinkedList
{
    public:
    //Head-> circle type ptr
    Node *head;
    Node *tail;
    //Constructor
    LinkedList()
    {
        head=NULL;
        tail=NULL;
    }
    //Inserting a new node
    void insert(int value)
    {
        //1st Node is added
        Node *temp=new Node();
        //Insert data in node
        temp->data=value;
        //1st node only
        if(head==NULL)
        {
            head=temp;
        }
        //for any other node
        else
        {
            temp->prev=tail;
            tail->next=temp;
        }
        tail=temp;
    }
    //Insert at a particular position 
    void InsertAt(int pos,int data)
    {
        //finding number of nodes
        int i=0;
	   	Node *count=head;
		while (count!=NULL)
		{
		    i++;
		    count=count->next;
		}
        if(pos>0 && pos<=i)
        {
            //for 1st position
            if(pos==1)
            {
                Node *current=head;
                Node *temp=new Node();
                temp->data=data;
                temp->next=current;
                current->prev=temp;
                head=temp;
            }
            else
            {
                //to reach the required position
                Node *current=head;
                int j=1;
                while(j<pos-1)
                {
                   j++;
                   current=current->next;
                }
                //Creating new node
                Node *temp=new Node();
                temp->data=data;
                temp->next=current->next;
                current->next=temp;
                temp->next->prev=temp;
                temp->prev=current;
            }
        }
        else
        {
            cout<<"Linked List does not have that many elements."<<endl;
        }
    }
    //Deleting last element
    void delet()
    {
        //store tail in temp
        Node *temp=tail;
        //before tail has to point to NULL
        Node *current=head;
        //to reach the penultimate position
        while(current->next!=tail)
        {
            current=current->next;
        }
        current->next=NULL;
        temp->prev=NULL;
        //update tail
        tail=current;
        //delete temp
        delete temp;
    }
    //Delete at a particular position
    void deleteAt(int pos)
    {
        //finding the number of nodes
        int i=0;
	   	Node *count=head;
		while (count!=NULL)
		{
		    i++;
		    count=count->next;
		}
        //Put condition for position
        if(pos>0 && pos<=i)
        {
            //If pos is 1st position
            if(pos==1)
            {
                Node *temp=head;
                head=head->next;
                temp->next=NULL;
                head->prev=NULL;
                delete temp;
            }
            else
            {
                //to reach the required position
                Node *current=head;
                int j=1;
                while(j<pos-1)
                {
                   j++;
                   current=current->next;
                }
                //copy the node to be deleted
                Node *temp=current->next;
                current->next->next->prev=current;
                current->next=current->next->next;
                temp->next=NULL;
                temp->prev=NULL;
                delete temp;
            }
        }
        else
        {
            cout<<"Linked List does not have that many elements."<<endl;
        }
    }
    //count items
    int countItems()
    {
        Node *current=head;
        int count=0;
        while(current!=NULL)
        {
            count++;
            current=current->next;
        }
        return count;
    }
    //Display
     void display()
    {
        Node *current=head;
        Node *last;
        while(current!=NULL)
        {
            cout<<current->data<<"->";
            last=current;
            current=current->next;
        }
        cout<<"NULL"<<endl;
        cout<<endl;
        cout << "Print in Reverse order : "<<endl;
        while(last!=NULL)
        {
            cout <<last->data<< "->";
            // Move backwards 
            last = last->prev;
        }
        cout <<"NULL"<< endl;
    }
};

int main()
{
    //Object of the class
    LinkedList l1;
    //creating several nodes
    for(int i=1;i<9;i++)
    {
        l1.insert(i);
    }
  
    l1.display();
    cout<<"The no. of nodes before deletion="<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"After deleting last element:-"<<endl;
    l1.delet();
    l1.display();
    cout<<"The no. of nodes after deletion="<<l1.countItems()<<endl;
    cout<<endl;
    
    //various options using insertAt function
    cout<<"After inserting a node at a 1st position:-"<<endl;
    l1.InsertAt(1,15);
    l1.display();
    cout<<"The no. of nodes after inserting at the asked position= "<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"After inserting at particular position(invalid ex:-1):-"<<endl;
    l1.InsertAt(-11,12);
    l1.display();
    cout<<"The no. of nodes after inserting at the asked position= "<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"After inserting at particular position(invalid ex:12)"<<endl;
    l1.InsertAt(12,14);
    l1.display();
    cout<<"The no. of nodes after inserting at the asked position= "<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"After inserting at particular position(valid ex:2):-"<<endl;
    l1.InsertAt(2,5);
    l1.display();
    cout<<"The no. of nodes after inserting at the asked position= "<<l1.countItems()<<endl;
    cout<<endl;
    
    //various options using deleteAt function
    cout<<"After deletion at particular position(valid ex:1):-"<<endl;
    l1.deleteAt(1);
    l1.display();
    cout<<"The no. of nodes after deleting at the particular position= "<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"After deletion at a particular position(invalid ex:-5):-"<<endl;
    l1.deleteAt(-5);
    l1.display();
    cout<<"The no. of nodes after deleting at the particular position= "<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"After deletion at a particular position(invalid ex-14):-"<<endl;
    l1.deleteAt(14);
    l1.display();
    cout<<"The no. of nodes after deleting at the  particular position="<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"After deletion at a particular position(valid ex:3):-"<<endl;
    l1.deleteAt(3);//use of deleteAt
    l1.display();
    cout<<"The number of nodes after deleting at the asked position="<<l1.countItems()<<endl;
    cout<<endl;
    
    return 0;
}

