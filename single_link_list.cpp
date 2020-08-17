                                                                                                                                                                                                                                                                                    #include<conio.h>
#include<iostream.h>
#include<process.h>
#include<conio.h>
#define Null 0
class linklist
{
  struct node
  {
    int data;
    struct node *next;
  }*head,*first,*last,*temp;

  public:
  linklist()
  {
    head=Null;
    last=Null;

  }
  ~linklist()
  {
  }
  void create();
  void display();
  void insert_at_beg();
  void insert_at_end();
  void insert_at_pos();
  void delete_at_beg();
  void delete_at_end();
  void delete_at_pos();
  void search();
  void reverse();
  void count();

}obj;
void main()
{
    int ch1;
    char ch2;
    clrscr();
    do
    {
      cout<<"1. Create a linklist \n";
      cout<<"2. Display link list \n";
      cout<<"3. Insert at beginning \n";
      cout<<"4. Insert at end \n";
      cout<<"5. Insert at a specific position \n";
      cout<<"6  Delete at beginning \n";
      cout<<"7. Delete at end \n";
      cout<<"8. Delete from a specific position \n";
      cout<<"9. Search for an element \n";
      cout<<"10.Reverse a linklist \n";
      cout<<"11.Count the no. of nodes \n";
      cout<<"12.  Exit \n";
      cout<<"    Enter your choice: ";
      cin>>ch1;
      switch(ch1)
      {
        case 1: obj.create();
		           break;
	      case 2:  obj.display();
		           break;
        case 3: obj.insert_at_beg();
                  break;
        case 4: obj.insert_at_end();
                 break;
        case 5: obj.insert_at_pos();
                   break;
        case 6: obj.delete_at_beg();
                  break;
         case 7: obj.delete_at_end();
                 break;
          case 8: obj.delete_at_pos();
                 break;
         case 9: obj.search();
                  break;
          case 10: obj.reverse();
                  break;
          case 11: obj.count();
                  break;
       	case 12 : exit(0);
      }
      cout<<"\n Do you want to operate more????(y/n): ";
      cin>>ch2;
      } while(ch2=='y'||ch2=='Y');
      getch();
 }
 void linklist::create()
 {
    char ch='y' ;
    do{
    first=new node;
    cout<<"Enter the data item in the node: ";
    cin>>first->data;
    first->next=Null;
     if(head==Null)
    {
       head=first;
       last=first;
     }
      else{
	   last->next=first;
	   last=first;
	}
       cout<<"Do you want to insert more nodes(y/n) :  ";
       cin>>ch;
       }while(ch=='y');
       last=head;
      }

     void linklist::insert_at_beg()
     {

       temp= new node;

       cout<<"Enter the data item in the node";
       cin>>temp->data;

       temp->next=head;
       head=temp;

      display();

     }
     void linklist::insert_at_end()
     {
        temp= new node;
        cout<<"Enter the data item in the node";
        cin>>temp->data;

        last->next=temp;
        temp->next=Null;
        last=temp;

        display();
       }


       void linklist::insert_at_pos()
       {
         temp= new node;
         struct node *temp1= new node;
         int pos;
         cout<<"Enter the data item in the node";
         cin>>temp1->data;
          cout<<"enter the position";
         cin>>pos;
         temp=head;
         for(int i=0;i<pos-1;i++)
            temp=temp->next;

            temp1->next=temp->next;
            temp->next=temp1;

         display();
        }


        void linklist::delete_at_beg()
        {
         temp=new node;
          temp=head;
          head=head->next;
           delete temp;
          display();
         }


          void linklist::delete_at_end()
          {
             temp=new node;
            temp=head;
            while(temp->next!=last)
            {
              temp=temp->next;
             }
             temp->next=Null;
             last=temp;
             display();
          }

          void linklist::delete_at_pos()
          {
             temp= new node;


            int pos;
            cout<<"Enter the position";
            cin>>pos;
            for(int i=0;i<pos-1;pos++)
            temp=temp->next;
             temp->next=temp->next->next;

             display();
            }



        void linklist::search()
     {
       int value,pos=0;
        bool flag=false;
    if(head==NULL)
    {
        cout<<"List is Empty";
        return;
    }
    cout<<"Enter the Value to be Searched:";
    cin>>value;
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        pos++;
        if(temp->data==value)
        {
            flag=true;
            cout<<"Element"<<value<<"is Found at : "<<pos<<" Position";
            return;
        }
        temp=temp->next;
    }
    if(!flag)
    {
        cout<<"Element "<<value<<" not Found in the List";
    }
}


   void linklist::reverse()
   {
     struct node *current,*prev=Null ,*next;
     current=head;
     while(current!=Null)
     {
       next=current->next;
       current->next=prev;
       prev=current;
       current=next;
      }
     head=prev;
     display();
     }

      void linklist::count()
      {
        int count=0;
        temp=head;
        while(temp!=Null)
        {
         count++;
         temp=temp->next;
         }
        cout<<" The no.of nodes are : "<<count;
      }



     void linklist::display()
     {

      struct node *temp=head;
     if(temp==Null)
     {
	  cout<<"List is empty";
     }
     else
     {
       cout<<"Elements of the list are: \n";
       while(temp!=Null)
      {
          cout<<temp->data;
          cout<<"-->";
          temp=temp->next;
      }
     }
   }
