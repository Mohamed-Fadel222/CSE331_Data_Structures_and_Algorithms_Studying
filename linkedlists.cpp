class node
{
    public:
    int list;
    node *next;
};
class linkedlist
{

   public:
   node* Head; 
   linkedlist(){
    Head=NULL;
   }
   bool isempty(){

    return(Head==NULL);
   }  
   void InsertFrst(int newvalue)
   {

    if (isempty())
        node*newnode;
        newvalue->data=newvalue;
    {
        
        newnode->next=NULL;
        Head = newnode;
    }
    else{
        newnode->data=newvalue;
        newnode->next=Head;
        Head= newnode;
    }
   }
   void Display(){
    node*temp=Head;
    temp=temp.next;


   }
};