/*
	Parallel Binary Search using OpenMP
	Author - Ajinkya Sonawane
*/

#include<iostream>
#include<omp.h>

using namespace std;

void bs(int l,int h,int *arr,int *ind,int key)
{
        int mid;
        while(l<h)
        {
                mid = (l+h)/2;
                if(arr[mid] == key)
                {
                        *ind = mid;
                        return;
                }        
                if(key < arr[mid])
                {
                        h = mid;
                }
                else if(key > arr[mid])
                {
                        l = mid;
                }
        }
}

int main()
{
        int size,*arr,key,n_threads;
		
		//Accept the total number of elements
        cout<<"\nEnter the number of elements : ";
        cin>>size;
        
		//Initialize the array or fetch your array
		arr = new int[size];
        for(int i=0;i<size;i++)
        {
                arr[i] = i+1;
        }
		
		//Initialize index to -1 so that the fetched index can be recorded usin this variable
        int index=-1;
        
        cout<<"\nEnter the key to be searched : ";
        cin>>key;              
        
        cout<<"\nEnter the number of threads : ";
        cin>>n_threads;
        
		//Set the number of threads requestd by the user
        omp_set_num_threads(n_threads);

		//Calculate chunk size that individual array will handle
        int work_per_thread = size/n_threads;
        
        #pragma omp parallel
        {
                int thread = omp_get_thread_num();
                int l = thread*work_per_thread;
                int h = (l+work_per_thread)-1;
                bs(l,h,arr,&index,key);
        }              
		
		if(index != -1)
			cout<<"\nIndex : "<<index<<endl;
		else
			cout<<"\nElement not found"<<endl;
}
