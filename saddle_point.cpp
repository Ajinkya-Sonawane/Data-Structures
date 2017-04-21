/*
	C++ Program for finding saddle point.
	- Ajinkya Sonawane [AJ-CODE-7]
*/

#include<iostream>
#include<cctype>
using namespace std;

template<class T>
class sad
{
	public:
		T mat[20][20];
		T small[20];
		T big[20];
		T min,max;
		int r,c,p,q;
		sad()
		{
			r=0;
			c=0;
			p=0;
			q=0;
		}
		void store();
		void display();
		void saddle();
};

template<class T>
void sad<T> :: store()
{
	cout<<"\nEnter the number of rows : ";
	cin>>r;
	cout<<"\nEnter the number of columns : ";
	cin>>c;
	cout<<"\nEnter the elements : ";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>mat[i][j];
		}
	}
}

template<class T>
void sad<T> :: display()
{
	cout<<"\n----------";
	cout<<"\nMatrix";
	cout<<"\n----------\n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<mat[i][j]<<"\t";
		}
		cout<<endl;
	}
}

template<class T>
void sad<T> :: saddle()
{

	for(int i=0;i<r;i++)
	{
		small[i] = mat[i][0];
		for(int j=0;j<c;j++)
		{
			if(mat[i][j]< small[i])
			{
				small[i]=mat[i][j];
			}
		}
	}
	for(int j=0;j<c;j++)
	{
		big[j] = mat[0][j];
		for(int i=0;i<r;i++)
		{
			if(mat[i][j]> big[j])
			{
			big[j]=mat[i][j];
			}
		}
	}
	max= small[0];
	for(int i=0;i<r;i++)
	{
		if(small[i]>max)
		{
			max=small[i];
			p= i;
		}
	}
	min=big[0];
	for(int j=0;j<c;j++)
	{
		if(big[j]<min)
		{
			min=big[j];
			q=j;
		}
	}
	if(min==max)
	{
		cout<<"\nthe saddle point value is "<<min;
		cout<<"\nThe saddle point row position is "<<p;
		cout<<"\nThe saddle point column position is"<<q;
	}
	else
	{
		cout<<"Not a saddle point ";
	}
}

int main()
{
	int x,ch;
	sad<int> s1;
	sad<float> s2;
	cout<<"\n1.Integer input";
	cout<<"\n2.Float input";
	cout<<"\n>>";
	try
	{
		cin>>x;
		if(x < 1 || x > 2)
			throw x;
		else if(!isdigit(x))
			throw x;	
	}
	catch(int)
	{
		cout<<"\nEnter proper choice : ";
		cin>>x;
	}
	catch(char)
	{
		cout<<"\nEnter a numeric value";
		cin>>x;
	}
	
	do
	{
		cout<<"\n1.Store";
		cout<<"\n2.Display";
		cout<<"\n3.Saddle";
		cout<<"\n4.Exit";
		cout<<"\n>>";
		cin>>ch;
		switch(ch)
		{
			case 1:
				if(x == 1)
					s1.store();
				else
					s2.store();
				break;
			case 2:	
				if(x == 1)
					s1.display();
				else
					s2.display();	
				break;
			case 3:
				if(x == 1)
					s1.saddle();
				else
					s2.saddle();	
				break;	
			case 4:
				break;		
		}
		if(ch == 4)
			break;
	}while(1);
}
