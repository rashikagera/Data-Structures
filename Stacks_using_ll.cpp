// Perform the following Stack operations using Linked List implementation.

//a)	Push
//b)	Pop
//c)	Clear

#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#define Null 0
class stacks
{
  struct node
  {
    int data;
    struct node*next;
  }*ptr,*temp,*top;

  public:
   stacks()
   {
     top=Null;
    }


    void push();
    void pop();
    void clear();
    void display();

}obj;
void stacks::push()
{
  int ele;
  ptr=new node;
  cout<<"Enter the number to be pushed: ";
  cin>>ele;
  ptr->data=ele;
  if(top==Null)
  {
    ptr->next=Null;
    top=ptr;
   }
   else
   {
    ptr->next=top;
    top=ptr;
    }

}

void stacks::pop()
{

  if(top==Null)
  {
   cout<<"Stack is emmpty..Underflow comdition";

   }
   else
   {
     temp=top;

     cout<<"The deleted element is"<<top->data;
     top=top->next;
     temp->next=Null;
    }

}



void stacks::clear()
 {
	node *ptr1 = top;

	while(ptr1!= NULL)
	{
		cout<<ptr1->data<<"->";
            node *temp = ptr1->next;
            delete ptr1;
            ptr1 = temp;

	}
        cout<<"NULL\n";
 }
void stacks::display()
{
 if(top==Null)
   cout<<"Stack is empty";
  else
  {
   temp=top;
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
      cout<<"1.  Push \n";
      cout<<"2.  Pop\n";
      cout<<"3.  Clear \n";
      cout<<"4.  Display\n";
      cout<<"5.  Exit \n";
      cout<<"    Enter your choice: ";
      cin>>ch1;
      switch(ch1)
      {
        case 1: obj.push();
		           break;
	      case 2: obj.pop();
		           break;
        case 3:  obj.clear();
                 break;
         case 4: obj.display();
                  break;
        case 5 : exit(0);
                  break;
      }
      cout<<"\n Do you want to operate more????(y/n): ";
      cin>>ch2;
    } while(ch2=='y'||ch2=='Y');
      getch();
}


