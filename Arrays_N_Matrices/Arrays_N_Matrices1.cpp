// Diagonal Matrix
#include<iostream.h>
#include<process.h>
#include<conio.h>


class diagonal
{
	int *d;
	int n;
public:
	 diagonal(int size=10)
	 {
		 n=size;
		 if(size!=0)
		 {
			d=new int[n];
		 }
		 else
			d=0;
	 }
	 ~diagonal()
	 {
		delete []d;
	 }
	 void store(int x,int i,int j);
	 int retrieve(int i,int j);
	 void show();


   };

void diagonal::store(int x,int i,int j)
{
	if(i<1||i>n||j<1||j>n)
	{
		cout<<"\nOut of bound";
		exit(0);
	}
	else if(i!=j&&x!=0)
		cout<<"\nMust be zero";
	else if(i==j)
		d[i]=x;
}

int diagonal::retrieve(int i,int j)
{
	 if(i<1||i>n||j<1||j>n)
	 {
		cout<<"\nOut of bound";
	 }
	 else if (i==j)
		return d[i];
	 else
		return 0;
}
void diagonal::show()
{
	cout<<"\nSparse matrix : ";
	for (int i = 1; i <= n; ++i)
	{
		cout<<d[i]<<"";
	}

    cout<<"\nComplete matrix :\n";
	for(int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
		{
			if (i!=j)
			    cout<<"0"<<"";
			else
				cout<<d[i]<<"";
		}
		cout<<"\n";
	}

}



int main()
{

	int m1=0,m2=0,y=0,i=0,j=0;
	cout<<"\nEnter the size of diagonal matrix : \n";
	cin>>m1>>m2;
	if(m1!=m2)
	{
		cout<<"\nInvalid size";
		exit(0);
	}
	diagonal ob(m1);
	cout<<"\nEnter the elements of array : \n";
	for (i = 1,j = 1; i <= m1,j <= m2; ++i,++j)
	{
		cin>>y;
	    ob.store(y,i,j);
	}
	cout<<"\nMatrix is : \n";
    ob.show();
    cout<<"\nEnter the location of retrieval : \n";
    cin>>i>>j;
    cout<<"Retrieved value is : "<<ob.retrieve(i,j)<<"\n";

   getch();

}
