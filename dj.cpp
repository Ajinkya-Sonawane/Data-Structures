
/*
	Shortest Path between two cities using Djikstra's Algorithm
	- Ajinkya Sonawane [AJ-CODE-7]
*/

#include<iostream>
#define INFINITY 9999
using namespace std;

class graph
{
	private:
		int **mat;		//2d array to store cost matrix
		bool check;		//variable to chose between directed and undirected graph
		string *names;		//array to store names of the cities
		int total,*d;		//total number of nodes,array for minimum distance
		bool *v;		//array to store visited flags of the nodes
	public:
		graph();
		void accept();		//method to accept the graph
		int minDistance();	//return's location of node with minimum distance
		void shortest();	//Method to calculate shortest path
};

graph :: graph()
{
	int ch;
	cout<<"\n\n1.Directed Graph";
	cout<<"\n2.Undirected Graph";
	cout<<"\n>>";
	cin>>ch;

	if(ch == 1)
		check = true;
	else
		check = false;
	cout<<"\nEnter the total number of cities : ";
	cin>>total;

	names = new string[total+1];	//list of names of the cities
	mat = new int*[total+1];	//cost matrix
	v = new bool[total+1];		//list of visited cities
	d = new int[total+1];		//list of the distance in final shortest path

	cout<<"\nEnter the names of the cities : ";
	for(int i=1;i<=total;i++)
	{
		cout<<"\n>>";
		ws(cin);
		getline(cin,names[i]);
	}


	//dynamically allocating memory for adjacency matrix
	for(int i=1;i<=total;++i)
		mat[i]= new int[total];


	for(int i=1;i<=total;i++)
	{
		v[i] = false;
		d[i] = INFINITY;
		for(int j=1;j<=total;j++)
		{
			mat[i][j] = 0;
		}
	}

}

void graph :: accept()
{
	int a,b,dis;
	char ch;
	cout<<"\nNames of cities are : ";
	for(int i =1;i<=total;i++)
	{
		cout<<names[i]<<"("<<i<<")"<<"\t";
	}
	cout<<endl;
	cout<<"\nEnter the connected cities as (1 2) : ";
	do
	{
		l1:
		cout<<"\nEnter the cities : ";
		cin>>a>>b;
		if(a<1 || a>total || b<1|| b>total)
		{
			cout<<"\n** Invalid Input, Re-enter the vertices **\n";
			goto l1;
		}
		cout<<"\nEnter the distance in kms : ";
		cin>>dis;
		mat[a][b] = dis;
		if(!check)
			mat[b][a] = dis;
		cout<<"\ny to add more .... n to exit : ";
		cin>>ch;
	}while(ch=='y');
}

void graph :: shortest()
{
	//accept source and destination for the shortest path
	int src,des;
	cout<<"\nEnter the source : ";
	cin>>src;
	cout<<"\nEnter destination : ";
	cin>>des;

	//Minimum distance from source to source is 0
	d[src] = 0;

	//loop to find the shortest distance from source to each node
	for(int count = 1;count < total;count++)
	{
		//minDistance returns the location of the minimum value
		int loc = minDistance();
		//set the visited flag to true
		v[loc] = true;
		for (int i = 1; i <= total; i++)
		{
			/* If the node is not visited,
			   If an edge is present between the two nodes,
			 & If the distance from source node is greater than the distance from a third node
			   Modify the distance */

			if (!v[i] && mat[loc][i] && d[loc] != INFINITY && (d[loc]+mat[loc][i]) < d[i])
		        {
		        	d[i] = d[loc] + mat[loc][i];
		        }
		}
	}
	cout<<"\nShortest path from "<<names[src]<<" to "<<names[des]<<" : "<<d[des]<<" kms\n";
}

int graph :: minDistance()
{
	//method tho find the minimum value in the distance array
	int min = INFINITY,min_loc;
	for(int i=1;i<=total;i++)
	{
		if(v[i] == false && d[i] <= min)
		{
			min = d[i];
			min_loc = i;
		}
	}

	return min_loc;
}

int main()
{
	//calling the functions to accept the graph and find the shortest path
	graph g;
	g.accept();
	g.shortest();
}
