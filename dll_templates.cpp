//ques 11 Implement Doubly Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list.

#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#define Null 0
template <class x>
class DLL
{
  struct node
  {
    node *prev;
    int data;
     node *next;
  }*head,*first,*tail,*temp;

  public:
  DLL()
  {
    head=Null;
    tail=Null;

  }
  ~DLL()
 {


 }
  void create();
  void display();
  void insert_at_beg();
  void insert_at_end();
  void insert_at_pos();
  void delete_at_beg();
  void delete_at_end();
  void delete_at_pos();
  void reverse();
  void search();


} ;
void main()
{
 DLL<int> obj,obj1;
    int ch1;
    char ch2;
    clrscr();
    do
    {
      cout<<"1. Create a linklist \n";
      cout<<"2. Display link list \n";
      cout<<"3. Insert at beginning \n";
      cout<<"4. Insert at end \n";
      cout<<"5. Insert at a specific position \n";
      cout<<"6  Delete at beginning \n";
      cout<<"7. Delete at end \n";
      cout<<"8. Delete from a specific position \n";
      cout<<"9. Reverse a linklist \n";
      cout<<"10. Search in a linklist \n";
      cout<<"11.  Exit \n";
      cout<<"Enter your choice: ";
      cin>>ch1;
      switch(ch1)
 {
    case 1:  obj.create();
		        break;
    case 2:  obj.display();
		       break;
    case 3:  obj.insert_at_beg();
             break;
    case 4:  obj.insert_at_end();
             break;
    case 5:  obj.insert_at_pos();
             break;
    case 6:  obj.delete_at_beg();
             break;
    case 7:  obj.delete_at_end();
             break;
    case 8:  obj.delete_at_pos();
             break;
    case 9:  obj.reverse();
             break;
    case 10: obj.search();
             break;
	case 11 : exit(0);
 }
      cout<<"\n Do you want to operate more????(y/n): ";
      cin>>ch2;
 } while(ch2=='y'||ch2=='Y');
      getch();
 }
template <class x>
 void DLL<x>::create()
 {


    char ch='y' ;
    do{
    first=new node;
    cout<<"Enter the data item in the node: ";
    cin>>first->data;
    first->next=Null;
    first->next=Null;

     if(head==Null)
    {
       head=first;
        tail=first;
     }
      else{


	   tail->next=first;
	   first->prev=tail;
      tail=first;
	  }

       cout<<"Do you want to insert more nodes(y/n) :  ";
       cin>>ch;
       }while(ch=='y');

 }

template <class x>
    void DLL<x>::insert_at_beg()
    {

     first=new node;
     cout<<"Enter the value of the data";
     cin>>first->data;
     first->prev=Null;
     first->next=head;
     head->prev=first;
     head=first;
      display();
    }

template <class x>
    void DLL<x>::insert_at_end()
    {
      first=new node;
     cout<<"Enter the value of the data";
     cin>>first->data;
     first->next=Null;
     first->prev=tail;
     tail->next=first;
     tail=first;
     display();
     }

template <class x>
      void DLL<x>::insert_at_pos()
      {
       first=new node;
       cout<<"Enter the value of the data";
      cin>>first->data;
      int pos;
      cout<<"Enter the position: ";
      cin>>pos;
      temp=head;
      for(int i=0;i<pos-1;i++)
       {temp=temp->next;
       }
       first->next=temp->next;
       temp->next->prev=first;
       temp->next=first;
       first->prev=temp;
       display();
     }

template <class x>
    void DLL<x>::delete_at_beg()
    {
      temp=head;
      head=head->next;
      temp->next=Null;
      head->prev=Null;
      display();

   }

template <class x>
   void DLL<x>::delete_at_end()
  {
     temp=tail;
     tail=tail->prev;
     temp->prev=Null;
     tail->next=Null;
     display();
   }

template <class x>
  void DLL<x>::delete_at_pos()
  {
    int pos;
    cout<<"Enter the position";
    cin>>pos;
    temp=head;
    for(int i=0;i<pos-1;i++)
    temp=temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;
    display();
   }

template <class x>
  void DLL<x>::reverse()
{    node *temp1= new node;
	temp1=tail;
	temp=head;
	while(temp!=temp1)
	{
		while(temp->next!=temp1)
		{
			temp=temp->next;
		}
		temp1->next=temp;
		temp1=temp;
		temp=head;
	}
	temp=head;
	head=tail;
	tail=temp;
	tail->next=NULL;
   display();
}

template <class x>
        void DLL<x>::search()
     {
       int value,pos=0;
        bool flag=false;
    if(head==NULL)
    {
        cout<<"List is Empty";
        return;
    }
    cout<<"Enter the Value to be Searched:";
    cin>>value;
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        pos++;
        if(temp->data==value)
        {
            flag=true;
            cout<<"Element"<<value<<"is Found at : "<<pos<<" Position";
            return;
        }
        temp=temp->next;
    }
    if(!flag)
    {
        cout<<"Element "<<value<<" not Found in the List";
    }
}

template <class x>
       void DLL<x>::display()
  {

      temp=head;
     if(temp==Null)
     {
	  cout<<"List is empty";
     }
     else
     {
       cout<<"Elements of the list are: \n";
       while(temp!=Null)
       {
          cout<<temp->data;
          cout<<"-->";
          temp=temp->next;
       }
     }
   }