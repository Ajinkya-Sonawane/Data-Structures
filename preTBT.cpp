
/*
    C++ Program to covert BST to Pre-Order TBT.
    - Ajinkya Sonawane [AJ-CODE-7]

    Pre-Order : Root -> Left -> Right

                          5
                         /  \
                        /    \
                       2   /->7
                      / \  |    \
                     /   \ |     \ 
                    1 --> 3      6

                threads from 1->3, 3->7

    Threaded Binary Tree can be traversed without using recursion or stack,hence saving space.
*/

#include<iostream>
#include<list>
using namespace std;

class node
{
    int data;           //field to store data in the node
    node *left,*right;  //links to left and right child
    bool rbit;          //Flag used to check whether there exists a child or a thread |False if child & True if thread |
    friend class tree;  //Allow class tree to access private members of the node
};

class tree
{
    node *root,*temp;   //declaring root node and a temporary node
    list<node*>q;       //using STL List to store nodes in sequence
public:
        tree();                     //constructor for initializing variables of the class

        inline node* get_root(){return root;} //getter method to return the reference of the root node

        void accept(int);           //accepting total number of nodes to be inserted
        node *insert(node*,node*);  //method to insert the node in the tree as per the rules of BST
        void display();             //method to display the tree in Pre-Order using threads

        void putPre(node*);         //method to pushing the references of the nodes in a list in Pre-Order manner
        void thread(node*);         //method to put threads using the references of the nodes present in the list
};

tree :: tree()
{
    root = NULL;    //initializing root node to NULL
}

void tree :: accept(int total)
{
    //inserting the total number of nodes given by the user
    for(int i=0;i<total;i++)
    {
        temp = new node;
        cout<<"\nEnter the element : ";
        cin>>temp->data;
        temp->rbit = false;
        temp->left = NULL;
        temp->right = NULL;

        root = insert(root,temp);   //inserting nodes in the tree
    }
    //putting threads from nodes to their Pre-Order successor
    thread(root);
}

node* tree :: insert(node* r,node* t)
{
    //Inserting nodes in the binary search tree using recursion
    if(r == NULL)
        return t;
    else if(r->data > t->data)
    {
        r->left = insert(r->left,t);
    }
    else
    {
        r->right = insert(r->right,t);
    }

    return r;
}

void tree :: display()
{
    //To display we need to use threads and normal links....We do not use recursion or stack to print the tree.
    node *cur = root;   //set a pointer 'cur' on the root to traverse the tree
    while(cur != NULL)
    {
        cout<<"\t"<<cur->data;      //Print the data of the current node

        if(cur->rbit)               //if right thread is present traverse to the right thread
        {
            cur = cur->right;
            cout<<"(T)";
        }
        else if(cur->left)          //if left child is present and there is no right thread then traverse left child
            cur = cur->left;
        else
            cur = cur->right;       //if there is no right thread and no left child then traverse the right child
    }
}

void tree :: putPre(node *r)
{
    //traverse the tree recursively in pre-order manner and push the reference of the node in the list
    if(r != NULL)
    {
        q.push_back(r);
        putPre(r->left);
        putPre(r->right);
    }
}

void tree :: thread(node *r)
{
    bool check = false;         //when check is true the operation has been completed
    node *cur ;                 //pointer used to traverse the nodes in the list having the references of the nodes

    putPre(r);                  //calling method 'putPre' to push the references of the nodes in the list

    while(!check)               //loop till the operation is not complete
    {
        cur = q.front();        //accessing the first reference in the list
        if(q.empty())           //check if the list is empty
            check = true;
        else
        {
                q.pop_front();     //pop/remove the top reference from the list after accessing that reference
                //if the node has no child the thread will be applied as in Pre-Order traversal the child is the immediate pre-order successor
                if(!cur->right && !cur->left)
                {
                    if(q.empty())      //check if the list is empty
                        cur->right = NULL;  //the last node of the tree points to NULL or dummy node if created
                    else
                    {
                        cur->right = q.front(); //putting thread from the node whose reference is accessed to the next node present in the list
                        cur->rbit = true;       //set the rbit to indicate presence of thread
                    }
                }
        }
    }
}

int main()
{
    //Menu driven program to chose between creating and displaying the tree
    //Tree once created remains the same and the threads are applied to the created tree
	tree t;
	int ch,total;

	do
	{
	    cout<<"\n\t|| PORGRAM TO CONVERT BST TO Pre-Order TBT ||\n";
		cout<<"\n1.Create Tree";
		cout<<"\n2.Display Pre-Order";
		cout<<"\n3.Exit";
		cout<<"\n>>";
		cin>>ch;

		switch(ch)
		{
			case 1:
			    if(t.get_root() != NULL)
                {
                    cout<<"\n\t***** Tree already exists... This program converts a binary tree to a threaded binary tree *****\n";
                    break;
                }
			    cout<<"\nEnter the total number of elements : ";
			    cin>>total;
				t.accept(total);
				break;
			case 2:
			    if(!t.get_root())
                {
                    cout<<"\n\t**** Tree doesn't exist ****\n";
                    break;
                }
			    cout<<"\n\t*** Nodes having threads are displayed succeeding with (T) ***\n";
			    cout<<"\n| Pre - Ordeer : |";
				t.display();
				cout<<endl;
				break;
			case 3:
				cout<<"\n\t\t********Exit*********\n";
				break;
			default:
				cout<<"\nInvalid Choice\n";
				break;
		}

	}while(ch!=3);

	return 0;
}