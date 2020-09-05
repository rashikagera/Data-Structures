//perform circular queues using linklist implenentation
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#define Null 0
class cir_queue
{
  struct node
  {
    int data;
    struct node*next;
  }*ptr,*temp,*front,*rear;

  public:
   cir_queue()
   {
     front=Null;
     rear=Null;
    }


    void enqueue();
    void dequeue();
    void display();



}obj;
void cir_queue::enqueue()
{
  int ele;
  ptr=new node;
  cout<<"Enter the number to be inserted in the queue ";
  cin>>ele;
  ptr->data=ele;
  ptr->next=Null;

    if(rear==Null)
  {
    front=rear=ptr;
    rear->next=front;
   }
   else
   {
     rear->next=ptr;
     rear=ptr;
     rear->next=front;
    }

}

void cir_queue::dequeue()
{
    temp=front;
  if(front==Null)
  {
   cout<<"Queue is emmpty..Underflow comdition";

   }
   else
     if(front==rear)
     {
       front=rear=Null;
       delete temp;

     }
      else
          {
            front=front->next;
            rear->next=front;
            delete temp;
           }


}






void cir_queue::display()
{
  temp=front;
 if(front==Null)
   cout<<"Queue is empty";
  else
  {

   while(temp->next!=front)
   {
    cout<<temp->data<<"->";
    temp=temp->next;
    }
    cout<<temp->data;
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
