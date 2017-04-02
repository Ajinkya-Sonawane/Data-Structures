/*
	Converting a BST to TBT
	- Ajinkya Sonawane [AJ-CODE-7]
*/

#include<iostream>
#include<list>
using namespace std;

class node
{
		int data;
		node* left;	//To point to left node
		node* right;	//To point to right node
		bool lbit,rbit;	//To check presence of thread
		friend class tree;
};

class tree
{
	private:
		int val;
		node *root,*temp,*p;
		node *dummy;
		bool cr;
		list<node*>q;
		list<node*>s;
	public:
		tree();
		void create();		//To create a BST
		node* get_root();		//getter method for root
		node* insert(node*,node*);	//To insert node in BST
		void display(node*); 		//To display the tree using Threads
		void pushIn(node*);		//To push elements in a list
		void thread(node*);		//To create threads successor as well as predecessor
		node* next_inorder(node*);	//To get the next inorder node
		void inOrder(node*);
		~tree();
};

tree :: tree()
{
	root = NULL;
	//Dummy node is created so that there are no dangling pointers
	dummy = new node;
	dummy->data = 9999;
	dummy->left = root;
	dummy->right = dummy;

	cr = false;
}

node* tree :: get_root()
{
	//Getter method for root which is a private member
	return this->root;
}

void tree :: create()
{
	int total;
	if(cr)
	{
		cout<<"\n*******Tree already exists********\n";
		return;
	}

	cr = true;

	//Accept total number of elements in the tree
	cout<<"\nEnter the total number of elements : ";
	cin>>total;

	for(int i=0;i<total;i++)
	{
		cout<<"\nEnter the element : ";
		cin>>val;
		temp = new node;
		temp->left = NULL;
		temp->right = NULL;
		temp->lbit = false;
		temp->rbit = false;
		temp->data = val;
		root = insert(root,temp);
	}

	//calling thread function to put threads
	thread(root);
}

node* tree :: insert(node *r,node* t)
{

	if(r == NULL)
	{
		r = t;
	}
	else
	{
		if(r->data > t->data)
		{
			r->left = insert(r->left,t);
		}
		else
		{
			r->right = insert(r->right,t);
		}
	}

	return r;
}

void tree :: display(node* r)
{
	if(r == NULL)
	{
		cout<<"\n********No Tree present*********\n";
		return;
	}
	node *cur = r;
	while(cur->left != dummy)
			cur = cur->left;

	cout<<"\nInorder traversal using Threads : ";
	while(true)
	{
		cout<<cur->data<<"\t";
		if(cur->right == dummy)
			break;
		cur = next_inorder(cur);
	}
	cout<<endl;
}

node* tree :: next_inorder(node *r)
{
	if(r->rbit)
		return r->right;

	r = r->right;
	while(!r->lbit)
	{
		r = r->left;
	}
	return r;
}


void tree :: inOrder(node *r)
{
/*	stack<node*>s;
	node* cur = r;
	bool check = false;

	while(!check)
	{
		if(cur != dummy)
		{
			s.push(cur);
			cur = cur->left;
		}
		else
		{
			if(s.empty())
			{
				check = true;
			}
			else
			{
				cur = s.top();
				s.pop();
				cout<<"\n------------------------------------";
				cout<<"\nElement : "<<cur->data;
				cout<<"\nLeft Bit : "<<cur->lbit;
				cout<<"\nRigtht Bit : "<<cur->rbit;
				if(cur->rthread != NULL)
					cout<<"\nSuccessor Thread -----> "<<cur->rthread->data;
				else
					cout<<"\nSuccessor Thread : No Thread";
				cout<<"\n------------------------------------";
				cur = cur->right;
			}
		}
	}*/
}

void tree :: pushIn(node *r)
{
	if(r==NULL || r == dummy)
		return;
	else
	{
		pushIn(r->left);
		q.push_back(r);
		pushIn(r->right);
	}
}

void tree :: thread(node *r)
{
	//Threads to successor
	pushIn(r);
	node* cur;

	bool check = false;

	while(!q.empty())
	{
		s.push_front(q.front());
		q.pop_front();
	}


	pushIn(r);

	while(!check)
	{
		cur = q.front();
		if(q.empty())
			check = true;
		else
		{
			q.pop_front();
			if(cur->right == NULL)
			{
				if(q.empty())
				{
					cur->right = dummy;
				}
				else
				{
					cur->right = q.front();
					cur->rbit = true;
				}
			}
		}

	}

	check = false;

	while(!check)
	{
		cur = s.front();
		if(s.empty())
			check = true;
		else
		{
			s.pop_front();
			if(cur->left == NULL)
			{
				if(s.empty())
				{
					cur->left = dummy;
				}
				else
				{
					cur->left = s.front();
					cur->lbit = true;
				}
			}
		}

	}

}

tree :: ~tree()
{
}


int main()
{
	tree t;
	int ch;

	cout<<"\n\t|| PORGRAM TO CONVERT BST TO TBT ||\n";
	do
	{
		cout<<"\n1.Create Tree";
		cout<<"\n2.Display";
		cout<<"\n3.Exit";
		cout<<"\n>>";
		cin>>ch;

		switch(ch)
		{
			case 1:
				t.create();
				break;
			case 2:
				t.display(t.get_root());
				break;
			case 3:
				cout<<"\n********Exit*********\n";
				break;
			default:
				cout<<"\nInvalid Choice";
				break;
		}

	}while(ch!=3);
	return 0;
}
