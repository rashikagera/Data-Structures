//	Create and perform the following operations on Queues using Linked List implementation:

//a)	Enqueue
//b)	Dequeue


#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#define Null 0
class queue
{
  struct node
  {
    int data;
    struct node*next;
  }*ptr,*temp,*front,*rear;

  public:
   queue()
   {
     rear=Null;
     front=Null;
    }


    void enqueue();
    void dequeue();
    void display();

}obj;
void queue::enqueue()
{
  int ele;
  ptr=new node;
  cout<<"Enter the number to be inserted:  ";
  cin>>ele;
  ptr->data=ele;
  ptr->next=Null;
  if(rear==Null)
  {
    front=ptr;
    rear=ptr;
   }
   else
   {
    rear->next=ptr;
    rear=ptr;
    }

}

void queue::dequeue()
{

  if(front==Null)
  {
   cout<<"Queue is emmpty..Underflow comdition";

   }
   else
   {
     temp=front;
     front=front->next;
     cout<<"The deleted element is" "<<temp->data;
     temp->next=Null;
      delete temp;

     }


}




void queue::display()
{
 temp=front;
 if(front==Null)
   cout<<"Queue is empty";
  else
  {

   while(temp!=Null)
   {
    cout<<temp->data<<"->";
    temp=temp->next;
    }
}
}
void main()
{
    int ch1;
    char ch2;
    clrscr();
    do
    {
      cout<<"1.  Enqueue \n";
      cout<<"2.  Dequeue\n";
      cout<<"3.  Display\n";
      cout<<"4.  Exit \n";
      cout<<"    Enter your choice: ";
      cin>>ch1;
      switch(ch1)
      {
        case 1: obj.enqueue();
		           break;
	      case 2: obj.dequeue();
		           break;

         case 3: obj.display();
                  break;
        case 4 : exit(0);
                  break;
      }
      cout<<"\n Do you want to operate more????(y/n): ";
      cin>>ch2;
    } while(ch2=='y'||ch2=='Y');
      getch();
}

