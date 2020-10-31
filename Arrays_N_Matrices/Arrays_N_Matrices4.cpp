//Symmetric Matrix
#include<iostream.h>
#include<conio.h>
#include<process.h>


class symmetric
{
	int *d;
	int n,k;
public:
	 symmetric(int size=10)
	 {
		 n=size;
		 if(size!=0)
		 {
			d=new int[n*(n+1)/2];
		 }
		 else
			d=0;
	 }
	 ~symmetric()
	 {
		delete []d;
	 }
	 void store(int x,int i,int j);
	 int retrieve(int i,int j);
	 void show();


   };

void symmetric::store(int x,int i,int j)
{
	if(i<1||i>n||j<1||j>n)
	{
		cout<<"\nOut of bound";
		exit(0);
	}
	else if(i<j&&x!=0)
		cout<<"\nMust be zero";
	else if(i>=j)
	{
        k= i*(i-1)/2+j-1;
		d[k+1]=x;
	}
}

int symmetric::retrieve(int i,int j)
{
	 if(i<1||i>n||j<1||j>n)
		cout<<"\nOut of bound";
	 else if(i==j)
		return d[i*(i-1)/2+j];
	 else if(i>j)
		return d[i*(i-1)/2+j];
	 else if(j>i)
		return d[j*(j-1)/2+i];
}
void symmetric::show()
{
	cout<<"\nSparse matrix : ";
	for (int i = 1; i <= n*(n+1)/2; ++i)
	{
		cout<<d[i]<<"";
	}

    cout<<"\nComplete matrix :\n";
	for(int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
		{
			if(i==j)
				cout<<d[i*(i-1)/2+j]<<"";
			else if(i>j)
			    cout<<d[i*(i-1)/2+j]<<"";
			else if(j>i)
			  cout<<d[j*(j-1)/2+i]<<"";
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
	symmetric ob(m1);


	cout<<"\nEnter the elements of array : \n";
	for (i = 1; i <= m1; ++i)
	{
		for (j = 1; j <= m2; ++j)
		{
			if(i>=j)
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
