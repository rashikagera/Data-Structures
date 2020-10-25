/*1. Write a program, using templates, to sort a list of n elements. Give user the option to perform sorting
using Insertion sort, Bubble sort or Selection sort.*/
#include<iostream.h>
#include<stdio.h>
#include<process.h>

template <class x>
class sorting
{

  public:

   void bubble(int arr[],int n);
   void selection(int arr[],int n);
   void insertion(int arr[],int n);
   void display(int arr[],int n);

  } ;

template <class x>
    void sorting<x>:: bubble(int arr[],int n)
{
	if(n==1)
	   return;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			int temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
		}
	}
	bubble(arr,n-1);
}

template <class x>
void sorting<x>::selection(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			    min=j;
		}
		int temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
}

template <class x>
void sorting<x>::insertion(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		int val=arr[i];
		int j=i;
		while(j>0 && arr[j-1]>val)
		{
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=val;
	}
}


template <class x>
void sorting<x>::display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<" "<<arr[i];
	}
}

int main()
{
	int ch,n;
   int arr[30];
  sorting<int> obj;
	do
	{
		cout<<"\n ---------------------MAIN MENU-------------------";
	    cout<<"\n 1. Bubble Sort";
	    cout<<"\n 2. Selection Sort";
	    cout<<"\n 3. Insertion Sort";

       cout<<"\n Enter your choice( 0 to Exit ) : ";
	    cin>>ch;
	    if(ch==0)
	    {
		exit(1);
		}
      cout<<"\n Enter the size of Array : ";
	    cin>>n;
	    cout<<"\n Enter the elements of array : \n";
	    for(int i=0;i<n;i++)
	    {
		cin>>arr[i];
		}

	     switch(ch)
	    {
		case 1:
			cout<<"\n Array Before sorting : ";
			obj.display(arr,n);
			obj.bubble(arr,n);
			cout<<"\n Array After sorting : ";
			obj.display(arr,n);
			break;
		case 2:
			cout<<"\n Array Before sorting : ";
			obj.display(arr,n);
         obj.selection(arr,n);
			    cout<<"\n Array After sorting : ";
         obj.display(arr,n);
				break;
			case 3:
				cout<<"\n Array Before sorting : ";
		  obj.display(arr,n);
        obj.insertion(arr,n);
			    cout<<"\n Array After sorting : ";
        obj.display(arr,n);
				break;

}
	}while(ch!=0);
	 return 0;
}
