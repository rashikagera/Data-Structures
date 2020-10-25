 //AVL TREE
#include<iostream>
#include<stdio>
#include<algorithm>
using namespace std;


struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root;


class avlTree
{
    public:
        int height(node *);
        int difference(node *);
        node *rr_rotation(node *);
        node *ll_rotation(node *);
        node *lr_rotation(node *);
        node *rl_rotation(node *);
        node *balance(node *);
        node *insert(node *, int);
       node *deleted(node *, int);
        void display(node *, int);
        avlTree()
        {
            root = NULL;
        }
};


int main()
{
    int ch, item;
    avlTree avl;
    while (1)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"AVL Tree Implementation"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.Display Balanced AVL Tree"<<endl;
        cout<<"3.Deletion"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            cin>>item;
            root = avl.insert(root, item);
            break;
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Balanced AVL Tree:"<<endl;
            avl.display(root, 1);
            break;
         case 3:
                cout<<"Enter the value to be deleted";
                cin>>item;
                root=avl.deleted(root, item);
                 break;

        case 4:
            exit(1);
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}


// Height of AVL Tree
int avlTree::height(node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

// Height Difference that is balancing factor
int avlTree::difference(node *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}

//RR rotation
node *avlTree::rr_rotation(node *parent)
{
    node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
//LL rotation
node *avlTree::ll_rotation(node *parent)
{
    node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

//LR rotation
node *avlTree::lr_rotation(node *parent)
{
    node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}

//RR rotation
node *avlTree::rl_rotation(node *parent)
{
    node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}


//Balancing AVL Tree

node *avlTree::balance(node *temp)
{
    int bal_factor = difference(temp);
    if (bal_factor > 1)
    {
        if (difference (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (difference(temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}


// Insertion

node *avlTree::insert(node *root, int value)
{
    if (root == NULL)
    {
        root = new node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}


//  Display AVL Tree

void avlTree::display(node *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}


//Deletion
node *avlTree::deleted(node * root, int value)
  {
    node *p;
    if(root==NULL)
    {
      return NULL;
    }
     else
       if(value>root->data)
       {

         root->right=deleted(root->right,value);
         root=balance(root);
        }

     else

        if(value < root->data)
        {
          root->left=deleted(root->left,value);
          root=balance(root);



         }
     else

     {
       if(root->right!=NULL)
				{
					p=root->right;

					while(p->left!= NULL)
						p=p->left;

					root->data=p->data;
					root->right=deleted(root->right,p->data);


				}
				else
					return(root->left);



     }
     return root;
     }
