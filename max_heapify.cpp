#include<iostream.h>
#include<conio.h>
void main()
{
  int n,i;
  cout<<"Enter the number of elements in the aray";
  cin>>n;
  int A[30];
  for(i=1;i<n;i++)
  {
    cout<<"Enter elements"<<" "<<i<<endl;
    cin>>A[i];
  }
  void Max_heapify(int A[],int n,int i)
  {
    int l=2*i;
    int r=2*i+1;
    int largest,temp;
    if(l<=n && A[l]>A[i])
      largest=l;
    if(r<=n && A[r]>A[largest])
       largest=r;
    if(largest != i)
    {
      //swap(A[i],A[largest]);
      temp=A[i];
      A[i]=A[largest];
      A[largest]=temp;
      Max_heapify(A,n,largest);
     }
  }
  void build_max_heap(int A[],int n)
  {
    int k=(n/2)-1;
    for(int i=k;i>=0,i--)
      Max_heapify(A,n,i);
   }

   void display(int A[],int n)
   {
     cout<<"Array representation of heap is: \n";
     for(i=0;i<n;i++)
         {
         cout<<A[i]<<" ";
       cout<<"\n";
       }
    }
}


