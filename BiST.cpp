//program to implement a binary search tree in c++

#include <iostream>
using namespace std;

class Node
{
	public:    
    int data;
    // Children
    Node * left;
    Node * right;

    Node(int val)				//parametrized constructor to initiat the variables and pointers
	{
       	data = val;
       	left = NULL;
       	right = NULL;
    }
};

//binary search class
class BiST
{
    public:
    Node *root;
    
    BiST()
    {
        root=NULL;
    }
    
    void insert(int value)								//function to insert a proper node in tree
    {
        insert2(root,value);
    }
    void insert2(Node *curr, int value)
    {
    	//at the beginning of the tree i.e. assigning value to root
        if(curr==NULL)
        {
            curr= new Node(value);
            if(root==NULL)
            root=curr;
            return;
        }
        
        else if(curr->data > value)						//entry to left portion
        {
            if(curr->left==NULL)
            {
               curr->left=new Node(value);//creating new node
            }
            else
               insert2(curr->left,value);// recursion
        }
        
        else											//entry to right portion
        {
            if(curr->right==NULL)
            {
                
               curr->right=new Node(value);//creating new node
            }
            else
               insert2(curr->right,value);// recursion
        }
    }
    
    void display()										//function to display the tree
    {
        display2(root);//recursion function
    }
    void display2(Node * curr)
    {
        if(curr==NULL)//if current position is null then return
        	return;
        display2(curr->left);//display the left data
        cout<<curr->data<<" ; ";
        display2(curr->right);//display the right data
    }
    
    void search(int value)								//function to search a given value in the tree
	{
		cout<<endl;
		Node *num;
		num = search2(root,value);
		if(num == NULL)
			cout<<"The requested number does not exist."<<endl;
		else
			cout<<"The number exists."<<endl;	
	}
	Node *search2(Node *curr,int value)
	{
		if(curr==NULL || curr->data==value)
			return curr;
			
		else if(value > curr->data)
			return search2(curr->right,value);
			
		else
			return search2(curr->left,value);		
	}
};

//declaring main function
int main()
{
	BiST B1;
	
	//inserting data
	for(int i=1; i<11; i++)
	{
		B1.insert(i);
	}
	
	//display
	B1.display();
	cout<<endl;
	
	int val;
	cout<<"Please enter a number to be searched in the list"<<endl;
	cin>>val;
	
	//search
	B1.search(val);
}
