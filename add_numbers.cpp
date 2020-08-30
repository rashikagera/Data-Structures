//	WAP to add two large integers using stack.
#include<iostream.h>
#include<stdio.h>
#include<process.h>
#include<conio.h>


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
        cout<<"\nStack is full";
      else
          arr[++top] = a;
     }

     x pop()
     {
      if(top!=-1)
        return arr[top--];
     }

     void clear()
     {
         while(top!=-1)
         {
          cout<<arr[top--];
         }


     }
};



int main()
{
    Stack <int>s1,s2,s3;
    int temp;
    int sum,n;
    sum = 0, temp = 0;

    cout<<"\nEnter the first number digit by digit & type -1 when finished : ";
    for (int i = 0; n != -1; ++i)
    {
      cin>>n;
      if (n != -1)
      {
         s1.push(n);
      }
    }
    n=0;
    cout<<"\nEnter the second number digit by digit & type-1 when finished : ";
    for (int i = 0; n != -1; ++i)
    {
       cin>>n;
       if (n != -1)
       {
          s2.push(n);
       }
    }
    temp = 0;
    while(s1.top!=-1 && s2.top!=-1)
    {
       temp = temp+s1.pop()+s2.pop();
       s3.push(temp%10);
       temp=temp/10;
    }

     if (s1.top!=-1)
    {
      while(s1.top!=-1)
      {
        s3.push(temp+s1.pop());
        temp=0;
      }
    }
    if (s2.top!=-1)
    {
      while(s2.top!=-1)
      {
        s3.push(temp+s2.pop());
        temp=0;
      }
    }
    if (temp!=0)
    {
      s3.push(temp);
    }



    cout<<"\nThe Result is : ";
    s3.clear();


  getch();
}