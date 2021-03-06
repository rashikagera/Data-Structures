//Upper Triangular Matrix
#include<iostream>
#include<process.h>
#include<conio.h>


class upper_triangular
{
	int *d;
	int n;
public:
	 upper_triangular(int size=10)
	 {
		 n=size;
		 if(size!=0)
		 {
			d=new int[n*(n+1)/2];
		 }
		 else
			d=0;
	 }
	 ~upper_triangular()
	 {
		delete []d;
	 }
	 void store(int x,int i,int j);
	 int retrieve(int i,int j);
	 void show();


   };

void upper_triangular::store(int x,int i,int j)
{
	int k=0;
	if(i<1||i>n||j<1||j>n)
	{
		cout<<"\nOut of bound";
		exit(0);
	}
	else if(i>j&&x!=0)
		cout<<"\nMust be zero";
	else if(j>=i)
	{
        k= (j*(j-1)/2+i-1);
		d[k]=x;
	}
}

int upper_triangular::retrieve(int i,int j)
{
	int k=0;
	 if(i<1||i>n||j<1||j>n)
	 {
		cout<<"\nOut of bound";
	 }
	 else if (j>=i)
	 {
		k= (j*(j-1)/2+i-1);
		return d[k];
	 }
	 else
		return 0;
}
void upper_triangular::show()
{
	cout<<"\nSparse matrix : ";
	for (int i = 0; i < n*(n+1)/2; ++i)
	{
		cout<<d[i]<<"";
	}

   cout<<"\nComplete matrix :\n";
    int z=1;
	for(int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
		{
			if(i>j)
			  2cout<<"0"<<"";
			else
				cout<<d[j*(j-1)/2+i-1]<<"";
		}
		cout<<"\n";
	}

}



int main()
{

	int m1=0,m2=0,y=0,i=0,j=0;
	cout<<"\nEnter the size of  matrix : \n";
	cin>>m1>>m2;
	if(m1!=m2)
	{
		cout<<"\nInvalid size";
		exit(0);
	}
	upper_triangular ob(m1);


	cout<<"\nEnter the elements of array : \n";
	for (i = 1; i <= m1; ++i)
	{
		for (j = 1; j <= m2; ++j)
		{
			if(j>=i)
			{

				cin>>y;
	            ob.store(y,i,j);
			}
		}
	}
    cout<<"\nMatrix is : \n";
    ob.show();
    cout<<"\nEnter the location of retrieval : \n";
    cin>>i>>j;
    cout<<"Retrieved value is : "<<ob.retrieve(i,j)<<"\n";
  getch();
}

