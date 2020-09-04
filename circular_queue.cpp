//Perform circular queues using Arrays implementation

#include<iostream.h>
#include<conio.h>
#define Size 10



class circular_queue
{
	int queue[Size];

 public:

     int ele;
     int front,rear;

     circular_queue()
     {
     	front=rear=-1;
     }

     int enqueue(int);
     void dequeue();
     void display();
     int isempty()
     {
        return(front==-1);


     }
     int isfull()
     {
        return((front==0&&rear==Size-1)||(front==rear+1));


     }
}obj;
int circular_queue::enqueue(int ele)
{
  if(isfull())
  {
    cout<<"Queue is full:overflow\n";

  }
  else
    if(front==-1)
    {
      front=0;
      rear=0;
    }
    else
      if(rear==Size-1)
      {
       rear=0;
       }
       else
        rear=rear+1;
 queue[rear]=ele;
 return 0;
}


void circular_queue::dequeue()
{
 if(isempty())
 {
  cout<<"underflow: Queue is empty\n";
  }
  else
  {
    cout<<"the deleted element is : "<<queue[front]<<endl;
   if(front==rear)
     front=rear=-1;

     else
       if(front==Size-1)
          front=0;
          else
             front++;
   }
}


void circular_queue::display()

  {
        int f = front, r = rear;
            if (isempty())
            {
                cout<<"Queue is empty\n";

            }
            else
            {
            cout<<"Queue elements :\n";
            if (f <= r)
            {
                while (f<= r)
                {
                    cout<<queue[f]<<"  ";
                    f++;
                }
            }
            else
            {
                while (f <= Size-1)
                {
                    cout<<queue[f]<<"  ";
                    f++;
                }
                f= 0;
                while (f<= r)
                {
                    cout<<queue[f]<<"  ";
                    f++;
                }
            }
            cout<<endl;
  }          }

   int main()
    {

   int ch, ele;
   cout<<"1)Enqueue\n";
   cout<<"2)Dequeue\n";
   cout<<"3)Display\n";
   cout<<"4)Exit\n";
   do {
      cout<<"Enter choice : "<<endl;
      cin>>ch;
      switch(ch)
       {
         case 1:
                  cout<<"Input for insertion: "<<endl;
                   cin>>ele;
                   obj.enqueue(ele);
                    break;

         case 2:
                obj.dequeue();
                break;

         case 3:
                 obj.display();
                  break;

         case 4:
                 cout<<"Exit\n";
                  break;
         default: cout<<"Wrong choice!!!!!!!!\n";
      }
   } while(ch != 4);
   return 0;
}

