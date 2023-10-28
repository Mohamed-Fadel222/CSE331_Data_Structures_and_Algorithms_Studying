 #include<iostream>
 using namespace std;
 
 class node
{
    public:
    int data;
    node *Next;
};
 class linkedlist
{
    public:
    node *head;
    linkedlist(){
        head=NULL;
    }

    bool isempty()
    {
        return (head==NULL);
    }

    void insertfirst(int newitem)
    {
        node*newnode;
        newnode->data=newitem;
        if (isempty()){
            
            node *Next=NULL;
            node*head=newnode;
        }
        else {
            node*Next=head;
            node*head=newnode;
        }
       
    }
    void displaylist()
    { 
        node *temp=head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp =temp->Next;
        }
    }

    bool isfound(int key)
    {
        bool found;
        node *temp=head;
        while(temp != NULL){
            if (temp->data==key){
                found =true;
                temp=temp->Next;
            }
            return found;

        }

    }

    int count(){
        int counter=0;
        node *temp=head;
        while(temp != NULL)
        {
            counter++;
            temp=temp->Next;
        }


    }
    void insertbefore(int item,int newvalue){

        node *temp=head;
        while(temp !=NULL&&temp->Next->data != item){
            temp=temp->Next;
        }
            node *newnode;
            newnode->data=newvalue;
            newnode->Next=temp->Next;
            temp->Next=newnode;


    }
   




};

int main(){
linkedlist l;
if (l.isempty())
{
    cout<<"empty list "<<endl;
}
else
cout<<l.count()<<endl;

cout<<"enter item to insert"<<endl;






}
    





