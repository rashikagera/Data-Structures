// Perform the following Stack operations using Array implementation using Templates:

//a)	Push
//b)	Pop
//c)	Clear

#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>

#define Size 10

template <class x>

class Stack
{
	x arr[Size];

 public:

     x ele,r;
     int top;

     Stack()
     {
     	top=-1;
     }

     void push(x a)
     {
	     if(top==Size)
        cout<<"Stack is full";
	else
	    arr[++top] = a;
     }

     x pop()
     {
	     if(top==-1)
       {
		  cout<<"\nStack is empty";

    	}
	else
		return arr[top--];
     }

     void clear()
     {
         while(top!=-1)
         {
         	cout<<arr[top--]<<"->";
         }
          cout<<"NULL\n";


     }
     void display()
     {
       if(top!=-1)
       {
          for(int i=top;i>=0;i--)
           {
             cout<<arr[i]<<"->";
           }
       }
       else
       cout<<"Stack is empty";
     }
};


int main()
{
    Stack <int>s;
    int ch;
    while(1)
    {
   	cout<<"\n1.PUSH\n2.POP\n3.CLEAR\n4.DISPLAY\n5.EXIT\n";
      cout<<"Enter your choice: ";
      cin>>ch;
   	switch(ch)
   	{
          case 1:
                  cout<<"\nEnter the value to be pushed : ";
                  cin>>s.ele;
                  s.push(s.ele);
                  break;
          case 2:
                  s.r = s.pop();
                  cout<<"\nValue popped out is : "<<s.r;
                  break;
          case 3: s.clear();
                  break;
          case 4: s.display();
                  break;
          case 5: exit(0);
          default:
                  cout<<"\nEnter a valid choice";
	  }
    }
	return 0;
   getch();
}
