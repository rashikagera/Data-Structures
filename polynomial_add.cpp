//13.	WAP to add two polynomials using linked list representation.
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>

class polynomial
{
	public:
   struct node
		{
			public:
				int coeff;
				int pow;
				node *next;
		}*first,*last,*temp,*temp1;

		void insert(int,int);
		void display();
		void sum(polynomial);
		polynomial()
		{
			first=last=NULL;
		}
};

void polynomial::display()
{
	temp=first;
	while(temp!=NULL)
	{

		if(temp->coeff>0)
		{
		    if(temp->coeff==0)
		    {
			 temp=temp->next;
			}

			if(temp->pow==0)
			{
				cout<<'+'<<temp->coeff;
			}
			else if(temp->pow==1)
			{
				cout<<'+'<<temp->coeff<<"x";
			}
		    else
		    {
			cout<<'+'<<temp->coeff<<"x^"<<temp->pow;
			}

		}
		else
		{
			if(temp->coeff==0)
			{
				temp=temp->next;
			}
			if(temp->pow==0)
			{
				cout<<temp->coeff;
			}
			else if(temp->pow==1)
			{
				cout<<temp->coeff<<"x";
			}
			else
			{
				cout<<temp->coeff<<"x^"<<temp->pow;
			}
		}
		temp=temp->next;
	}
}

void polynomial::sum(polynomial ob1)
{
	int flag;
	ob1.temp1=ob1.first;
	while(ob1.temp1)
	{
		temp1=first;
		while(temp1)
		{
			if(temp1->pow == ob1.temp1->pow)
		    {
			temp1->coeff = temp1->coeff+ob1.temp1->coeff;
			flag=1;
			break;
		    }
		    else
		    {
			flag=0;
			}
			temp1=temp1->next;
		}
		if(flag==0)
		{
			insert(ob1.temp1->pow,ob1.temp1->coeff);
		}
		ob1.temp1=ob1.temp1->next;
	}
	cout<<"\n\n SUM : ";
	display();
}

void polynomial::insert(int p,int c)
{
	temp=new node;
	temp->next=NULL;
	temp->pow=p;
	temp->coeff=c;
	if(first==NULL)
	    first=last=temp;
	else
	{
	    last->next=temp;
		last=temp;
	}
}

int main()
{
	polynomial obj1,obj2;
	int a,b;
	char ch;
	cout<<"\n  First Polynomial  ";
	do
	{
		cout<<"\n Enter the power : ";
		cin>>a;
		cout<<"\n Enter the coefficient : ";
		cin>>b;
		obj1.insert(a,b);
		cout<<"\n Want to add more (y/n) : ";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	obj1.display();
	cout<<"\n\n";
	cout<<"\n Second Polynomial  ";
		do
	{
		cout<<"\n Enter the power : ";
		cin>>a;
		cout<<"\n Enter the coefficient : ";
		cin>>b;
		obj2.insert(a,b);
		cout<<"\n Want to add more (y/n) : ";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	obj2.display();
	cout<<"\n\n";
	obj1.sum(obj2);
	return 0;
   getche();
}