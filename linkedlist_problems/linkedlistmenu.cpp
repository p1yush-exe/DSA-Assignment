#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node()
    {
        data=0;
        next=NULL;
    }
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

class LinkedList
{
    Node* head;

    public:
    LinkedList() 
    {
        head=NULL;
    }
    ~LinkedList() 
    { 
        clear();
    }

    void clear()
    {
        Node* temp = head;
        while(temp)
        {
            Node* nxt = temp->next;
            delete temp;   // frees node
            temp = nxt;
        }
        head = nullptr;
    }

    void insert_end(int data)
    {
        Node* newNode= new Node(data);

        if(head==NULL)
        {
            head=newNode;
            return;
        }

        Node* temp=head;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        
        temp->next=newNode;
        newNode->next=NULL;
    }

    void insert_beg(int data)
    {
        Node* newNode= new Node(data);
        if(head==NULL)
        {
            head=newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    }

    void display()
    {
        Node* temp=head;

        if(head==NULL)
        {
            cout<<"Empty list."<<endl;
            return;
        }

        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void search(int x)
    {
        Node* temp=head;

        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
        }

        while(temp!=NULL)
        {
            if(temp->data==x)
            {
                cout<<"Element found"<<endl;
                return;
            }
            temp=temp->next;
        }
        cout<<"Element not found"<<endl;
    }

    void insert(int after, int data)
    {
        Node* newNode= new Node(data);
        Node* temp=head;

        if(head==NULL)
        {
            head=newNode;
            return;     
        }

        while(temp!=NULL && temp->data!=after)
        {
            temp=temp->next;
        }

        if(temp==NULL)
        {
            cout<<"ELEMENT NOT FOUND"<<endl;
            return;
        }

        newNode->next=temp->next;
        temp->next=newNode;
    }
};

int main()
{
    LinkedList l1;
    l1.display();
    l1.insert_beg(10);
    l1.insert_beg(9);
    l1.insert_beg(-24);
    l1.insert_beg(-82);

    l1.display();
    l1.search(9);

    l1.insert_end(15);
    l1.insert_end(20);
    l1.insert_end(69);

    l1.display();
    l1.search(69);

    l1.insert(10,11);
    l1.insert(20,24);
    l1.insert(-82,-43);

    l1.display();
    l1.search(-1);

    return 0;
    
}