#include <iostream>
using namespace std;

class Node
{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node()
    {
        next = NULL;
    }
};

class CSLL
{
    public:
    Node *head;
    Node *tail;
    CSLL()
    {
        head=NULL;
        tail=NULL;
    }
    // Inserts to the end of the linked list.
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
		
	    }
		
		//any other node including second
		else
		{
			temp->next=head;
	       tail->next=temp;
	    }
	    tail=temp;
	}
    // Displays the linked list.
    void display()
    {
        Node * current = head;
        if(current == NULL) 
        {
            cout << "No elements " << endl;
            return;
        }
        while(current->next != head)
        { // Stopping at head
            cout << current -> data << "->";
            current = current -> next;
        }
        // Printing the last element
        cout << current -> data ;
        cout << endl;
    }
    //insert the node at a particular position
    void InsertAt(int pos, int value)
    {
        //to count the Number of items.
        int i=0;
	   	Node *current=head;
		while (current->next!=head)
		{
		    i++;
		    current=current->next;
		}
		
		if(pos>i+1 || pos<1)
		{
		    cout<<"Linked List does not have that many elements"<<endl;
		}
		else
		{
			//for 1st position
			if(pos==1)
			{
				Node *temp = new Node;
				temp->data = value;
	            tail->next = temp;
				temp->next = head;
				head = temp;
			}
			//for other positions	
			else
			{

				Node *temp = new Node;
				temp->data = value;
				//moving current pointer to required position
				Node *current = head;
				int i = 1;
				while(i<pos-1)
				{
					i++;
					current = current->next;
				}
				//changing links
				temp->next = current->next;
				current->next = temp;
			}
		}
    }
    //to delete a node from the asked position
    void DeleteAt(int pos)
    {
        //for positions other than 1st node	
		if(pos!=1)
		{
			//moving current pointer to required position
			Node *current = head;
			int i = 1;
			while(i<pos-1)
			{
				i++;
				current = current->next;
			}
				
			//to delete the next node
			Node *temp = new Node;
			temp = current->next;
			current->next = temp->next;
			//delete temp
			delete temp;
		}
		//for 1st node
		else
		{
			Node *temp = head;   //initialise temp with head to create a new link
			tail->next = head->next;
			head = head->next;
			//delete temp
			delete temp;
		}
		
    }
    //to delete the last node in the list
    void Delet()
    {
        //assigning new node
		Node *current = head;
		Node *temp = tail;
		//reaching required position i.e. before tail
		while(current->next != tail)
		{
			current = current->next;
		}
		current->next = head;
		tail = current;
			
		//delete temp
		delete temp;
    }
    //to count the number of nodes in the list
    int CountItems()
    {
        // Counts the Number of items.
        int i=0;
	   	Node *current=head;
		while (current->next!=head)
		{
		    i++;
		    current=current->next;
		}
		return i+1;
	}

};

int main()
{
    CSLL csll1;
     for(int i=1;i<9;i++)
    {
        csll1.insert(i);
    }
  
    csll1.display();
    cout<<"The no. of nodes before deletion="<<csll1.CountItems()<<endl;
    cout<<endl;
    
    //Delet() function
    cout<<"After deleting last element:-"<<endl;
    csll1.Delet();
    csll1.display();
    cout<<"The no. of nodes after deletion="<<csll1.CountItems()<<endl;
    cout<<endl;
    
    //InsertAt() function
    cout<<"After inserting a node at a 1st position:-"<<endl;
    csll1.InsertAt(1,15);
    csll1.display();
    cout<<"The no. of nodes after inserting at the asked position= "<<csll1.CountItems()<<endl;
    cout<<endl;
    
    cout<<"After inserting at particular position(invalid ex:-1):-"<<endl;
    csll1.InsertAt(-1,12);
    csll1.display();
    cout<<"The no. of nodes after inserting at the asked position= "<<csll1.CountItems()<<endl;
    cout<<endl;
    
    cout<<"After inserting at particular position(invalid ex:12)"<<endl;
    csll1.InsertAt(12,14);
    csll1.display();
    cout<<"The no. of nodes after inserting at the asked position= "<<csll1.CountItems()<<endl;
    cout<<endl;
    
    cout<<"After inserting at particular position(valid ex:2):-"<<endl;
    csll1.InsertAt(2,5);
    csll1.display();
    cout<<"The no. of nodes after inserting at the asked position= "<<csll1.CountItems()<<endl;
    cout<<endl;
    
    //DeleteAt()
    cout<<"After deletion at particular position(valid ex:1):-"<<endl;
    csll1.DeleteAt(1);
    csll1.display();
    cout<<"The no. of nodes after deleting at the particular position= "<<csll1.CountItems()<<endl;
    cout<<endl;
    
    cout<<"After deletion at a particular position(valid ex:3):-"<<endl;
    csll1.DeleteAt(3);
    csll1.display();
    cout<<"The number of nodes after deleting at the asked position="<<csll1.CountItems()<<endl;
    cout<<endl;
    
    return 0;
}
