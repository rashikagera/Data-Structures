/*2. Given a list of N elements, which follows no particular arrangement, you are required to search an
element x in the list. The list is stored using array data structure. If the search is successful, the output
should be the index at which the element occurs, otherwise returns -1 to indicate that the element is
not present in the list. Assume that the elements of the list are all distinct. Write a program to perform
the desired task.*/

#include<iostream>
#include<stdio.h>
#include<conio.h>
int Search(int a[],int n,int el)
{
	if(n>0)
	{
		Search(a,n-1,el);
	    if(el==a[n-1])
	        return n-1;
    }
	return -1;
}
int main()
{

	int arr[20],n,el,res;
   cout<<"\n Enter the size of Array : ";
   cin>>n;
   cout<<"\n Enter the elements of array : \n";
   for(int i=0;i<n;i++)
   {
		cin>>arr[i];
   }



    cout<<"\n Enter the element to be searched : ";
				cin>>el;
			    res=Search(arr,n,el);
				if(res==-1)
				{
					cout<<"\n Element not found !!!";
				}
				else
				{
					cout<<"\n Element found at index position : "<<res;
				}
   getch();

}