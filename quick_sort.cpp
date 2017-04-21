#include<iostream>
using namespace std;

class quick
{
	public:
		int *q,t;
		int pivot,low,high;
		int p;
		quick()
		{
			cout<<"\n\nEnter the maximum size of the array : ";
			cin>>t;
			q = new int[t];
		}
		void accept();
		void display();
		int part(int,int,int);
		void sort(int,int);
		void swap(int a,int b)
		{
			int temp;
			temp = q[a];
			q[a] = q[b];
			q[b] = temp;
		}
};

void quick :: accept()
{
	cout<<"\nEnter the elements : ";
	for(int i=0;i<t;i++)
	{
		cin>>q[i];
	}
}

void quick :: display()
{
	cout<<"\nElements : "<<"\t";
	for(int i=0;i<t;i++)
	{
		cout<<q[i]<<"\t";
	}
	cout<<endl;
}

int quick :: part(int l,int h,int pivot)
{
	for(int i=l;i<=h;i++)
	{
		if(q[i] < q[pivot])
		{
			swap(i,l);
			l++;
		}
		display();
	}
	swap(l,pivot);
	return l;
}

void quick :: sort(int low,int high)
{
	if(high - low <= 0)
	{
		return;
	}
	else
	{
		pivot = high;
		p = part(low,high-1,pivot);
		sort(low,p-1);
		sort(p+1,high);
	}
}

int main()
{
	quick l;
	char ch;
	do
	{
		cout<<"\n\t\t\t| Quick Sort |\n";
		cout<<"\n\t\t\t1.Store";
		cout<<"\n\t\t\t2.Display";
		cout<<"\n\t\t\t3.Sort";
		cout<<"\n\t\t\t4.Exit";
		cout<<"\n\t\t\t>>";
		cin>>ch;
		switch(ch)
		{	
			case '1':
				l.accept();
				break;
			case '2':
				l.display();
				break;
			case '3':
				l.sort(0,l.t-1);
				l.display();
				cout<<"\n\t\t\t****Sorted****\n";
				break;	
			case '4':
				cout<<"\n\t\t\t***Thank you***\n";
				break;
			default:
				cout<<"\n\t\t\t***Invalid Choice***\n";
				break;	
		}
	}while(ch != '4');
	return 0;	
}
