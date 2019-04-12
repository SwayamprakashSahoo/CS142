//program to to implement a Min Heap via array

#include<iostream>
using namespace std;

class BinaryHeap{
    public:
    // Pointer to array of elements
    int * hArr;
    // Maximum possible size of array
    int mSize;
    // Current size of array 
    int cSize;

    BinaryHeap(int mSize)
	{
        // Constructor 
        hArr = new int[mSize];
        this->mSize = mSize;
        cSize = 0;
    }

    void swap(int a, int b){
        // Swap elements ... 
        hArr[a]=hArr[a]+hArr[b];
        hArr[b]=hArr[a]-hArr[b];
        hArr[a]=hArr[a]-hArr[b];
    }

    int parent(int i)
	{
		return (i-1)/2;
	}
    int left(int i)
	{
		return (i*2)+1;
	}
    int right(int i)
	{
		return (i*2)+2;
	}

    int getMin()
	{
		return hArr[0];
	}

    void insert(int value)
	{
        // Base case. for Heap Overflow
        if(cSize==mSize)											//current size equals the max size
        	cout<<"Heap Overflow"<<endl;
        	
        // Insert the new key at the end.
		else
        {
            hArr[cSize++]=value;									//value assigned to new key
            int a=cSize-1;
            //Check it for all hierarchy with loop
            while(a>0 && hArr[a]<hArr[parent(a)])
            {
            	//Check if it breaks the heap property and fix it.
                swap(a,parent(a));
                a=parent(a);
            }
        } 
    }
    
    void display()
	{
        // Display the array
        displayer(0,0);
    }
    void displayer(int i, int j)
	{
        if(i<cSize)
        {
            displayer(right(i),++j);//displaying right subtree
            cout<<endl;
            for(int i=1;i<j;i++)
            	cout<<"  ";
            cout<<hArr[i]<<endl;
            displayer(left(i),j);//displaying left subtree
        }
    }

    int extractMin() 
    { 
        //case 1: Empty Heap
        if(cSize==0)
        	return -1;
        //case 2 : Heap with 1 value.
		else if(cSize==1)
			return hArr[cSize--];
		//case 3 : Heap with more than 1 value
		else
        {
            int min=getMin();					// the minimum of the heap is stored
            hArr[0]=hArr[--cSize]; 				// Copy the last element to the root. 
            MinHeapify(0);						// Call MinHeapify on root. 
            return min;
        }
    }

    void decreaseKey(int i) 
    { 
        // Algorithm for what happens when I reduce the value of an element indexed at i to new_val. You can assume new_val to be less than the present value of the element. 
        hArr[i]=getMin()-1; 
        // Loop for correcting the Property 2.
        while(i>0 && hArr[i]<hArr[parent(i)])		// Compare with parent and move up till i == 0 or there is no violation. 
        {
            swap(i,parent(i));
            i=parent(i);
        } 
	}
	 
    // Deletes the element indexed at i. 
    void deleteKeyAt(int i) 
    { 
        // Decrease the value to INT_MIN at index i use decreaseKey()
        decreaseKey(i);
        // Call ExtractMin
        i=extractMin();
    }

    void MinHeapify(int i) 
    { 
        // Compare with left and right 
    	int least=i;
    	//checking if 'i' is already a min in any branch
    	//case 1 : right branch
    	if(right(i)<cSize && hArr[right(i)]<hArr[least])
        	least=right(i);
        //case 2 : left branch
        if(left(i)<cSize && hArr[left(i)]<hArr[least])
        	least=left(i);
            
        if(least!=i)
        {
            swap(i,least);
            // Call MinHeapify at the replaced child
            MinHeapify(least); 
   		} 
    } 
};

int main()
{
    BinaryHeap bh1(20);
    for(int i = 10; i >0 ; i--)
	{
        cout << "Inserting " << i << endl;
        bh1.insert(i);
        bh1.display();
        cout<<"________________________________________________________________"<<endl;
    }
    
    bh1.extractMin();
    bh1.display();
    cout<<"________________________________________________________________"<<endl;
    bh1.deleteKeyAt(3);
    bh1.display();
    cout<<"________________________________________________________________"<<endl;
    cout << endl;
}
