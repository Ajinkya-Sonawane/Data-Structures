#include<iostream>
using namespace std;
class ternary
{
    private:
        int a[20];
        int front , last, n, fp, sp , key;
    public:
        void acceptan();
        void acceptkey();
        void sort();
        void search();
};

void ternary::acceptan()
{
    cout<<"\nEnter the size of the array:";
    cin>>n;
    cout<<"\nEnter the elements of the array";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

void ternary:: acceptkey()
{
    cout<<"\nEnter the element you want to search";
    cin>>key;
}

void ternary:: sort()
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}


void ternary:: search()
{
    int flag;
    front=0;
    last=n-1;
    for(int i=front;i<=last;i++)
    {
        fp=front+(last-front)/3;
        sp=last-(last-front)/3;
        if(key==a[fp])
        {   
            flag=1;
            cout<<"\nThe element is present in the list";
            break;
        }
        if(key==a[sp])
        {   
            flag=1;
            cout<<"\nThe element is present in the list";
            break;
        }
        if(key<a[fp])
        {
            last=fp-1;
        }
        else if(key>a[fp]&&key<a[sp])
        {
            front=fp+1;
            last=sp-1;
        }
        else if(key>a[sp])
        {
            front=sp+1;
        }
    }
    if(flag==0)
    {
        cout<<"\nThe element is not present";
    }
}


int main()
{
    int k;
    ternary t;
    do
    {
        cout<<"\n\n\n";
        cout<<"----------TERNARY SEARCH----------";
        cout<<"\n\n\n";
        cout<<"1.Store the elements in the list";
        cout<<"\n2.Accepting the element you want to search in the list";
        cout<<"\n3.Searching the element in the list including sorting";
        cout<<"\n4.Exit";
        cout<<">>";
        cin>>k;
        switch(k)
        {
            case 1:
                t.acceptan();
                break;
            case 2:
                t.acceptkey();
                break;
            case 3:
                t.sort();
                t.search();
                break;
            case 4:
                break;
            default:
                cout<<"\nInvalid choice";
        }
        if(k==4)
        {
            break;
        }
    }
    while(true);   
}
