/*3. Given a list of N elements, which is sorted in ascending order, you are required to search an element x
in the list. The list is stored using array data structure. If the search is successful, the output should be
the index at which the element occurs, otherwise returns -1 to indicate that the element is not present
in the list. Assume that the elements of the list are all distinct. Write a program to perform the desired
task.*/
#include<iostream>
#include<stdio>
#include<conio.h>
int binarySearch(int a[],int beg,int last,int el)
{
	if(last>=1)
	{
		int mid=(beg+(last-1))/2;
		if(el==a[mid])
		{
			return mid;
		}
		else if(el<a[mid])
		{
			return binarySearch(a,beg,mid-1,el);
		}
		else
		{
			return binarySearch(a,mid+1,last,el);
		}
	}
	return -1;
}

int main()
{
	int ch,arr[20],n,el,res;
      cout<<"\n Enter the size of Array : ";
	    cin>>n;
	    cout<<"\n Enter the elements of array : \n";
	    for(int i=0;i<n;i++)
	    {
	   	cin>>arr[i];
		}

       cout<<"\n Enter the element to be searched : ";
				cin>>el;
			    res=binarySearch(arr,0,n-1,el);
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


