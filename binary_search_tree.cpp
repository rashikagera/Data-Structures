#include<iostream>
#include<stdio.h>
#include<process.h>


class node
{
	public:
		int data;
		node *left;
		node *right;
};
class Queue
{
	node* a[30];
	public:
		int first,last;
		Queue()
		{
			first=last=-1;
		}
		~Queue()
		{  }
		void enqueue(node *t)
		{
			if(first==-1)
			{
				first=last=0;
				a[last++]=t;
			}
			else if(last==29)
			{
				cout<<"\n Queue full !!!";
				exit(1);
			}
			else
			{
				a[last++]=t;
			}
		}

		node* dequeue()
		{
			if(first==-1)
			{
				cout<<"\n Queue Empty !!!";
			}
			node *k;
			if(first==last)
			{
				k=a[first];
				first=last=-1;
			}
			else
			{
				k=a[first++];
			}
			return k;
		}
};

class BST
{
	public:
		node *temp,*temp1,*temp2,*root;
		int leaf,nonLeaf;
		BST()
		{
			leaf=nonLeaf=0;
         root=NULL;
		}
      void insert();

      void search(int);

		void rec_preorder(node *);
		void rec_postorder(node *);
      void rec_inorder(node *);
      void bfs_treversal(node *);
      void mirrorImage(node *);
      void leaf_nonLeaf(node *);
      int height(node *);


};
void BST::insert()
{
	int i;
	cout<<"\n Enter the node value ( 0 to exit ) : ";
	cin>>i;
	while(i!=0)
	{
		temp=new node;
		temp->data=i;
		temp->left=temp->right=NULL;

		if(root==NULL)
		{
			root=temp;
		}
		else
		{
			temp1=root;
			while(temp1!=NULL)
			{
				if(i<temp1->data)
				{
					temp2=temp1;
					temp1=temp1->left;
				}
				else
				{
					temp2=temp1;
					temp1=temp1->right;
				}
			}
			if(i<temp2->data)
			{
				temp2->left=temp;
			}
			else
			{
				temp2->right=temp;
			}
		}
		cout<<"\n Enter the node value ( 0 to exit ) : ";
	    cin>>i;
	}
}

void BST::rec_postorder(node *t)
{
	if(t!=NULL)
	{
		rec_postorder(t->left);
		rec_postorder(t->right);
		cout<<""<<t->data<<",";
	}
}

void BST::rec_preorder(node *t)
{
	if(t!=NULL)
	{
		cout<<""<<t->data<<",";
		rec_preorder(t->left);
		rec_preorder(t->right);
	}
}

void BST::rec_inorder(node *t)
{
	if(t!=NULL)
	{
		rec_inorder(t->left);
		cout<<""<<t->data<<",";
		rec_inorder(t->right);
	}
}

void BST::bfs_treversal(node *t)
{
	Queue q;
	if(t!=NULL)
	{
		q.enqueue(t);
		while(q.first!=-1)
		{
			t=q.dequeue();
			cout<<""<<t->data;
			if(t->left!=NULL)
			    q.enqueue(t->left);
			if(t->right!=NULL)
			    q.enqueue(t->right);
		}
	}
}

void BST::leaf_nonLeaf(node *t)
{
	if(t!=NULL)
	{
		if(t->left==0 && t->right==0)
		    leaf++;
		else
		    nonLeaf++;
		leaf_nonLeaf(t->left);
		leaf_nonLeaf(t->right);
	}
}

void BST::search(int el)
{
	int flag=0;
	temp=root;
	while(temp)
	{
		if(el==temp->data)
		{
			flag=1;
			break;
		}
		else if(el<temp->data)
		{
			temp=temp->left;
		}
		else
		{
			temp=temp->right;
		}
	}
	if(flag==1)
	{
		cout<<"\n Element found !";
	}
	else
	{
		cout<<"\n Element not found !!!";
	}
}


int BST::height(node *t)
{
	if(t==NULL)
	    return 0;
	int lheight=height(t->left);
	int rheight=height(t->right);
	if(lheight>rheight)
	    return lheight+1;
	else
	    return rheight+1;
}

void BST::mirrorImage(node *t)
{
	if(t==NULL)
	    return;
	else
	{
		mirrorImage(t->left);
		mirrorImage(t->right);

		temp=t->left;
		t->left=t->right;
		t->right=temp;
	}
}



int main()
{
	BST ob;
	int ch,el;
	do
	{
		cout<<"\n -------------MAIN MENU---------------";
		cout<<"\n 1. Insertion";
		cout<<"\n 2. Search";
		cout<<"\n 3. Inorder, preorder and postorder (recursive) ";
	  	cout<<"\n 4. Inorder, preorder and postorder (iterative)";
		cout<<"\n 5. bfs Treversal";
		cout<<"\n 6. Mirror Image";
		cout<<"\n 7. Count the Leaf, Non-Leaf nodes ";
      cout<<"\n 9. Height";
      cout<<"\n Enter your choice ( 0 to exit ) : ";
      cin>>ch;

		switch(ch)
		{
			case 1:
				ob.insert();
				break;
         case 2:
			    cout<<"\n Enter the key to be searched : ";
				cin>>el;
				ob.search(el);
				break;
			case 3:
            cout<<"\n Inorder :";
				ob.rec_inorder(ob.root);
				cout<<"\n Preorder :";
				ob.rec_preorder(ob.root);
				cout<<"\n Postorder :";
				ob.rec_postorder(ob.root);
				break;
         case 5:
			    cout<<"\n BFS Treversal :";
			    ob.bfs_treversal(ob.root);
			    break;
         case 6:
			    ob.mirrorImage(ob.root);

				cout<<"\n Tree Inverted Successfully !";
             ob.rec_inorder(ob.root);
				break;
         case 7:
			    ob.leaf_nonLeaf(ob.root);
				cout<<"\n LEAF : "<<ob.leaf;
				cout<<"\n NON-LEAF : "<<ob.nonLeaf;
				break;
        case 9:
			    el=ob.height(ob.root);
				cout<<"\n Height : "<<el;
				break;




			default :
			    break;
		}
	}while(ch!=0);
return 0;
}




