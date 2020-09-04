//	Perform the following Queue operations using Circular Array implementation (Use Templates):

//a)	Enqueue
//b)	Dequeue


#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>

#define Size 10

template <class x>

class queue
{
	x queue[Size];

 public:

     x ele;
     int front,rear;

     queue()
     {
     	front=rear=-1;
     }

     void enqueue()
     {
	     if(rear==Size-1)
        cout<<"Overflow: Queue is full";
	else
   {
     cout<<"Enter the element" ;
     cin>>ele;
     if(front==-1)
     {
      front=0;
     }
	    rear++;
       queue[rear]=ele;
   }

     }

     void dequeue()
     {
	    if(rear==-1||front>rear)
       {
		  cout<<"\n Underflow condition :Queue is empty";
       }
	else
		ele=queue[front];
      cout<<"The deleted element is: "<<ele;
      front++ ;
     }


     void display()
     {
      if(rear==-1||front>rear)
       cout<<"Empty queue";
       else
       {
          for(int i=front;i<=rear;i++)
           {
             cout<<queue[i]<<"->";
           }
       }

     }
};


int main()
{
    queue <int>q;
    int ch;
    while(1)
    {
   	cout<<"\n1.Enqueue\n2.Dequeue\n3.DISPLAY\n4.EXIT\n";
      cout<<"Enter your choice: ";
      cin>>ch;
   	switch(ch)
   	{
          case 1: q.enqueue();
                  break;


          case 2: q.dequeue();
                  break;

          case 3: q.display();
                  break;
                  
          case 4: exit(0);
          default:
                  cout<<"\nEnter a valid choice";
	  }
    }
	return 0;
   getch();
}