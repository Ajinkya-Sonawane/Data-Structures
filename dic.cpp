/*
	Program to create a dictionary using AVL.
	- Ajinkya Sonawane [AJ-CODE-7]
*/

#include<iostream>
#include<cstring>
using namespace std;

class node
{
	public:
		string meaning;
		string key;
		node *left,*right;
};

class tree
{
	private:
		node *root;			//Root for the BST
		node* cur;			//Pointer to traverse the BST
		char* s;
	public:
		tree();
		node* get_root();		//Getter method for root node
		void create();			//Method to create a BST
		node* insert(node*,node*);	//Method to insert the nodes in BST
		void display(node*);		//Method to display the BST
		node* traverse(node*,char*);	//Method to traverse and locate a node
		char* convert(string);
		bool search();			//Method to search words in the dictionary
		void update();			//Method to update the meaning
		void Delete();
		node* delNode(node*,char*);
		node* findMin(node*);

		node* balance(node*);       //method to balance the avl
	        node* leftRotate(node*);    //method to rotate nodes in left direction
	        node* rightRotate(node*);   //method to rotate nodes in right direction

         	int height(node*);          //method to calculate height of a particular node
        	int bal(node*);             //method to calculate the balance factor used for balancing the avl
};

tree :: tree()
{
	root = NULL;
	cur = NULL;
}

node* tree :: get_root()
{
	return root;
}

char * tree :: convert(string x)
{
	int i = x.size();
	char *s = new char[i+1];

	for(int j=0;j<i;j++)
	{
		s[j] = x[j];
	}

	return s;
}

void tree :: create()
{
	int t;
	cout<<"\nEnter the total number of word you want to store : ";
	cin>>t;
	for(int i=0;i<t;i++)
	{
		node* temp = new node;
		cout<<"\nEnter the word : ";
		cin>>temp->key;

		cout<<"\nEnter the meaning of the word : ";
		ws(cin);
		getline(cin,temp->meaning);

		temp->left = NULL;
		temp->right = NULL;

		root = insert(root,temp);
	}
}

node* tree :: insert(node* r,node* t)
{
	if(r == NULL)
		r = t;
	else
	{
		if(strcmp( convert(r->key),convert(t->key) ) < 0)
		{
			r->left = insert(r->left,t);
			r = balance(r);
		}
		else
		{
			r->right = insert(r->right,t);
			r = balance(r);
		}
	}
	return r;
}

bool tree :: search()
{
	if(root == NULL)
	{
		cout<<"\n********No entries in the dictionary***********\n";
	}
	else
	{
		string key;
		cout<<"\nEnter the word you want to search : ";
		ws(cin);
		getline(cin,key);
		cur = traverse(root,convert(key));
		if(cur == NULL)
		{
			cout<<"\nWord not found!"<<endl;
			return false;
		}
		cout<<"\nMeaning of "<<key<<" : "<<cur->meaning<<endl;
	}
	return true;
}

node* tree :: traverse(node *r,char *k)
{
	if(r != NULL)
	{
		if(strcmp( convert(r->key) , k) < 0)
		{
			traverse(r->left,k);
		}
		else if(strcmp(convert(r->key),k) > 0)
		{
			traverse(r->right,k);
		}
		else
		{
			return r;
		}
	}
	else
		return NULL;
}

void tree :: update()
{
	if(root == NULL)
	{
		cout<<"\n********No entries in the dictionary***********\n";
		return;
	}
	if(search())
	{
		cout<<"\nEnter new meaning for "<<cur->key<<" : ";
		ws(cin);
		getline(cin,cur->meaning);
		cout<<"\n\nUPDATED SUCCESSFULLY\n";
	}
}

void tree :: display(node *r)
{
	if(r != NULL)
	{
		cout<<"\nKey : "<<r->key;
		cout<<"\nMeaning : "<<r->meaning;
		cout<<endl;
		display(r->left);
		display(r->right);
	}
}

void tree :: Delete()
{
	if(root == NULL)
		cout<<"\n**********Tree Doesn't Exist********\n";
	else
	{
		string key;
		cout<<"\nEnter the word you want to delete : ";
		cin>>key;
		root = delNode(root,convert(key));
		cout<<"\n********Deleted Successfully*********\n";
	}
}

node* tree :: delNode(node* r,char* x)
{
	node *temp;
	if(r == NULL)
		return r;
	else if(strcmp(convert(r->key),x) < 0)
	{
		r->left = delNode(r->left,x);
	}
	else if(strcmp(convert(r->key),x) > 0)
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
			strcpy(convert(r->key),convert(temp->key));
			r->right = delNode(r->right,convert(temp->key));
			r = balance(r);
		}
	}
	return r;
}

node* tree :: findMin(node* r)
{
	node* cur = r;
	while(cur->left != NULL)
		cur = cur->left;
	return cur;
}

int tree :: height(node *r)
{
	    //Here height is the number of nodes present in the longest path  (including root) and not the number of edges
	    if(r == NULL)
	        return 0;
	    else
	    {
	        int lheight = height(r->left)+1;
	        int rheight = height(r->right)+1;

	        return (lheight > rheight) ? lheight : rheight; //returning longest path from root
	    }
}

int tree :: bal(node *r)
{
	    int left = height(r->left);
	    int right = height(r->right);

	    return (left-right);    //returning difference between left subtree and right subtree
}



node* tree :: leftRotate(node* r)
{
	    //rotating in left direction
	    node* cur = r->left;
	    r->left = cur->right;
	    cur->right = r;

	    return cur;
}

node* tree :: rightRotate(node* r)
{
	    //rotating in right direction
	    node* cur = r->right;
	    r->right = cur->left;
	    cur->left = r;

	    return cur;
}

node* tree :: balance(node* r)
{
	    int bf = bal(r);
	    if (bf > 1)
	    {
	        if (bal(r->left) > 0)
	        {
	            //simple rotation on the left of left subtree
	            r = leftRotate(r);
	        }
	        else
	        {
	            //complex rotation on right of left subtree
	            r->left = rightRotate(r->left);
	            return leftRotate(r);
	        }
	    }
	    else if (bf < -1)
	    {
	        if (bal(r->right) > 0)
	        {
	            //complex rotation on left of right subtree
	            r->right = leftRotate(r->right);
	            return rightRotate(r);
	        }
	        else
	        {
	            //simple rotation on right of right subtree
	            r = rightRotate(r);
	        }
	    }
	    return r;
}


int main()
{
	tree t;
	int ch;
	do
	{
		cout<<"\n\t\t|| DICTIONARY ||\n";
		cout<<"\n1.Store";
		cout<<"\n2.Search";
		cout<<"\n3.Update";
		cout<<"\n4.Delete";
		cout<<"\n5.Exit";
		cout<<"\n>>";
		cin>>ch;

		switch(ch)
		{
			case 1:
				t.create();
				break;

			case 2:
				t.search();
				break;

			case 3:
				t.update();
				break;

			case 4:
				t.Delete();
				break;
			case 5:
				cout<<"\n********Exit*********\n";
				break;
			default:
				cout<<"\nInvalid Choice";
				break;
		}
	}while(ch!=5);
	return 0;
}
