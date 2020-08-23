// ques 14Write a menu driven program to implement the following operations in an ordered linked list:

//a)	Insertion
//b)	Deletion
//c)	Merging

#include<iostream.h>
#include<stdio.h>
#include<conio.h>


class OLL
{
	public:
		class node
		{
			public:
				int data;
				node *next;
		} *first,*last,*temp,*temp1;

		OLL()
		{
			first=last=NULL;
		}
		~OLL()
		{
			temp=first;
			while(first!=NULL)
			{
				temp=temp->next;
				delete first;
				first=temp;
			}
		}
		void insert(int);
		void display();
		void deleteNode(int);
		void merge(OLL);
};

void OLL::insert(int el)
{
	temp=new node;
	temp->data=el;
	temp->next=NULL;
	if(first==NULL)
	{
		first=last=temp;
	}
	else if(temp->data <= first->data)
	{
		temp->next=first;
		first=temp;
	}
	else if(temp->data >= last->data)
	{
		last->next=temp;
		last=temp;
	}
	else
	{
		temp1=first;
		while(temp1!=last)
		{
			if((temp->data > temp1->data) && (temp->data <= temp1->next->data))
			{
				temp->next=temp1->next;
				temp1->next=temp;
			}
			temp1=temp1->next;
		}
	}

}

void OLL::deleteNode(int n)
{
	temp=first;
	if(n==1)
	{
		temp=first;
		first=first->next;
		delete temp;
	}
	else  {
	for(int i=1;i<n-1;i++)
	{
		temp=temp->next;
	}
	temp1=temp->next;  //node to be deleted
	temp->next=temp1->next;
	delete temp1;
	cout<<"\n Node Deleted Successfully";
   }
  display();
}

void OLL::display()
{
	temp=first;
	cout<<"\n LINKED LIST : ";
	while(temp!=NULL)
	{
		cout<<""<<temp->data<<"->";
		temp=temp->next;
	}
}

void OLL::merge(OLL ob)
{
	ob.temp=ob.first;
	while(ob.temp!=NULL)
	{
		insert(ob.temp->data);
		ob.temp=ob.temp->next;
	}
   display();
}

int main()
{
	int ch,el,n,i=1;
	OLL ob1,ob2;

	do
	{
		cout<<"\n -------------MAIN MENU----------------";
	    cout<<"\n 1. insert";
	    cout<<"\n 2. delete";
	    cout<<"\n 3. merge";
       cout<<"\n 4. display";
	    cout<<"\n Enter you choice(0 to exit) : ";
	    cin>>ch;
	    switch(ch)
	    {
		case 1:
			cout<<"\n Enter the element : ";
			cin>>el;
			ob1.insert(el);
			break;
		case 2:
			    cout<<"\n Enter the position from which the node is to be deleted : ";
				cin>>n;
				ob1.deleteNode(n);
				break;
			case 3:
			    cout<<"\n Enter the no. of nodes in the second list : ";
				cin>>n;
				while(n>0)
				{
					cout<<"\n Enter the element no. "<<i<<" : ";
					cin>>el;
					ob2.insert(el);
					i++;
					n--;
				}
				ob1.merge(ob2);
         case 4:ob1.display();
                break;


			default: break;
			    break;
		}
	}while(ch!=0);
	return 0;
   getch();
}
