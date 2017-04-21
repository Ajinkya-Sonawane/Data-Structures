/*
	C++ Program to implement Fibonacci Search.
	- Ajinkya Sonawane [AJ-CODE-7]
*/

#include<iostream>
using namespace std;

class fibb
{
	int *arr;
  	int size,search;
	public :
  	int fibs();
  	void getdata();
};

void fibb::getdata()
{
	int temp;
  	cout<<"\nEnter the maximum size of the array : ";
  	cin>>size;
	arr = new int[size];
  	cout<<"\nEnter roll numbers : ";
  	for(int i=0;i<size;i++)
	{
			cout<<"\n>>";
    		cin >> arr[i];
  	}
	cout<<"\nEnter the roll number to be searched : ";
  	cin>>search;
	for(int i=0;i<size;i++)
    	{
        	for(int j=0;j<size-i;j++)
        	{
            		if(arr[j]>arr[j+1])
            		{
                		temp=arr[j];
                		arr[j]=arr[j+1];
                		arr[j+1]=temp;
            		}
		}    
    	}
	if(fibs()==-1)
	{
		cout << "\nRoll number not found ";
		return;
	}
  	cout<<"\nRoll number found at "<<fibs()+1<<" position ";
}

int fibb::fibs()
{
  	int f2=0;
  	int f1=1;
  	int f3=f1+f2;

  	while(f3<size)
  	{
    		f2=f1;
    		f1=f3;
    		f3=f1+f2;
  	}

  	int offset=-1;

	  while(f3>1)
  	  {
    		 int i=(offset+f2 < size-1 ? offset+f2 : size-1);
    		 if(arr[i]<search)
    		{
      			f3=f1;
      			f1=f2;
      			f2=f3-f1;
      			offset=i;
    		}
    		else if(arr[i]>search)
    		{
      			f3=f2;
      			f1=f1-f2;
      			f2=f3-f1;
    		}
    		else 
    			return i;
  	}
  	if(arr[offset+1]==search)
    		return offset+1;

  	return -1;
}

int main()
{
  fibb obj;
  obj.getdata();
  return 0;
}

