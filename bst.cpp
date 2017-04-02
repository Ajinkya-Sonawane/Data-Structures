/*
	Binary Search Tree
	-Ajinkya Sonawane [AJ-CODE-7]
*/

#include<iostream>
using namespace std;

class node
{
	int data;
	node *left,*right;
	friend class bst;
};

class bst
{
	node *root,*temp;
	int val;
	public:
		bst();				//Constructor to Initialize root to NULL
		void create(int);		//Method to create BST
		node* get_root();		//Getter method for root of the tree
		node* insert(node*,node*);	//Method to insert a node in the BST
		void inOrder(node*);		//Method to display contents of the tree
		void preOrder(node *);
		void postOrder(node *);
		void Delete();			//Method to delet element form the tree
		node* delNode(node*,int);	//Method to remove the node from the tree
		node* findMin(node*);		//Method to find min value in the tree |Left-Most Value|
		node* findMax(node*);		//Method to find max value in the tree |Right_Most Value|
		void Find(int);			//Method for calling different method
		int height(node *);		//Method to Find Height of the tree
		void mirror(node *);
};

bst :: bst()
{
	//Initializing root to NULL
	root = NULL;
}

node* bst :: get_root()
{
	return root;
}
void bst :: create(int total)
{

	for(int i=0;i<total;i++)
	{
		//Accepting an element to insert in the tree
		cout<<"\nEnter the element : ";
		cin>>val;

		temp = new node;
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		root = insert(root,temp);
	}
}

node* bst :: insert(node* r,node* t)
{
	if(r == NULL)
		return t;
	else
	{
		//if newly inserted value if less than root it is placed in the left sub-tree else in the right sub-tree
		if(r->data > t->data)
			r->left = insert(r->left,t);
		else
			r->right = insert(r->right,t);
	}
	return r;
}

void bst :: inOrder(node *r)
{
	if(r!=NULL)
	{
        inOrder(r->left);
		cout<<r->data<<"\t";
		inOrder(r->right);
	}
}

void bst :: preOrder(node *r)
{
	if(r!=NULL)
	{
		cout<<r->data<<"\t";
		preOrder(r->left);
		preOrder(r->right);
	}
}

void bst :: postOrder(node *r)
{
	if(r!=NULL)
	{
		postOrder(r->left);
		postOrder(r->right);
		cout<<r->data<<"\t";
	}
}

void bst :: Delete()
{
	if(root == NULL)
	{
		cout<<"\n********Tree does not exist********\n";
		return;
	}
	else
	{
		int x;
		cout<<"\nEnter the element you want to delete : ";
		cin>>x;
		root = delNode(root,x);
		cout<<"\n***********Deleted Successfully*********\n";
	}
}



node* bst :: delNode(node* r,int x)
{
	node *temp;
	if(r == NULL)
		return r;
	else if(x < r->data)
	{
		r->left = delNode(r->left,x);
	}
	else if(x > r->data)
	{
		r->right = delNode(r->right,x);
	}
	else
	{
		if(r->left == NULL)
		{
			temp = r->right;
			delete r;
			return temp;
		}
		else if(r->right == NULL)
		{
			temp = r->left;
			delete r;
			return temp;
		}
		else
		{
			temp = findMin(r->right);
			r->data = temp->data;
			r->right = delNode(r->right,temp->data);
		}
	}
	return r;
}

node* bst :: findMin(node* r)
{
	node* cur = r;
	while(cur->left != NULL)
		cur = cur->left;
	return cur;
}

node* bst :: findMax(node* r)
{
	node* cur = r;
	while(cur->right != NULL)
		cur = cur->right;
	return cur;
}

void bst :: Find(int  ch)
{
	if(root == NULL)
		cout<<"\n*********Tree Doesn't Exist********\n";
	else
	{
		node* temp;
		switch(ch)
		{
			case 1:
				temp = findMin(root);
				cout<<"\n Min Value in the tree: "<<temp->data<<endl;
				break;
			case 2:
				temp = findMax(root);
				cout<<"\n Max Value in the tree: "<<temp->data<<endl;
				break;
			case 3:
				int res = height(root);
				cout<<"\n Height of the Tree : "<<res<<endl;
				break;
		}
	}
}

int bst :: height(node* r)
{
	if(r == NULL)
		return 0;

	int lheight = height(r->left)+1;
	int rheight = height(r->right)+1;

	return (lheight > rheight) ? lheight:rheight;
}

void bst :: mirror(node *r)
{
	if(r == NULL)
		return;
	mirror(r->left);
	mirror(r->right);

	//Switching the pointer of child nodes
	node* cur = r->right;
	r->right = r->left;
	r->left = cur;

}

int main()
{
	bst b;
	int ch,total;

	do
	{
		cout<<"\n\t\t|| Binary Search Tree ||\n";
		cout<<"\n1.Create BST";
		cout<<"\n2.Insert Element";
		cout<<"\n3.Display";
		cout<<"\n4.Delete Element";
		cout<<"\n5.Find Hieght";
		cout<<"\n6.Minimum Value";
		cout<<"\n7.Maximum Value";
		cout<<"\n8.Mirror";
		cout<<"\n9.Exit";
		cout<<"\n>>";
		cin>>ch;

		switch(ch)
		{
			case 1:
				cout<<"\nEnter the total number of elements you wish to enter : ";
				cin>>total;
				b.create(total);
				break;
			case 2:
				b.create(1);
				break;
			case 3:
				if(b.get_root() == NULL)
				{
					cout<<"\n*********Tree Doesn't Exist********\n";
					break;
				}
				int dch;
				cout<<"\n1.Inorder";
				cout<<"\n2.Preorder";
				cout<<"\n3.Postorder";
				cout<<"\n>>";
				cin>>dch;
				switch(dch)
				{
					case 1:
						cout<<"\n In Order :\t";
						b.inOrder(b.get_root());
						cout<<endl;
						break;
					case 2:
						cout<<"\n Pre Order :\t";
						b.preOrder(b.get_root());
						cout<<endl;
						break;
					case 3:
						cout<<"\n Post Order :\t";
						b.postOrder(b.get_root());
						cout<<endl;
						break;
					default:
						cout<<"\nInvalid Choice";
						break;
				}
				break;
			case 4:
				b.Delete();
				break;
			case 5:
				b.Find(3);
				break;
			case 6:
				b.Find(1);
				break;
			case 7:
				b.Find(2);
				break;
			case 8:
				b.mirror(b.get_root());
				cout<<"\n******** Mirrored Successfully *******\n";
				break;
			case 9:
				cout<<"\n********Exit*********\n";
				break;
			default:
				cout<<"\nInvalid Choice";
				break;
		}
	}while(ch != 9);
}
