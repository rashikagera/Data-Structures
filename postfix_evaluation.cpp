// evaluate postfix expression.

#include<iostream.h>
#include<stdio.h>
#include<string>
#include<conio.h>
#include<process.h>


using namespace std;

#define Size 10

template <class x>

class Stack
{
	x arr[Size];

 public:


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


};


int main()
{
    Stack <int>s1;
    int len;
    int n1,n2;
    string str;
    cout<<"\nEnter the postfix expression : ";
     getline(cin,str);
    len=str.length();

    for (int i =0; i <len; ++i)
    {
       switch(str[i])
       {
          case '+':

                   n2 = s1.pop();
                   n1 = s1.pop();
                   s1.push(n2+n1);
                   break;
          case '-':

                   n2 = s1.pop();
                   n1 = s1.pop();
                   s1.push(n2-n1);
                   break;
          case '*':

                   n2 = s1.pop();
                   n1 = s1.pop();
                   s1.push(n2*n1);
                   break;
          case '/':

                   n2 = s1.pop();
                   n1 = s1.pop();
                   s1.push(n2/n1);
                   break;
          default:
                   str[i]=str[i]-'0';
                   s1.push(str[i]);

       }

      } cout<<"\nThe result after solving is : "<<s1.pop()<<"\n";




  getch();
}
