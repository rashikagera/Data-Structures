
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#define Null 0
class linklist
{
  struct node
  {
    struct node *prev;
    int data;
    struct node *next;
   }*head,*first,*tail,*temp;

  public:
  linklist()
  {
    head=Null;
    tail=Null;

  }
  ~linklist()
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


 }obj;
void main()
{
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
      cout<<"9. Exit \n";
      cout<<"Enter your choice: ";
      cin>>ch1;
      switch(ch1)
     {
	    case 1: obj.create();
		        break;
       case 2:  obj.display();
		      break;
       case 3: obj.insert_at_beg();
             break;
       case 4:  obj.insert_at_end();
             break;
       case 5: obj.insert_at_pos();
             break;
       case 6: obj.delete_at_beg();
              break;
       case 7: obj.delete_at_end();
              break;
       case 8: obj.delete_at_pos();
              break;

     	case 9 : exit(0);
      }
      cout<<"\n Do you want to operate more????(y/n): ";
      cin>>ch2;
      } while(ch2=='y'||ch2=='Y');
      getch();
 }
 void linklist::create()
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
      else
     {
	   tail->next=first;
	   first->prev=tail;
      first->next=head;
      head->prev=first;
      tail=first;
	  }

       cout<<"Do you want to insert more nodes(y/n) :  ";
       cin>>ch;
       }while(ch=='y');

 }


    void linklist::insert_at_beg()
    {

     first=new node;
     cout<<"Enter the value of the data";
     cin>>first->data;
     if(head==Null)
     {
       head=tail=first;
       first->prev=tail;
       first->next=head;
      }
      else
      {

       first->next=head;
       head->prev=first;
       first->prev=tail;
       tail->next=first;
       head=first;
     }
      display();
    }

    void linklist::insert_at_end()
    {
       first=new node;
       cout<<"Enter the value of the data";
       cin>>first->data;
      if(head==Null)
      {
       head=tail=first;
       first->prev=tail;
       first->next=head;
      }
      else
      {
       first->prev=tail;
       tail->next=first;
       first->next=head;
       head->prev=first;
       tail=first;

     }
      display();
     }

     void linklist::insert_at_pos()
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
       first->prev=temp;
       first->next=temp->next;
       temp->next->prev=first;
       temp->next=first;
       display();
       }

    void linklist::delete_at_beg()
    {
      temp=tail;
       tail=tail->prev;
      tail->next=head;
      head->prev=tail;
       delete temp;
      display();

   }
   void linklist::delete_at_end()
  {
     temp=tail;
     tail=tail->prev;
     temp->prev=Null;
     tail->next=Null;
     display();
   }
  void linklist::delete_at_pos()
  {
    int pos;
    cout<<"Enter the position";
    cin>>pos;
    temp=head;
    for(int i=0;i<pos-1;i++)
    temp=temp->next;
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    if(temp->next==head)
    {
     tail=temp->prev;
     delete temp;
     }
     else
      delete temp;
     display();
   }

    void linklist::display()
     {
        temp=head;
     if(temp==Null)
     {
	  cout<<"List is empty";
     }
     else
     {
       cout<<"Elements of the list are: \n";
       while(temp!=tail)
       {
          cout<<temp->data;
          cout<<"-->";
          temp=temp->next;
       }
      cout<<temp->data;
     }
   }