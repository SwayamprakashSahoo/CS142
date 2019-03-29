//program to implement a binary search tree in c++ with some new functions

#include <iostream>
using namespace std;

class Node
{
	public:    
    int data;
    // Children
    Node * left;
    Node * right;
    Node * parent;

    Node(int val)				//parametrized constructor to initiat the variables and pointers
	{
       	data = val;
       	left = NULL;
       	right = NULL;
       	parent = NULL;
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
               curr->left->parent= curr;
            }
            else
               insert2(curr->left,value);// recursion
        }
        
        else											//entry to right portion
        {
            if(curr->right==NULL)
            {
                curr->right=new Node(value);//creating new node
                curr->right->parent= curr;
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
    
   Node *search(int value)									//function to search for a given value in tree
    {
        return search2(root,value);//retruns node
    }
    Node *search2(Node * curr,int value)
    {
        if(curr==NULL || value==curr->data)//node obtained
            return curr;
        else if(value > curr->data)//search right side
            search2(curr->right,value);
        else//search left side
            search2(curr->left,value);
    }
    
	Node *find_min(Node *curr)							//function to get minimum node in subtree
    {
        if(curr!=NULL)//initial position
        {
            while(curr->left!=NULL)//lesser value always exists on left side of tree
            {
                curr=curr->left;
            }
        }
        return curr;
    }
    
    void replace_At_Parent(Node *A,Node *B)				//function to replace A with B at the parent of A
    {
        
        B->parent=A->parent;//change the parent
        //checks the side B is on as the child of A and links A's parent with B
        if(A->parent->data > A->data)
        {
            A->parent->left=B;
        }
        else
        {
            A->parent->right=B;
        }
        B=A;
        A->parent=NULL;
        A->left=NULL;
        A->right=NULL;
    }
    //Swapping the value of the two nodes
    void swap(Node * A,Node * B)
    {
        int temp=A->data;
        A->data=B->data;
        B->data=temp;
    }
    
    void deleteNode(int value)
    {
        if(search(value)!=NULL)//checks presence of value in tree
        {
            if(root->data!=value)//case 1: root doesnot need to be deleted
            {
                Node *curr=search(value);
                if(curr->left==NULL && curr->right==NULL)//node to be deleted is a leaf node
                {
                    if(curr->parent->data < curr->data)
                    {
                        curr->parent->right=NULL;
                    }
                    else
                    {
                        curr->parent->left=NULL;
                    }
                    curr->parent=NULL;
                    delete curr;
                }
                else if(curr->left!=NULL && curr->right==NULL)//node to be deleted has only left branch
                {
                    replace_At_Parent(curr,curr->left);
                    delete curr;
                }
                else if(curr->left==NULL && curr->right!=NULL)//node to be deleted has only right branch
                {
                    replace_At_Parent(curr,curr->right);
                    delete curr;
                }
                else //node to be deleted has both left and right branching
                {
                	//making it so the node can fulfill any of above 3 cases
                    swap(curr,find_min(curr->right));
                    curr=find_min(curr->right);
                    if(curr->right!=NULL)//if curr has right branching
                    {
                        curr->parent->right=curr->right;
                        curr->right->parent=curr->parent;
                        curr->right=NULL;
                    }
                    else
                    {
                        //if curr is a leaf node and has higher value than parent i.e. present at its parent's right
                        if(curr->parent->right->data==curr->data)
                        {
                            curr->parent->right=NULL;
                        }
                        else
                        {
                            curr->parent->left=NULL;
                        }
                    }
                    curr->parent=NULL;
                    delete curr;
                }
                    
            }
            else //case 2: node to be deleted is the root node
            {
                Node * curr=root;
                //all other conditions same as in case 1
                if(curr->left==NULL && curr->right==NULL)
                {
                    root=NULL;
                    delete curr;
                }
                else if(curr->left!=NULL && curr->right==NULL)
                {
                    root=curr->left;
                    delete curr;
                }
                else if(curr->left==NULL && curr->right!=NULL)
                {
                    root=curr->right;
                    delete curr;
                }
                else
                {
                    swap(curr,find_min(curr->right));
                    curr=find_min(curr->right);
                    if(curr->right!=NULL)
                    {
                        curr->parent->right=curr->right;
                        curr->right->parent=curr->parent;
                        curr->right=NULL;
                    }
                    else
                    {
                        curr->parent->left=NULL;
                    }
                    curr->parent=NULL;
                    delete curr;
                }
            }
        }
        else
        {
            cout<<"The suggested value doesnot exist in tree."<<endl;
        }
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
    if(B1.search(val)==NULL)
    {
        cout<<"The asked value "<<val<<" does not exist in the tree."<<endl;
    }
    else
    {
 		cout<<"The asked value "<<val<<" exists in the tree."<<endl;
    }
    
    //find minimum
    if(B1.find_min(B1.root)!=NULL)
    {
        cout<<"Minimum value of the tree: "<<B1.find_min(B1.root)->data<<endl;
    }
    else
    {
        cout<<"Case invalid."<<endl;
    }
    
    //delete a node
    int del;
    cout<<"Please enter the node you want to delete"<<endl;
    cin>>del;
    B1.deleteNode(del);
    if(B1.root!=NULL)
    {
        B1.display();
        cout<<endl;
    }
    else
    {
        cout<<"No element in the tree after deletion."<<endl;// the BST had just one element
    }
    return 0;
}
